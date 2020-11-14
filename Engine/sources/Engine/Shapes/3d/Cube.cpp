/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Engine/Shapes/3d/Cube.hpp"

namespace engine::shape3d {

Cube::Cube(engine::Shader& shader)
    : Drawable(shader, 1)
{}

Cube::~Cube()
{}

void Cube::setAllIntoShader()
{
    // this->m_Shader.set("lightColor", this->m_Light.getColor());
}

} // namespace engine::shape3d
