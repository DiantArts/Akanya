//
// Akanya, Engine
// sources/Game/Scenes/Example
// Simple example of a scene to test things
//

#include "pch.hpp"

#include "Example.hpp"

#include "Game/Objects/Backpack.hpp"
#include "Game/Objects/EnlightenedCube.hpp"
#include "Game/Objects/Floor.hpp"
#include "Game/Objects/LightSourceCube.hpp"
#include "debugMacros.hpp"



namespace game::scene {



// ---------------------------------- *structors

Example::Example(
    ::engine::graphic::Window& window
)
    : ::engine::graphic::AScene(window)
{
    // this->emplaceActor<game::object::Floor>(m_shaderMap["floor"]);

    auto& lightSource { this->emplaceActor<game::object::LightSourceCube>(m_shaderMap["lightSource"], 4) };
    lightSource.instances[0] = glm::vec3(-3.0F, 0.0F, 0.0F);
    lightSource.instances[1] = glm::vec3(-1.0F, 0.0F, 0.0F);
    lightSource.instances[2] = glm::vec3( 1.0F, 0.0F, 0.0F);
    lightSource.instances[3] = glm::vec3( 3.0F, 0.0F, 0.0F);
}

Example::~Example()
{}



} // namespace game::scene
