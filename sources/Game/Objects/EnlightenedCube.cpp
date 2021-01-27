/*
** EPITECH PROJECT, 2020
** sources/Objects/EnlightenedCube
** File description:
** An enlightened cube lol
*/

#include "EnlightenedCube.hpp"

#include "pch.hpp"

#include "Engine/Actors/Lights/ALight.hpp"
#include "Engine/Actors/Lights/Directional.hpp"
#include "Engine/Actors/Lights/Point.hpp"
#include "Engine/Actors/Lights/Spot.hpp"

extern bool gammaEnabled;
extern bool blinnEnabled;


namespace game::object {



// ---------------------------------------------------------------------------- *structors

EnlightenedCube::EnlightenedCube(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, EnlightenedCube::setAttributes, "lightningMap")
{
    this->useShader();

    this->addTexture("container.png", "material.diffuse");
    this->addTexture("containerBorders.png", "material.specular");

    this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
    this->setIntoShader("material.shininess", 8.0F);
}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());

    this->setIntoShader("gamma", gammaEnabled);
    this->setIntoShader("blinn", blinnEnabled);

    this->setIntoShader("nrDirLight", engine::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", engine::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", engine::actor::light::Spot::getNbLight());
    for (const auto& light : engine::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }
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


} // namespace game::object
