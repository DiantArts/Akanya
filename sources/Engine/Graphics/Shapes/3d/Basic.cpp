/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Basic
** File description:
** BasicShape
*/

#include "Basic.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../Vertexes/Vertices.hpp"

namespace engine::graphic::shape3d {



// ---------------------------------------------------------------------------- *structors

Basic::Basic(engine::Shader&              shader,
             const std::function<void()>& setAttributes,
             const std::string_view       verticesFilename,
             const size_t                 numberOfPositions /* = 1 */,
             const size_t                 numberOfTextures /*= 1 */)
    : engine::graphic::Drawable(shader)
    , engine::graphic::Transformable(numberOfPositions)
    , m_TextureVector(shader, numberOfTextures)
{
    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributes();
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();
}

Basic::~Basic()
{}



// ---------------------------------------------------------------------------- *structors

void Basic::drawModels(const engine::Camera&) const
{
    this->m_Vao.bind();
    this->m_TextureVector.bindThemAll();
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
    }
}


glm::mat4 Basic::getModel(const glm::vec3& position) const
{
    return this->transformModel(position);
}



// ---------------------------------------------------------------------------- Textures

void Basic::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}


const engine::container::vector::Texture& Basic::getTextures() const
{
    return this->m_TextureVector;
}



} // namespace engine::graphic::shape3d
