/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/EnlightenedCube.hpp"

extern glm::vec3 lightPos;

namespace engine::shape3d {

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    engine::Vertices("updatedCube").createBuffer();

    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

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

size_t EnlightenedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}

} // namespace engine::shape3d
