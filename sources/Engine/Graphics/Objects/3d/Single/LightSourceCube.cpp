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


engine::object3d::single::LightSourceCube& getLamp()
{
    static engine::Shader                            lightSourceshader("lightSource", "lightSource");
    static engine::object3d::single::LightSourceCube lightSource(lightSourceshader, { 2.0F, 0.8F, 0.0F });
    return lightSource;
}



namespace engine::object3d::single {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader, const glm::vec3& position /* = (0, 0, 0) */)
    : Cube(shader, false)
{
    this->setScale(0.2, 0.2, 0.2);
    this->setPosition(position);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::transformShape(const engine::Camera& camera) const
{
    engine::graphic::shape3d::Basic::transformShape(camera);
    this->set("lightColor", 1.0F, 1.0F, 1.0F);
}

void LightSourceCube::update(float)
{
    auto lampYMouvement = -pow(abs(cos(glfwGetTime() * 2) * 5), 3);

    getLamp().setPosition(
        glm::vec3 { 0, 6 - pow(abs(cos(glfwGetTime() * 2) * 5), 3) / 200, -1 + sin(glfwGetTime() * 2) * 4.0F });
    this->setPosition(glm::vec3 { 0, 4 + lampYMouvement / 200, -1 + sin(glfwGetTime() * 2) * 4.0F });
}

glm::mat4 LightSourceCube::getModel(const engine::graphic::position::Single& position) const
{
    return glm::translate(glm::mat4 { 1.0F }, position.get());
}



} // namespace engine::object3d::single
