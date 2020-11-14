/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Objects/3d/EnlightenedCube.hpp"

extern glm::vec3 lightPos;

namespace engine::object3d {

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : UpdatedCube(shader)
{}

EnlightenedCube::~EnlightenedCube()
{}

void EnlightenedCube::setAllIntoShader()
{
    this->m_Shader.set("objectColor", 1.0f, 0.5f, 0.31f);
    this->m_Shader.set("lightColor",  1.0f, 1.0f, 1.0f);
    this->m_Shader.set("lightPos", lightPos);
}

glm::mat4 EnlightenedCube::getModel(const glm::vec3&)
{
    return glm::mat4(1.0f);
}

} // namespace engine::object3d
