/*
** EPITECH PROJECT, 2020
** UpdatedMultipleCube
** File description:
** Light source as cube
*/

#include "UpdatedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Vertexes/Vertices.hpp"



namespace engine::shape3d::multiple {



// ---------------------------------------------------------------------------- *structors

UpdatedCube::UpdatedCube(engine::Shader&              shader,
                         const std::string_view       verticesFileName /* = "updateCube" */,
                         const std::function<void()>& attributesSetter /* [] { ... } */,
                         const size_t                 numberOfTextures /* = 1 */)
    : Drawable(shader, attributesSetter, numberOfTextures)
{
    engine::Vertices(verticesFileName).createBuffer();
}



// ---------------------------------------------------------------------------- virtuals

glm::mat4 UpdatedCube::getModel(const glm::vec3& position)
{
    glm::mat4 model { 1.0F };
    return glm::translate(model, position);
}

void UpdatedCube::setAllIntoShader(const engine::Camera&)
{}



// ---------------------------------------------------------------------------- final

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->m_NumberOfArrayToDraw;
}



} // namespace engine::shape3d::multiple
