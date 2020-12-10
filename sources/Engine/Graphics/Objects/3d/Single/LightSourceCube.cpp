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
    : UpdatedCube(shader, position)
{
    this->setScale(0.2, 0.2, 0.2);
}



// ---------------------------------------------------------------------------- override

void LightSourceCube::setAllIntoShader(const engine::Camera&)
{
    this->getShader().set("lightColor", 1.0F, 1.0F, 1.0F);
}

glm::mat4 LightSourceCube::getModel(const glm::vec3& position)
{
    auto lampYMouvement = -pow(abs(cos(glfwGetTime() * 2) * 5), 3);

    getLamp().setPosition(
        { 0, 6 - pow(abs(cos(glfwGetTime() * 2) * 5), 3) / 200, -1 + sin(glfwGetTime() * 2) * 4.0F });
    this->setPosition({ 0, 4 + lampYMouvement / 200, -1 + sin(glfwGetTime() * 2) * 4.0F });

    glm::mat4 model { 1.0F };
    return glm::translate(model, position);
}



} // namespace engine::object3d::single
