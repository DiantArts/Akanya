/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#include "LightSourceCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "debugMacros.hpp"

#include "../../../Vertexes/Vertices.hpp"



namespace engine::object3d::single {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader, const glm::vec3& position /* = (0, 0, 0) */)
    : Cube(shader, false)
{
    this->setScale(1);
    this->setPosition(position);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::transformShape(const engine::Camera& camera) const
{
    engine::graphic::shape3d::Basic::transformShape(camera);
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



} // namespace engine::object3d::single
