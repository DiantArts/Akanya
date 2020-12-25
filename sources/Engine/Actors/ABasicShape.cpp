/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/BasicShape
** File description:
** BasicShape
*/

#include "Basicshape.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../Vertexes/Vertices.hpp"

namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

BasicShape::BasicShape(engine::Shader&              shader,
                       const std::function<void()>& setAttributes,
                       const std::string_view       verticesFilename,
                       const size_t                 numberOfPositions /* = 1 */,
                       const size_t                 numberOfTextures /*= 1 */)
    : engine::graphic::Shape(shader, numberOfPositions)
    , m_TextureVector(shader, numberOfTextures)
{
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
    this->m_TextureVector.bindThemAll();
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
    }
}



// ---------------------------------------------------------------------------- Textures

void BasicShape::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}


const engine::container::vector::Texture& BasicShape::getTextures() const
{
    return this->m_TextureVector;
}



} // namespace engine::graphic
