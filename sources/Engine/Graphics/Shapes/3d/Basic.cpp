/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Basic
** File description:
** BasicShape
*/

#include "Basic.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Window.hpp"
#include "../../Vertexes/Vertices.hpp"

namespace engine::graphic::shape3d {



Basic::Basic(engine::Shader&              shader,
             const std::function<void()>& setAttributes,
             const std::string_view       verticesFilename,
             const bool                   isMultiplePositionsShape /* = false */,
             const size_t                 numberOfTextures /*= 1 */)
    : engine::graphic::Drawable(shader, setAttributes, numberOfTextures)
    , engine::graphic::Transformable(isMultiplePositionsShape)
{
    engine::Vertices(verticesFilename, this->m_NumberOfArrayToDraw).createBuffer();
}

Basic::~Basic()
{}



// ---------------------------------------------------------------------------- Override
void Basic::drawModels() const
{
    if (this->isMultiplePositions()) {
        for (const auto& position : *this->m_MultiplePositions) {
            this->set("model", glm::scale(this->getModel(*this, position.get()), this->m_Scale));
            glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
        }
    } else {
        this->set("model", glm::scale(this->getModel(*this, *this->m_SinglePosition), this->m_Scale));
        glDrawArrays(GL_TRIANGLES, 0, this->m_NumberOfArrayToDraw);
    }
}

void Basic::update(float)
{}

void Basic::transformShape(const engine::Camera& camera) const
{
    this->set("view", camera.getView());
    this->set("projection", glm::perspective(glm::radians(camera.getZoom()),
                                             (float)Window::width / (float)Window::height, 0.1F, 100.0F));
}



// ---------------------------------------------------------------------------- Virtuals

glm::mat4 Basic::getModel(const engine::graphic::Transformable&,
                          const engine::graphic::position::Single& position) const
{
    return glm::translate(glm::mat4 { 1.0F }, position.get());
}



} // namespace engine::graphic::shape3d
