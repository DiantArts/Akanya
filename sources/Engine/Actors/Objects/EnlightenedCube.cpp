/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Objects/EnlightenedCube
** File description:
** default Enlightened cube
*/

#include "EnlightenedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>



namespace engine::actor::object {



// ---------------------------------------------------------------------------- *structors

EnlightenedCube::EnlightenedCube(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, EnlightenedCube::setAttributes, "lightningMap")
{
    this->useShader();
    this->addTexture("container.png", "material.diffuse");
    this->addTexture("containerBorders.png", "material.specular");
}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("material.shininess", 32.0F);
    this->setIntoShader("viewPos", camera.getPosition());


    // directional light
    // this->setIntoShader("dirLight.direction", camera.getOrientation());
    // this->setIntoShader("dirLight.ambient", camera.parameters.ambient * glm::vec3 { 0 });
    // this->setIntoShader("dirLight.diffuse", camera.parameters.diffuse * glm::vec3 { 0 });
    // this->setIntoShader("dirLight.specular", camera.parameters.specular * glm::vec3 { 0 });

    for (auto light : engine::actor::light::ALight::getAll()) {
        this->setIntoShader(light.name + ".position", light.position);
        this->setIntoShader(light.name + ".ambient", light.parameters.ambient);
        this->setIntoShader(light.name + ".diffuse", light.parameters.diffuse);
        this->setIntoShader(light.name + ".specular", light.parameters.specular);
        this->setIntoShader(light.name + ".constant", light.parameters.constant);
        this->setIntoShader(light.name + ".linear", light.parameters.linear);
        this->setIntoShader(light.name + ".quadratic", light.parameters.quadratic);
    }
    this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
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


} // namespace engine::actor::object
