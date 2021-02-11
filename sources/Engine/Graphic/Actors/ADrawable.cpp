//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ADrawable
// Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
//

#include "pch.hpp"
#include "debugMacros.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::ADrawable::ADrawable(
    ::engine::graphic::opengl::Shader& shader
)
    : m_shader(shader)
{
    this->setBlockBindingIntoShader("CameraInformations", 0);
}

::engine::graphic::actor::ADrawable::~ADrawable() = default;



// ---------------------------------- Draw

void ::engine::graphic::actor::ADrawable::draw(
    const ::engine::graphic::Camera& camera
) const
{
    this->useShader();
    this->configureShader(camera);
    this->drawModels();
}



// ---------------------------------- Update

void ::engine::graphic::actor::ADrawable::configureShader(
    const ::engine::graphic::Camera&
) const
{}



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

void ::engine::graphic::actor::ADrawable::setBlockBindingIntoShader(
    const std::string& name,
    const size_t index
) const
{
    m_shader.setBlockBinding(name, index);
}




// ---------------------------------- ID

auto ::engine::graphic::actor::ADrawable::getId() const
    -> size_t
{
    return m_id;
}
