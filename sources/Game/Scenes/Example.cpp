/*
** EPITECH PROJECT, 2020
** sources/Game/Scenes/Example
** File description:
** Simple example of a scene to test things
*/

#include "Example.hpp"

#include "debugMacros.hpp"

#include "Game/Objects/Backpack.hpp"
#include "Game/Objects/EnlightenedCube.hpp"
#include "Game/Objects/Floor.hpp"
#include "Game/Objects/LightSourceCube.hpp"



namespace game::scene {



// ---------------------------------------------------------------------------- *structors

Example::Example()
{
    this->emplaceActor<game::object::Floor>(m_ShaderMap["floor"]);

    auto& lightSource { this->emplaceActor<game::object::LightSourceCube>(m_ShaderMap["lightSource"], 4) };
    lightSource.instances.add(-0.0F, 2.0F,   0.0F);
    lightSource.instances.add(-5.0F, 2.0F, 105.0F);
    lightSource.instances.add(-3.0F, 1.5F,  -7.5F);
    lightSource.instances.add( 5.0F, 2.0F, 105.0F);

    auto& cube { this->emplaceActor<game::object::EnlightenedCube>(m_ShaderMap["multiEnlightened"]) };
    cube.instances.add( 0.0F,  0.0F,   0.0F);
    cube.instances.add( 2.0F, 10.0F, -15.0F);
    cube.instances.add(-1.7F,  3.0F,  -7.5F);
    cube.instances.add( 1.5F,  2.0F,  -2.5F);
    cube.instances.add( 1.5F,  0.2F,  -1.5F);
    cube.instances.add(-1.3F,  1.0F,  -1.5F);

    auto& backpack { this->emplaceActor<game::object::Backpack>(m_ShaderMap["model3d"], 2) };
    backpack.instances.addPosition(-5.0F, 2.0F, 0.0F);
    backpack.instances.addPosition( 5.0F, 2.0F, 0.0F);
}

Example::~Example()
{}



} // namespace game::scene
