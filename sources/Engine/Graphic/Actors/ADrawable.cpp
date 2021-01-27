/*
** Akanya, Engine
** sources/Engine/Actors/ADrawable
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#include "pch.hpp"

#include "ADrawable.hpp"

#include "Lights/ALight.hpp"
#include "debugMacros.hpp"
#include "pch.hpp"



namespace engine::graphic::actor {



// ---------------------------------- *structors

ADrawable::ADrawable(::engine::graphic::opengl::Shader& shader) : m_shader(shader)
{}

ADrawable::~ADrawable()
{}



// ---------------------------------- Draw
void ADrawable::draw(const engine::graphic::Camera& camera) const
{
    this->useShader();
    this->configureShader(camera);
    this->drawModels(camera);
}

void ADrawable::drawShadows(const engine::graphic::Camera& camera) const
{
    this->configureShader(camera);
    this->drawModels(camera);
}



// ---------------------------------- Update
void ADrawable::configureShader(const engine::graphic::Camera& camera) const
{
    this->setIntoShader("view", camera.getView());
    this->setIntoShader("projection",
                        glm::perspective(glm::radians(camera.getZoom()),
                                         (float)Window::width / (float)Window::height, 0.1F, 100.0F));
}



// ---------------------------------- Shader

const ::engine::graphic::opengl::Shader& ADrawable::getShader() const
{
    return m_shader;
}

void ADrawable::useShader() const
{
    m_shader.use();
}

void ADrawable::setIntoShader(const engine::graphic::actor::light::ALight& light) const
{
    light.setIntoEnlightenedShader(this->getShader());
}



} // namespace engine::graphic::actor
