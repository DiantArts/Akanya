//
// Akanya, Engine
// sources/Objects/LightSourceCube
// A lamp ?
//

#include "pch.hpp"

#include "LightSourceCube.hpp"


// ---------------------------------- *structors

::game::object::LightSourceCube::LightSourceCube(
    std::vector<std::reference_wrapper<::engine::graphic::ALight>>& lights,
    const size_t numberOfPositions,
    const std::string& shaderFilepath
)
    : engine::graphic::actor::basicShape::Cube(shaderFilepath, numberOfPositions)
    , engine::graphic::light::Point(lights, "pointLights", this->instances)
{
    this->setScale(0.1F);
}

::game::object::LightSourceCube::~LightSourceCube() = default;



// ---------------------------------- override

void ::game::object::LightSourceCube::configureShader() const
{
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
