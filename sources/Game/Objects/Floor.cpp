/*
** EPITECH PROJECT, 2020
** sources/Objects/Floor
** File description:
** Just a floor lol
*/

#include "Floor.hpp"
#include "Engine/Actors/Lights/ALight.hpp"

#include <glm/gtc/matrix_transform.hpp>

bool gammaEnabled { false };


namespace game::object {



// ---------------------------------------------------------------------------- *structors

Floor::Floor(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, Floor::setAttributes, "floor")
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
}



// ---------------------------------------------------------------------------- override

void Floor::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());
    this->setIntoShader("gamma", gammaEnabled);

    this->setIntoShader("material.shininess", 32.0F);

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
