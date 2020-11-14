/*
** EPITECH PROJECT, 2020
** LightCube
** File description:
** Light source as cube
*/

#include "Engine/Shapes/3d/LightCube.hpp"

namespace engine::shape3d {

LightCube::LightCube(engine::Shader& shader)
    : Drawable(shader, 1)
{}

LightCube::~LightCube()
{}

void LightCube::setAllIntoShader()
{
    // this->m_Shader.set("lightColor", this->m_Light.getColor());
}

} // namespace engine::shape3d
