/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#include "UpdatedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "Engine/Vertexes/Vertices.hpp"



namespace engine::shape3d::single {



// ---------------------------------------------------------------------------- *structors

UpdatedCube::UpdatedCube(engine::Shader&              shader,
                         const glm::vec3&             position /* = glm::vec3(0, 0, 0)) */,
                         const std::string_view       verticesFileName /* = "updatedCube" */,
                         const std::function<void()>& attributesSetter /* []{ ... } */,
                         const size_t                 numberOfTextures /* = 1 */)

    : Drawable(shader, position, attributesSetter, numberOfTextures)
{
    engine::Vertices(verticesFileName).createBuffer();
}



// ---------------------------------------------------------------------------- final

void UpdatedCube::setAllIntoShader(const engine::Camera&)
{}



// ---------------------------------------------------------------------------- virtual

glm::mat4 UpdatedCube::getModel(const glm::vec3& position)
{
    glm::mat4 model { 1.0F };
    return glm::translate(model, position);
}

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}



} // namespace engine::shape3d::single
