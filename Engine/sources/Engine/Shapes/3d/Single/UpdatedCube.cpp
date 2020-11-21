/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#include "UpdatedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "Engine/Vertexes/Vertices.hpp"



// clang-format off

#include "../../../Objects/3d/Single/LightSourceCube.hpp" // tmp
extern engine::object3d::single::LightSourceCube& getLamp(); // tmp

// clang-format on



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

glm::mat4 UpdatedCube::getModel(const glm::vec3&)
{
    glm::mat4 model { 1.0f };
    return glm::translate(model, getLamp().getPosition());
}

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}



} // namespace engine::shape3d::single
