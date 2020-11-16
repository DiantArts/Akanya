/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Objects/3d/Multiple/EnlightenedCube.hpp"

#include "Engine/Objects/3d/LightSourceCube.hpp" // tmp
extern engine::object3d::LightSourceCube& getLamp();

namespace engine::object3d::multiple {

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : UpdatedCube(shader)
{}

EnlightenedCube::~EnlightenedCube()
{}

void EnlightenedCube::setAllIntoShader(const engine::Camera& camera)
{
    this->m_Shader.set("viewPos", camera.getPosition());

    this->m_Shader.set("material.shininess", 64.0f);

    this->m_Shader.set("light.position", getLamp().getPosition());
    this->m_Shader.set("light.ambient",  getLamp().getLightParameters().ambient);
    this->m_Shader.set("light.diffuse",  getLamp().getLightParameters().diffuse);
    this->m_Shader.set("light.specular", getLamp().getLightParameters().specular);
}

glm::mat4 EnlightenedCube::getModel(const glm::vec3& position)
{
    auto model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    return model;
}

} // namespace engine::object3d::multiple
