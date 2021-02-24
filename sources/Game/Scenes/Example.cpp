//
// Akanya, Engine
// sources/Game/Scenes/Example
// Simple example of a scene to test things
//

#include "pch.hpp"
#include "Example.hpp"

#include "Game/Objects/Floor.hpp"
#include "Game/Objects/Backpack.hpp"
#include "Game/Objects/EnlightenedCube.hpp"
#include "Game/Objects/LightSourceCube.hpp"
#include "Game/Entities/Player.hpp"



// ---------------------------------- *structors

::game::scene::Example::Example(
    ::engine::graphic::Window& window
)
    : ::engine::graphic::AScene(window)
{
    auto& lightSource { this->emplaceActor<game::object::LightSourceCube>(4) };
    lightSource.instances[0] = glm::vec3{ -3.0F, 0.0F, 0.0F };
    lightSource.instances[1] = glm::vec3{ -1.0F, 0.0F, 0.0F };
    lightSource.instances[2] = glm::vec3{  1.0F, 0.0F, 0.0F };
    lightSource.instances[3] = glm::vec3{  3.0F, 0.0F, 0.0F };

    this->emplaceActor<game::object::Floor>();

    auto& player { this->emplacePlayer<game::entity::Player>("multiEnlightened") };
    player.instances[0] = glm::vec3{ 1.0f, 0.0f, 4.0f };
}

::game::scene::Example::~Example()
{}
