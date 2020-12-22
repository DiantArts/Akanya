/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Multiple/LightSourceCube
** File description:
** LightsourceCube
*/

#include "LightSourceCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "debugMacros.hpp"

#include "../../../Vertexes/Vertices.hpp"


extern engine::object3d::multiple::LightSourceCube* lamp;



namespace engine::object3d::multiple {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader) : Cube(shader, true)
{
    this->setScale(0.15);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::transformShape(const engine::Camera& camera) const
{
    engine::graphic::shape3d::Basic::transformShape(camera);
    this->set("lightColor", 1.0F, 1.0F, 1.0F);
}

void LightSourceCube::update(float)
{}



} // namespace engine::object3d::multiple
