/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/Cube.hpp"

namespace engine::shape3d {

Cube::Cube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    engine::Vertices("cube").createBuffer();

    // position corrd attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // texture corrd attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->addTexture("wall.jpg", "texture1", 0);
    this->addTexture("awesomeface.png", "texture2", 1);
}

Cube::~Cube()
{}

void Cube::setAllIntoShader()
{}

} // namespace engine::shape3d
