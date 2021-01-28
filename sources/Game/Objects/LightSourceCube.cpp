/*
** Akanya, Engine
** sources/Objects/LightSourceCube
** A lamp ?
*/

#include "pch.hpp"

#include "LightSourceCube.hpp"


// ---------------------------------- *structors

::game::object::LightSourceCube::LightSourceCube(
    ::engine::graphic::opengl::Shader& shader,
    const size_t numberOfPositions
)
    : engine::graphic::actor::basicShape::Cube(shader, numberOfPositions)
    , engine::graphic::actor::light::Point("pointLights", this->instances)
{
    this->setScale(0.1F);
}

::game::object::LightSourceCube::~LightSourceCube() = default;



// ---------------------------------- override

void ::game::object::LightSourceCube::configureShader(
    const ::engine::graphic::Window& window,
    const ::engine::graphic::Camera& camera
) const
{
    engine::graphic::actor::ABasicShape::configureShader(window, camera);
    this->setIntoShader("lightColor", m_parameters.color);
}

void ::game::object::LightSourceCube::update(
    float
)
{
    auto z = sin(glfwGetTime() / 1.2) * 3;
    for (auto& position : this->instances) {
        position.z = z;
    }
}
