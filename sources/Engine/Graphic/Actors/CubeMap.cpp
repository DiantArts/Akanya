//
// Akanya, Engine
// sources/Engine/CubeMap
// allow sky or things like that
//

#include "pch.hpp"

#include "CubeMap.hpp"

#include "../OpenGL/Vertices.hpp"



namespace {



class TextureMap {
public:
    using DataType   = GLuint;
    using DataPtr    = std::shared_ptr<DataType>;
    using InternData = std::weak_ptr<DataType>;
    using Map        = std::unordered_map<std::string, InternData>;
    using iterator   = Map::iterator;

    TextureMap()
    {}

    DataPtr operator[](const std::string& filename)
    {
        {
            auto it { m_map.find(filename) };
            if (it != m_map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance(new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            m_map.erase(filename);
        });
        m_map.emplace(filename, instance);
        glGenTextures(1, instance.get());
        return instance;
    }

    DataPtr operator[](std::string&& filename)
    {
        {
            auto it { m_map.find(filename) };
            if (it != m_map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance(new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            m_map.erase(filename);
        });
        m_map.emplace(std::move(filename), instance);
        glGenTextures(1, instance.get());
        return instance;
    }

private:
    TextureMap::Map m_map;
};

TextureMap g_CachedTextures;



} // namespace



// ---------------------------------- *structors

::engine::graphic::actor::CubeMap::CubeMap(
    ::engine::graphic::opengl::Shader& shader,
    const glm::mat4& projection,
    const std::function<void()>& setAttributesFunc,
    const std::string_view verticesFilename,
    const std::string_view textureDirectory
)
    : engine::graphic::AActor(shader, projection, 1), m_texture(textureDirectory.data())
{
    m_vbo.bind();
    m_vao.bind();
    engine::graphic::opengl::Vertices(verticesFilename, m_numberOfArrayToDraw).createBuffer();
    setAttributesFunc();

    this->instances.setPosition(0, 0, 0);

    this->useShader();
    this->setIntoShader("skybox", static_cast<int>(0));
}

::engine::graphic::actor::CubeMap::~CubeMap()
{}



// ---------------------------------- Drawable

void ::engine::graphic::actor::CubeMap::draw(
    const ::engine::graphic::Camera& camera
) const
{
    glDepthFunc(GL_LEQUAL); // change depth function so depth test passes when values are equal to depth
                            // buffer's content
    ADrawable::draw(camera);
    glDepthFunc(GL_LESS); // set depth function back to default
}

void ::engine::graphic::actor::CubeMap::drawModels() const
{
    m_vao.bind();
    m_texture.bind();
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
}



// ---------------------------------- Textures

::engine::graphic::actor::CubeMap::Texture::Texture(const std::string& textureDirectory)
    : m_id(g_CachedTextures[textureDirectory])
{
    if (m_id.use_count() == 1) { // if just created
        glBindTexture(GL_TEXTURE_CUBE_MAP, *m_id);

        std::string textureConfigFilepath;
        textureConfigFilepath.reserve(textureDirectory.size() + ::engine::core::config::filepath::textures.size() + 17);
        textureConfigFilepath += ::engine::core::config::filepath::textures;
        textureConfigFilepath += textureDirectory;
        textureConfigFilepath += "/filepaths.config";

        std::ifstream configFile(textureConfigFilepath);
        if (!configFile.is_open()) {
            throw std::runtime_error("Unable to open '"s + textureConfigFilepath +
                                     "' texture config file");
        }


        std::string filepath, filename;
        filepath.reserve(textureDirectory.size() + ::engine::core::config::filepath::textures.size() + 1);
        filepath += ::engine::core::config::filepath::textures;
        filepath += textureDirectory;
        filepath += "/";
        size_t filepathSize { filepath.size() };

        stbi_set_flip_vertically_on_load(false);
        for (size_t i { 0 }; std::getline(configFile, filename); ++i) {
            filepath.replace(filepath.begin() + filepathSize, filepath.end(), filename);

            int        width, height, nrComponents;
            const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

            if (!data) {
                stbi_image_free(const_cast<unsigned char*>(data));
                throw std::runtime_error("Failed to load '"s + filepath + "' cube map's texture");
            }

            GLenum format;
            switch (nrComponents) {
            case 1: format = GL_RED; break;
            case 3: format = GL_RGB; break;
            case 4: format = GL_RGBA; break;
            default: throw std::runtime_error("unsupported texture format found");
            }

            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, format, width, height, 0, format,
                         GL_UNSIGNED_BYTE, data);
            stbi_image_free(const_cast<unsigned char*>(data));
        }
        stbi_set_flip_vertically_on_load(true);

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }
}

::engine::graphic::actor::CubeMap::Texture::~Texture() = default;

void ::engine::graphic::actor::CubeMap::Texture::bind() const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, *m_id);
}
