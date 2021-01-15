/*
** EPITECH PROJECT, 2020
** sources/Scenes/AdvancedLight
** File description:
** Scene to test lightning
*/

#include "AdvancedLight.hpp"

#include "Engine/Actors/Objects/AdvancedEnlightenedCube.hpp"
#include "Engine/Actors/Objects/EnlightenedCube.hpp"
#include "Engine/Actors/Objects/LightSourceCube.hpp"
#include "Engine/Actors/Objects/ShadowCube.hpp"
#include "debugMacros.hpp"



namespace scene {



// ---------------------------------------------------------------------------- *structors

AdvancedLight::AdvancedLight()
{
    this->emplaceActor<engine::actor::object::LightSourceCube>(m_ShaderMap["lightSource"]);

    m_ShaderMap["pointShadow"].use();
    m_ShaderMap["pointShadow"].set("depthMap", 1);
}

AdvancedLight::~AdvancedLight()
{}



// ---------------------------------------------------------------------------- hardcoded

void AdvancedLight::additionalDraws() const
{}



} // namespace scene
