/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ABasicShape
** File description:
** Regroup every built-in shapes like Cube and Sphere
*/

#include "ABasicShape.hpp"

#include <stb/stb_image.h>

#include "Vertexes/Vertices.hpp"

#include "../Filepaths.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ABasicShape::ABasicShape(engine::Shader&              shader,
                         const std::function<void()>& setAttributesFunc,
                         const std::string_view       verticesFilename,
                         const size_t                 numberOfPositions /* = 1 */,
                         const size_t                 numberOfTextures /*= 1 */)
    : engine::actor::AActor(shader, numberOfPositions)
{
    this->m_TextureVector.reserve(numberOfTextures);

    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributesFunc();
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();
}

ABasicShape::~ABasicShape()
{}



// ---------------------------------------------------------------------------- *structors

void ABasicShape::drawModels(const engine::Camera&) const
{
    this->m_Vao.bind();
    for (const auto& texture : this->m_TextureVector) {
        texture.bind();
    }
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
    }
}



// ---------------------------------------------------------------------------- Textures

void ABasicShape::addTexture(const std::string_view filename, const std::string_view name)
{
    std::string filepath;
    filepath.reserve(filename.size() + engine::filepath::textures.size());
    filepath += engine::filepath::textures;
    filepath += filename;

    this->m_TextureVector.emplace_back(filepath, this->getShader(), name.data(), numberOfTextures++);
}



// ---------------------------------------------------------------------------- Texture
ABasicShape::Texture::Texture(const std::string&    filepath,
                              const engine::Shader& shader,
                              const std::string&    name,
                              const size_t          textureIndex)
{
    this->m_Index = GL_TEXTURE0 + textureIndex;

    int        width, height, nrComponents;
    const auto data { stbi_load(filepath.c_str(), &width, &height, &nrComponents, 0) };

    if (!data) {
        throw std::runtime_error(std::string("ERROR: Failed to load '") + filepath + "' texture\n");
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

    glGenTextures(1, &this->m_Id);

    glBindTexture(GL_TEXTURE_2D, this->m_Id);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(const_cast<unsigned char*>(data));

    shader.use();
    shader.set(name.c_str(), static_cast<int>(textureIndex));
}

ABasicShape::Texture::~Texture()
{}


void ABasicShape::Texture::bind() const
{
    glActiveTexture(this->m_Index);
    glBindTexture(GL_TEXTURE_2D, this->m_Id);
}



} // namespace engine::actor
