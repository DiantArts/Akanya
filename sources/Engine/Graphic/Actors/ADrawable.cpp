//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ADrawable
// Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
//

#include "pch.hpp"
#include "Engine/Graphic/Camera.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::ADrawable::ADrawable(
    const std::string& shaderFilepath
)
    : m_shader(shaderFilepath)
{
    this->setBlockBindingIntoShader("CameraInformations", 0);
}

::engine::graphic::actor::ADrawable::~ADrawable() = default;



// ---------------------------------- Draw

void ::engine::graphic::actor::ADrawable::draw() const
{
    this->useShader();
    this->configureShader();
    this->drawModels();
}



// ---------------------------------- Update

void ::engine::graphic::actor::ADrawable::configureShader() const
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
    const engine::graphic::light::ALight& light
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
