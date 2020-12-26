/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/BasicShape
** File description:
** BasicShape
*/

#include "ABasicShape.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../Vertexes/Vertices.hpp"

namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

BasicShape::BasicShape(engine::Shader&              shader,
                       const std::function<void()>& setAttributes,
                       const std::string_view       verticesFilename,
                       const size_t                 numberOfPositions /* = 1 */,
                       const size_t                 numberOfTextures /*= 1 */)
    : engine::actor::AShape(shader, numberOfPositions)
{
    this->m_TextureVector.reserve(numberOfTextures);

    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributes();
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();
}

BasicShape::~BasicShape()
{}



// ---------------------------------------------------------------------------- *structors

void BasicShape::drawModels(const engine::Camera&) const
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

void BasicShape::addTexture(const std::string_view filepath, const std::string_view name)
{
    this->m_TextureVector.push_back(filepath, this->m_Shader.get(), name, numberOfTextures++);
}



// ---------------------------------------------------------------------------- Texture
BasicShape::Texture::Texture(std::string_view filepath, engine::Shader& shader, const std::string& name, size_t textureIndex)
{
    this->m_Index = GL_TEXTURE0 + textureIndex;

    int        width, height, nrComponents;
    const auto data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

    if (!data) {
        throw std::runtime_error(std::string("ERROR: Failed to load '") + textureFilepath + "' texture\n");
    }

    GLenum format;
    switch (nrComponents) {
    case 1: format = GL_RED; break;
    case 3: format = GL_RGB; break;
    case 4: format = GL_RGBA; break;
    default: throw std::runtime_error("unsupported texture format found");
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

    shader.set(name.c_str(), textureIndex);
}

BasicShape::Texture::~Texture()
{}


void BasicShape::Texture::bind() const
{
    glActiveTexture(this->m_Index);
    glBindTexture(GL_TEXTURE_2D, this->m_Id);
}



} // namespace engine::actor
