/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ADrawable
** File description:
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#include "ADrawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "Lights/ALight.hpp"
#include "Lights/Directional.hpp"
#include "Lights/Point.hpp"
#include "Lights/Spot.hpp"
#include "debugMacros.hpp"

#include "../Window.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ADrawable::ADrawable(engine::Shader& shader) : m_Shader(shader)
{
    DEBUG_MSG("(" << m_Id << "): created");
}

ADrawable::~ADrawable()
{}



// ---------------------------------------------------------------------------- Draw
void ADrawable::draw(const engine::Camera& camera) const
{
    this->useShader();
    this->configureShader(camera);
    this->drawModels(camera);
}

void ADrawable::drawShadows(const engine::Camera& camera) const
{
    this->configureShader(camera);
    this->drawModels(camera);
}



// ---------------------------------------------------------------------------- Update
void ADrawable::configureShader(const engine::Camera& camera) const
{
    this->setIntoShader("view", camera.getView());
    this->setIntoShader("projection",
                        glm::perspective(glm::radians(camera.getZoom()),
                                         (float)Window::width / (float)Window::height, 0.1F, 100.0F));
    this->setIntoShader("nrDirLight", engine::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", engine::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", engine::actor::light::Spot::getNbLight());
}



// ---------------------------------------------------------------------------- Shader

const engine::Shader& ADrawable::getShader() const
{
    return m_Shader;
}

void ADrawable::useShader() const
{
    m_Shader.use();
}

void ADrawable::setIntoShader(const engine::actor::light::ALight& light) const
{
    light.setIntoEnlightenedShader(this->getShader());
}



} // namespace engine::actor
