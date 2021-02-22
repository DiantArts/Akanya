//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ABasicShape
// Regroup every built-in shapes like Cube and Sphere
//

#include "pch.hpp"
#include "ABasicShape.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::ABasicShape::ABasicShape(
    const std::string& shaderFilepath,
    const std::function<void()>& setAttributesFunc,
    const std::string& verticesFilename,
    const size_t numberOfPositions,
    size_t numberOfTextures
)
    : engine::graphic::AActor(shaderFilepath, numberOfPositions)
{
    m_textureVector.reserve(numberOfTextures);

    m_vbo.bind();
    m_vao.bind();
    setAttributesFunc();
    engine::graphic::opengl::Vertices(verticesFilename, m_numberOfArrayToDraw).createBuffer();
}

::engine::graphic::actor::ABasicShape::~ABasicShape() = default;



// ---------------------------------- ADrawable

void ::engine::graphic::actor::ABasicShape::drawModels() const
{
    m_vao.bind();
    this->bindTextures();
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, m_numberOfArrayToDraw);
    }
}



// ---------------------------------- Texture

::engine::graphic::actor::ABasicShape::Texture::Texture(
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

::engine::graphic::actor::ABasicShape::Texture::~Texture()
{}



// ---------------------------------- Copy sementic

::engine::graphic::actor::ABasicShape::Texture::Texture(
    const Texture&
) noexcept = default;

auto ::engine::graphic::actor::ABasicShape::Texture::operator=(
    const Texture&
) noexcept -> Texture& = default;



// ---------------------------------- Move sementic

::engine::graphic::actor::ABasicShape::Texture::Texture(
    Texture&&
) noexcept = default;

auto ::engine::graphic::actor::ABasicShape::Texture::operator=(
    Texture&&
) noexcept -> Texture& = default;



// ---------------------------------- Texture

void ::engine::graphic::actor::ABasicShape::addTexture(
    const std::string& filename,
    const std::string& name,
    const bool gammaCorrection
)
{
    this->setIntoShader(name.c_str(), static_cast<int>(m_textureVector.size()));
    m_textureVector.emplace_back(filename, gammaCorrection);
}

void ::engine::graphic::actor::ABasicShape::bindTextures() const
{
    for (size_t i { 0 }; i < m_textureVector.size(); i++) {
        glActiveTexture(i + GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_textureVector[i].get());
    }
}
