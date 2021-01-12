/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Objects/LightSourceCube
** File description:
** Lamp as cube
*/

#include "LightSourceCube.hpp"



namespace engine::object {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader, const size_t numberOfPositions /* = 1 */)
    : engine::actor::basicShape::Cube(shader, numberOfPositions), engine::actor::ALight(this->instances)
{
    this->setScale(0.1F);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("lightColor", 1.0F, 1.0F, 1.0F);
}

void LightSourceCube::update(float)
{
    // auto lampYMouvement = -pow(abs(cos(glfwGetTime() * 2) * 5), 3);

    // getLamp().setPosition(
    // glm::vec3 { 0, 6 - pow(abs(cos(glfwGetTime() * 2) * 5), 3) / 200, -1 + sin(glfwGetTime() * 2) * 4.0F
    // });
    // this->setPosition(glm::vec3 { 0, 4 + lampYMouvement / 200, -1 + sin(glfwGetTime() * 2) * 4.0F });
}



} // namespace engine::object
