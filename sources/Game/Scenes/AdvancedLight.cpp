/*
** Akanya, Engine
** sources/Game/Scenes/AdvancedLight
** Scene to test lightnings
*/

#include "pch.hpp"

#include "AdvancedLight.hpp"

#include "../Objects/Floor.hpp"
#include "../Objects/EnlightenedCube.hpp"
#include "../Objects/LightSourceCube.hpp"
#include "debugMacros.hpp"



namespace game::scene {



// ---------------------------------- *structors

AdvancedLight::AdvancedLight()
{
    this->emplaceActor<game::object::LightSourceCube>(m_shaderMap["lightSource"]);
    m_shaderMap["pointShadow"].use();
    m_shaderMap["pointShadow"].set("depthMap", 1);
}

AdvancedLight::~AdvancedLight()
{}



} // namespace game::scene
