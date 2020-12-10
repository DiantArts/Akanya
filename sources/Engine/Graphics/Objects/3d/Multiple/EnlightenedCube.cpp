/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "EnlightenedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Vertexes/Vertices.hpp"



// clang-format off

#include "../Single/LightSourceCube.hpp" // tmp
extern engine::object3d::single::LightSourceCube& getLamp(); // tmp

// clang-format on



namespace engine::object3d::multiple {



// ---------------------------------------------------------------------------- *structors

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : UpdatedCube(shader, "lightningMap", [] {
        // vertex attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        // normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // normal attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    })
{}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::setAllIntoShader(const engine::Camera& camera)
{
    this->getShader().set("viewPos", camera.getPosition());

    this->getShader().set("material.shininess", 32.0F);

    this->getShader().set("light.position", getLamp().getPosition());
    // this->getShader().set("light.position", camera.getPosition());
    // this->getShader().set("light.direction", camera.getFront());
    this->getShader().set("light.cutOff", glm::cos(glm::radians(12.5f)));
    this->getShader().set("light.outerCutOff", glm::cos(glm::radians(17.5f)));


    this->getShader().set("light.ambient", getLamp().getParameters().ambient);
    this->getShader().set("light.diffuse", getLamp().getParameters().diffuse);
    this->getShader().set("light.specular", getLamp().getParameters().specular);

    this->getShader().set("light.constant", getLamp().getParameters().constant);
    this->getShader().set("light.linear", getLamp().getParameters().linear);
    this->getShader().set("light.quadratic", getLamp().getParameters().quadratic);
}

glm::mat4 EnlightenedCube::getModel(const glm::vec3& position)
{
    // static size_t i { 0 };
    // float angle = 20.0F * i;
    // i = (i + 1) % 10;
    // model = glm::translate(model, position);
    // model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0F, 0.3F, 0.5F));

    glm::mat4 model { 1.0F };
    return glm::translate(model, position);
}


} // namespace engine::object3d::multiple
