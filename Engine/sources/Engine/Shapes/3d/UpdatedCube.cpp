/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/UpdatedCube.hpp"

#include "Engine/Objects/3d/LightSourceCube.hpp" // tmp
extern engine::object3d::LightSourceCube& getLamp();

namespace engine::shape3d {

UpdatedCube::UpdatedCube(engine::Shader& shader, const glm::vec3& position /* = glm::vec3(0, 0, 0)) */,
        const std::string_view verticesFileName /* = "updatedCube" */,
        const std::function<void()>& attributesSetter /* []{ ... } */,
        const size_t numberOfTextures /* = 1 */)

    : Drawable(shader, position, attributesSetter, numberOfTextures)
{
    engine::Vertices(verticesFileName).createBuffer();
}

UpdatedCube::~UpdatedCube()
{}

void UpdatedCube::setAllIntoShader(const engine::Camera&)
{}

glm::mat4 UpdatedCube::getModel(const glm::vec3&)
{
    auto model(glm::mat4(1.0f));
    model = glm::translate(model, getLamp().getPosition());
    return model;
}

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}

} // namespace engine::shape3d
