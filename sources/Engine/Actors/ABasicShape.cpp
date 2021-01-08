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



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ABasicShape::ABasicShape(engine::Shader&              shader,
                         const std::function<void()>& setAttributesFunc,
                         const std::string_view       verticesFilename,
                         const size_t                 numberOfPositions /* = 1 */,
                         const size_t                 numberOfTexturesToReserve /*= 1 */)
    : engine::actor::AActor(shader, numberOfPositions)
{
    this->m_TextureVector.reserve(numberOfTexturesToReserve);

    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributesFunc();
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();

    DEBUG_MSG("basic shape created");
}

ABasicShape::~ABasicShape()
{}



// ---------------------------------------------------------------------------- *structors

void ABasicShape::drawModels(const engine::Camera&) const
{
    this->m_Vao.bind();
    this->bindTextures();
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
    }
}



// ---------------------------------------------------------------------------- Texture

ABasicShape::Texture::Texture(const std::string& filename)
    : engine::Texture(filename)
{
    if (this->m_Id.use_count() == 1) { // if need initialisation
        int        width, height, nrComponents;

        std::string filepath;
        filepath.reserve(filename.size() + engine::filepath::textures.size());
        filepath += engine::filepath::textures;
        filepath += filename;
        const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

        if (!data) {
            throw std::runtime_error(std::string("ERROR: Failed to load '") + filepath + "' texture");
        }

        GLenum format;
        switch (nrComponents) {
        case 1: format = GL_RED; break;
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default:
            stbi_image_free(const_cast<unsigned char*>(data));
            throw std::runtime_error("unsupported texture format found");
        }

        glBindTexture(GL_TEXTURE_2D, *this->m_Id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
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

void ABasicShape::addTexture(const std::string& filename, const std::string& name)
{
    this->useShader();
    this->setIntoShader(name.c_str(), static_cast<int>(this->m_TextureVector.size()));
    this->m_TextureVector.emplace_back(filename);
}

void ABasicShape::bindTextures() const
{
    for (size_t i { 0 }; i < this->m_TextureVector.size(); i++) {
        glActiveTexture(i + GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->m_TextureVector[i].get());
    }
}



} // namespace engine::actor
