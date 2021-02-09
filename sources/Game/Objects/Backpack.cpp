//
// Akanya, Engine
// sources/Objects/Backpack
// basic model backpack
//

#include "pch.hpp"

#include "Backpack.hpp"



// ---------------------------------- *structors

::game::object::Backpack::Backpack(::engine::graphic::opengl::Shader& shader,
        const size_t numberOfPositions)
    : engine::graphic::actor::Model(shader, "backpack/backpack.obj", numberOfPositions)
{}

::game::object::Backpack::~Backpack() = default;



// ---------------------------------- override

void ::game::object::Backpack::configureShader(
    const ::engine::graphic::Camera& camera
) const
{
    // for (const auto& light : engine::graphic::actor::ALight::getAll()) {
        // this->setIntoShader(light);
    // }

    this->setIntoShader("material.shininess", 32.0F);
}
