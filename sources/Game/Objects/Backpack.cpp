//
// Akanya, Engine
// sources/Objects/Backpack
// basic model backpack
//

#include "pch.hpp"

#include "Backpack.hpp"



// ---------------------------------- *structors

::game::object::Backpack::Backpack(
    const std::string& shaderFilepath,
    const size_t numberOfPositions
)
    : engine::graphic::actor::Model(shaderFilepath, "backpack/backpack.obj", numberOfPositions)
{}

::game::object::Backpack::~Backpack() = default;



// ---------------------------------- override

void ::game::object::Backpack::configureShader() const
{
    this->setIntoShader("material.shininess", 32.0F);
}
