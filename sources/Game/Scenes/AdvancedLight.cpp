/*
** EPITECH PROJECT, 2020
** sources/Game/Scenes/AdvancedLight
** File description:
** Scene to test lightnings
*/

#include "AdvancedLight.hpp"

#include "../Objects/Floor.hpp"
#include "../Objects/EnlightenedCube.hpp"
#include "../Objects/LightSourceCube.hpp"
#include "../Objects/ShadowCube.hpp"
#include "debugMacros.hpp"



namespace game::scene {



// ---------------------------------------------------------------------------- *structors

AdvancedLight::AdvancedLight()
{
    this->emplaceActor<game::object::LightSourceCube>(m_ShaderMap["lightSource"]);
    m_ShaderMap["pointShadow"].use();
    m_ShaderMap["pointShadow"].set("depthMap", 1);
}

AdvancedLight::~AdvancedLight()
{}



// ---------------------------------------------------------------------------- hardcoded

void AdvancedLight::additionalDraws() const
{}



} // namespace game::scene