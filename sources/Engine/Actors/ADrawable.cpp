/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ADrawable
** File description:
** abstract class
*/

#include "ADrawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../Window.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ADrawable::ADrawable(engine::Shader& shader) : m_Shader(shader)
{}

ADrawable::~ADrawable()
{}



// ---------------------------------------------------------------------------- Draw
void ADrawable::draw(const engine::Camera& camera) const
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
}



// ---------------------------------------------------------------------------- Shader

const engine::Shader& ADrawable::getShader() const
{
    return this->m_Shader;
}



} // namespace engine::actor
