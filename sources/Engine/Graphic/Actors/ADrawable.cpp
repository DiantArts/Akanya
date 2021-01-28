/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/ADrawable
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#include "pch.hpp"
#include "debugMacros.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::ADrawable::ADrawable(
    ::engine::graphic::opengl::Shader& shader
)
    : m_shader(shader)
{}

::engine::graphic::actor::ADrawable::~ADrawable() = default;



// ---------------------------------- Draw
void ::engine::graphic::actor::ADrawable::draw(
    const ::engine::graphic::Window& window,
    const ::engine::graphic::Camera& camera
) const
{
    this->useShader();
    this->configureShader(window, camera);
    this->drawModels(camera);
}



// ---------------------------------- Update
void ::engine::graphic::actor::ADrawable::configureShader(
    const ::engine::graphic::Window& window,
    const ::engine::graphic::Camera& camera
) const
{
    this->setIntoShader("view", camera.getView());
    this->setIntoShader("projection", glm::perspective(
            glm::radians(camera.getZoom()),
            window.getSize().width / window.getSize().height,
            0.1F,
            100.0F
        ));
}



// ---------------------------------- Shader

auto ::engine::graphic::actor::ADrawable::getShader() const
    -> const ::engine::graphic::opengl::Shader&
{
    return m_shader;
}

void ::engine::graphic::actor::ADrawable::useShader() const
{
    m_shader.use();
}

void ::engine::graphic::actor::ADrawable::setIntoShader(
    const engine::graphic::actor::light::ALight& light
) const
{
    light.setIntoEnlightenedShader(this->getShader());
}
