/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ADrawable
** File description:
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#include "ADrawable.hpp"
#include "debugMacros.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../Window.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ADrawable::ADrawable(engine::Shader& shader)
    : m_Shader(shader)
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



// ---------------------------------------------------------------------------- Update
void ADrawable::configureShader(const engine::Camera& camera) const
{
    this->setIntoShader("view", camera.getView());
    this->setIntoShader("projection",
                        glm::perspective(glm::radians(camera.getZoom()),
                                         (float)Window::width / (float)Window::height, 0.1F, 100.0F));
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



} // namespace engine::actor
