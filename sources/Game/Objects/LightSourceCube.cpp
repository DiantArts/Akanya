/*
** EPITECH PROJECT, 2020
** sources/Objects/LightSourceCube
** File description:
** A lamp ?
*/

#include "pch.hpp"

#include "LightSourceCube.hpp"


namespace game::object {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader, const size_t numberOfPositions /* = 1 */)
    : engine::actor::basicShape::Cube(shader, numberOfPositions)
    , engine::actor::light::Point("pointLights", this->instances)
{
    this->setScale(0.1F);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("lightColor", m_Parameters.color);
}

void LightSourceCube::update(float)
{
    auto z = sin(glfwGetTime() / 1.2) * 3;
    for (auto& position : this->instances) {
        position.z = z;
    }
}



} // namespace game::object
