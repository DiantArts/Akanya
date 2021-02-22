//
// Akanya
// sources/Engine/Component/Drawable
// Drawable component
//

#include "pch.hpp"
#include "Drawable.hpp"



// ---------------------------------- *structors

::engine::component::Drawable::Drawable(
    const std::string& shaderFilepath,
    const std::string& verticesFilename,
    void (&setAttributesFunc)()
)
    : m_shader(shaderFilepath)
{
    m_vbo.bind();
    m_vao.bind();
    setAttributesFunc();
    engine::graphic::opengl::Vertices(verticesFilename, m_numberOfArrayToDraw).createBuffer();
}

::engine::component::Drawable::~Drawable() = default;



// ---------------------------------- Draw

void ::engine::component::Drawable::draw(
    const glm::mat4& tranform
) const
{
    m_shader.use();
    this->configureShader();
    this->setIntoShader("model", transform);
    m_vao.bind();
    for (size_t i { 0 }; i < m_textureVector.size(); i++) {
        glActiveTexture(i + GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_textureVector[i].get());
    }
    glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
}


void ::engine::component::Drawable::configureShader() const
{}



// ---------------------------------- Texture

void ::engine::component::Drawable::addTexture(
    const std::string& name,
    const std::string& filepath,
    bool gammaCorrection
)
{
    this->setIntoShader(name.c_str(), static_cast<int>(m_textureVector.size()));
    m_textureVector.emplace_back(filepath, gammaCorrection);
}

::engine::component::Drawable::Texture::Texture(
    const std::string& filename,
    const bool gammaCorrection
)
    : engine::graphic::actor::Texture(filename)
{
    if (m_id.use_count() == 1) { // if need initialisation
        int width, height, nrComponents;

        std::string filepath;
        filepath.reserve(filename.size() + engine::core::config::filepath::textures.size());
        filepath += engine::core::config::filepath::textures;
        filepath += filename;
        const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

        if (!data) {
            throw std::runtime_error("ERROR: Failed to load '"s + filepath + "' texture");
        }

        GLenum dataFormat;
        GLenum internalFormat;
        switch (nrComponents) {
        case 1: internalFormat = dataFormat = GL_RED; break;
        case 3:
            internalFormat = gammaCorrection ? GL_SRGB : GL_RGB;
            dataFormat     = GL_RGB;
            break;
        case 4:
            internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA;
            dataFormat     = GL_RGBA;
            break;
        default:
            stbi_image_free(const_cast<unsigned char*>(data));
            throw std::runtime_error("unsupported texture format found");
        }

        glBindTexture(GL_TEXTURE_2D, *m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(const_cast<unsigned char*>(data));
    }
}
