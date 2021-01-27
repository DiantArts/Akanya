/*
** Akanya, Engine
** sources/Objects/LightSourceCube
** A lamp ?
*/

#include "pch.hpp"

#include "LightSourceCube.hpp"


namespace game::object {



// ---------------------------------- *structors

LightSourceCube::LightSourceCube(::engine::graphic::opengl::Shader& shader, const size_t numberOfPositions /* = 1 */)
    : engine::graphic::actor::basicShape::Cube(shader, numberOfPositions)
    , engine::graphic::actor::light::Point("pointLights", this->instances)
{
    this->setScale(0.1F);
}



// ---------------------------------- override

void LightSourceCube::configureShader(const engine::graphic::Camera& camera) const
{
    engine::graphic::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("lightColor", m_parameters.color);
}

void LightSourceCube::update(float)
{
    auto z = sin(glfwGetTime() / 1.2) * 3;
    for (auto& position : this->instances) {
        position.z = z;
    }
}



} // namespace game::object
