/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/LightSourceCube.hpp"

namespace engine::shape3d {

LightSourceCube::LightSourceCube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    engine::Vertices("updatedCube").createBuffer();

    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

LightSourceCube::~LightSourceCube()
{}

void LightSourceCube::setAllIntoShader()
{}

} // namespace engine::shape3d
