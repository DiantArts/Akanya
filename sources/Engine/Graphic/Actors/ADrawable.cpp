/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/ADrawable
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#include "pch.hpp"
#include "ADrawable.hpp"

#include "Lights/ALight.hpp"
#include "debugMacros.hpp"
#include "pch.hpp"



namespace engine::graphic::actor {



// ---------------------------------- *structors

ADrawable::ADrawable(
    ::engine::graphic::opengl::Shader& shader
)
    : m_shader(shader)
{}

ADrawable::~ADrawable() = default;



// ---------------------------------- Draw
void ADrawable::draw(
    const ::engine::graphic::Window& window
) const
{
    this->useShader();
    this->configureShader(window);
    this->drawModels(window.getCamera());
}



// ---------------------------------- Update
void ADrawable::configureShader(
    const ::engine::graphic::Window& window
) const
{
    this->setIntoShader("view", window.getCamera().getView());
    this->setIntoShader("projection", glm::perspective(
            glm::radians(window.getCamera().getZoom()),
            window.getSize().width / window.getSize().height,
            0.1F,
            100.0F
        ));
}



// ---------------------------------- Shader

auto ADrawable::getShader() const
    -> const ::engine::graphic::opengl::Shader&
{
    return m_shader;
}

void ADrawable::useShader() const
{
    m_shader.use();
}

void ADrawable::setIntoShader(
    const engine::graphic::actor::light::ALight& light
) const
{
    light.setIntoEnlightenedShader(this->getShader());
}



} // namespace engine::graphic::actor
