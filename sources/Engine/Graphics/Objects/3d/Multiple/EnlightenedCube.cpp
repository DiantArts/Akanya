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
    : Cube(shader, true, EnlightenedCube::setAttributes, "lightningMap")
{}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::transformShape(const engine::Camera& camera) const
{
    engine::graphic::shape3d::Basic::transformShape(camera);
    this->set("viewPos", camera.getPosition());

    this->set("material.shininess", 32.0F);

    this->set("light.position", getLamp().getPosition());
    // this->set("light.position", camera.getPosition());
    // this->set("light.direction", camera.getFront());
    this->set("light.cutOff", glm::cos(glm::radians(12.5f)));
    this->set("light.outerCutOff", glm::cos(glm::radians(17.5f)));


    this->set("light.ambient", getLamp().getParameters().ambient);
    this->set("light.diffuse", getLamp().getParameters().diffuse);
    this->set("light.specular", getLamp().getParameters().specular);

    this->set("light.constant", getLamp().getParameters().constant);
    this->set("light.linear", getLamp().getParameters().linear);
    this->set("light.quadratic", getLamp().getParameters().quadratic);
}



// ---------------------------------------------------------------------------- Attributes

void EnlightenedCube::setAttributes()
{
    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // normal attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}


} // namespace engine::object3d::multiple
