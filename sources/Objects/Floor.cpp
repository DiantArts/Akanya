/*
** EPITECH PROJECT, 2020
** sources/Objects/Floor
** File description:
** Just a floor lol
*/

#include "Floor.hpp"

#include <glm/gtc/matrix_transform.hpp>

bool gammaEnabled { false };


namespace game::object {



// ---------------------------------------------------------------------------- *structors

Floor::Floor(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, Floor::setAttributes, "floor")
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "texture1");
}



// ---------------------------------------------------------------------------- override

void Floor::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());
    this->setIntoShader("gamma", gammaEnabled);

    // for (auto light : engine::actor::light::ALight::getAll()) {
        // this->setIntoShader("lightPos", light.position);
    // }

    glm::vec3 lightPositions[] = {
        { -3.0f, 0.0f, 0.0f },
        { -1.0f, 0.0f, 0.0f },
        { 1.0f, 0.0f, 0.0f },
        { 3.0f, 0.0f, 0.0f }
    };
    this->setIntoShader("lightPositions", std::span<glm::vec3>(lightPositions));

    glm::vec3 lightColors[] = {
        { 0.25F, 0.25F, 0.25F },
        { 0.50F, 0.50F, 0.50F },
        { 0.75F, 0.75F, 0.75F },
        { 1.00F, 1.00F, 1.00F }
    };
    this->setIntoShader("lightColors", std::span<glm::vec3>(lightColors));
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
