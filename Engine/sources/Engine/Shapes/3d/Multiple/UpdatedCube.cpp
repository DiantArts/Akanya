/*
** EPITECH PROJECT, 2020
** UpdatedMultipleCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/Multiple/UpdatedCube.hpp"

#include "Engine/Objects/3d/LightSourceCube.hpp" // tmp
extern engine::object3d::LightSourceCube& getLamp();

namespace engine::shape3d::multiple {

UpdatedCube::UpdatedCube(engine::Shader& shader,
        const std::string_view verticesFileName /* = "updateCube" */,
        const std::function<void()>& attributesSetter /* []{ ... } */,
        const size_t numberOfTextures /* = 1 */)
    : Drawable(shader, attributesSetter, numberOfTextures)
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
    return this->m_NumberOfArrayToDraw;
}

} // namespace engine::shape3d::multiple
