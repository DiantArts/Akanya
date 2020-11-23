/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/


#include "LightSourceCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

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
    this->m_Shader.set("lightColor", 1.0F, 1.0F, 1.0F);
}

glm::mat4 LightSourceCube::getModel(const glm::vec3& position)
{
    this->setPosition({ cos(glfwGetTime() * 2) * 10.0F, 5, -1 + sin(glfwGetTime() * 2) * 10.0F });

    glm::mat4 model { 1.0F };
    return glm::translate(model, position);
}



} // namespace engine::object3d::single