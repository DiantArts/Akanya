/*
** EPITECH PROJECT, 2020
** sources/Objects/Floor
** File description:
** Just a floor lol
*/

#include "Floor.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "Engine/Actors/Lights/ALight.hpp"
#include "Engine/Actors/Lights/Directional.hpp"
#include "Engine/Actors/Lights/Point.hpp"
#include "Engine/Actors/Lights/Spot.hpp"

extern bool gammaEnabled;
extern bool blinnEnabled;



namespace game::object {



// ---------------------------------------------------------------------------- *structors

Floor::Floor(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, Floor::setAttributes, "floor")
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
    this->setIntoShader("material.shininess", 1000.0F);
}



// ---------------------------------------------------------------------------- override

void Floor::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());

    this->setIntoShader("gamma", gammaEnabled);
    this->setIntoShader("blinn", blinnEnabled);

    this->setIntoShader("nrDirLight", engine::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", engine::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", engine::actor::light::Spot::getNbLight());
    for (auto light : engine::actor::light::ALight::getAll()) {
        this->setIntoShader(light);
    }
}



// ---------------------------------------------------------------------------- Attributes

void Floor::setAttributes()
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
