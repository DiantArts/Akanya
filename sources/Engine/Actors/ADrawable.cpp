/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Drawable
** File description:
** Drawable
*/

#include "Drawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../Window.hpp"



namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Drawable::Drawable(engine::Shader& shader) : m_Shader(shader)
{}

Drawable::~Drawable()
{}



// ---------------------------------------------------------------------------- Draw
void Drawable::draw(const engine::Camera& camera) const
{
    this->applyPerspective(camera);
    this->drawModels(camera);
}



// ---------------------------------------------------------------------------- Update
void Drawable::applyPerspective(const engine::Camera& camera) const
{
    this->setIntoShader("view", camera.getView());
    this->setIntoShader("projection",
                        glm::perspective(glm::radians(camera.getZoom()),
                                         (float)Window::width / (float)Window::height, 0.1F, 100.0F));
}



// ---------------------------------------------------------------------------- Shader

void Drawable::setShader(engine::Shader& shader)
{
    this->m_Shader = shader;
}

const engine::Shader& Drawable::getShader() const
{
    return this->m_Shader.get();
}



} // namespace engine::graphic
