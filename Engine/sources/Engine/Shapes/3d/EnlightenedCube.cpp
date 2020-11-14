/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/EnlightenedCube.hpp"

namespace engine::shape3d {

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    engine::Vertices("updatedCube").createBuffer();

    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

EnlightenedCube::~EnlightenedCube()
{}

void EnlightenedCube::setAllIntoShader()
{
    this->m_Shader.set("objectColor", 1.0f, 0.5f, 0.31f);
    this->m_Shader.set("lightColor",  1.0f, 1.0f, 1.0f);
}

} // namespace engine::shape3d
