/*
** EPITECH PROJECT, 2020
** sources/Objects/ShadowCube
** File description:
** Trying to implement shadows, just a trial
*/

#include "ShadowCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

extern const glm::mat4* shadowsSpaceMatrix;


namespace game::object {



// ---------------------------------------------------------------------------- *structors

ShadowCube::ShadowCube(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, ShadowCube::setAttributes, "cube")
{
    this->useShader();
    this->addTexture("container.png", "material.diffuse");
    this->setIntoShader("shadowMap", 1);
}



// ---------------------------------------------------------------------------- override

void ShadowCube::configureShader(const engine::Camera& camera) const
{
    ABasicShape::configureShader(camera);

    this->setIntoShader("viewPos", camera.getPosition());
    // for (auto light : light::ALight::getAll()) {
        // this->setIntoShader("lightPos", light.position);
    // }
    // this->setIntoShader("lightSpaceMatrix", *shadowsSpaceMatrix);

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

void ShadowCube::setAttributes()
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
