/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ABasicShape
** File description:
** Regroup every built-in shapes like Cube and Sphere
*/

#include "ABasicShape.hpp"
#include "debugMacros.hpp"

#include <stb/stb_image.h>

#include "Vertexes/Vertices.hpp"

#include "../Filepaths.hpp"

extern bool gammaEnabled;


namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ABasicShape::ABasicShape(engine::Shader&              shader,
                         const std::function<void()>& setAttributesFunc,
                         const std::string_view       verticesFilename,
                         const size_t                 numberOfPositions /* = 1 */,
                         const size_t                 numberOfTexturesToReserve /*= 1 */)
    : engine::AActor(shader, numberOfPositions)
{
    m_TextureVector.reserve(numberOfTexturesToReserve);

    m_Vbo.bind();
    m_Vao.bind();
    setAttributesFunc();
    engine::Vertices(verticesFilename, m_NumberOfArrayToDraw).createBuffer();

    DEBUG_MSG("basic shape created");
}

ABasicShape::~ABasicShape()
{}



// ---------------------------------------------------------------------------- *structors

void ABasicShape::drawModels(const engine::Camera&) const
{
    m_Vao.bind();
    this->bindTextures();
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, m_NumberOfArrayToDraw);
    }
}



// ---------------------------------------------------------------------------- Texture

ABasicShape::Texture::Texture(const std::string& filename, bool gammaCorrection)
    : engine::actor::Texture(filename)
{
    if (m_Id.use_count() == 1) { // if need initialisation
        int        width, height, nrComponents;

        std::string filepath;
        filepath.reserve(filename.size() + engine::filepath::textures.size());
        filepath += engine::filepath::textures;
        filepath += filename;
        const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

        if (!data) {
            throw std::runtime_error(std::string("ERROR: Failed to load '") + filepath + "' texture");
        }

        GLenum dataFormat;
        GLenum internalFormat;
        switch (nrComponents) {
        case 1: internalFormat = dataFormat = GL_RED; break;
        case 3: internalFormat = gammaCorrection ? GL_SRGB : GL_RGB; dataFormat = GL_RGB; break;
        case 4: internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA; dataFormat = GL_RGBA;  break;
        default:
            stbi_image_free(const_cast<unsigned char*>(data));
            throw std::runtime_error("unsupported texture format found");
        }

        glBindTexture(GL_TEXTURE_2D, *m_Id);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(const_cast<unsigned char*>(data));
    }
}

ABasicShape::Texture::~Texture()
{}

void ABasicShape::addTexture(const std::string& filename, const std::string& name, const bool gammaCorrection)
{
    this->setIntoShader(name.c_str(), static_cast<int>(m_TextureVector.size()));
    m_TextureVector.emplace_back(filename, gammaCorrection);
}

void ABasicShape::bindTextures() const
{
    for (size_t i { 0 }; i < m_TextureVector.size(); i++) {
        glActiveTexture(i + GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_TextureVector[i].get());
    }
}



} // namespace engine::actor
