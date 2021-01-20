/*
** EPITECH PROJECT, 2020
** sources/Objects/Backpack
** File description:
** basic model backpack
*/

#include "Backpack.hpp"
#include <iostream>
#include "Engine/Actors/Lights/ALight.hpp"



namespace game::object {



// ---------------------------------------------------------------------------- *structors

Backpack::Backpack(engine::Shader& shader, const size_t numberOfPositions)
    : engine::actor::Model(shader, "backpack/backpack.obj", numberOfPositions)
{}

Backpack::~Backpack()
{}



// ---------------------------------------------------------------------------- override
void Backpack::configureShader(const engine::Camera& camera) const
{
    engine::actor::ADrawable::configureShader(camera);

    // for (auto light : engine::actor::ALight::getAll()) {
        // this->setIntoShader("dirLight.direction", camera.getOrientation());
        // this->setIntoShader("dirLight.ambient", camera.parameters.ambient * glm::vec3 { 0 });
        // this->setIntoShader("dirLight.diffuse", camera.parameters.diffuse * glm::vec3 { 0 });
        // this->setIntoShader("dirLight.specular", camera.parameters.specular * glm::vec3 { 0 });
    // }

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

    this->setIntoShader("material.shininess", 32.0F);
}



} // namespace game::object
