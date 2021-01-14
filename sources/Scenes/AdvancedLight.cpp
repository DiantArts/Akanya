/*
** EPITECH PROJECT, 2020
** sources/Scenes/AdvancedLight
** File description:
** Scene to test lightning
*/

#include "AdvancedLight.hpp"
#include "Engine/Actors/Objects/AdvancedEnlightenedCube.hpp"
#include "Engine/Actors/Objects/ShadowCube.hpp"
#include "Engine/Actors/Objects/EnlightenedCube.hpp"
#include "Engine/Actors/Objects/LightSourceCube.hpp"
#include "debugMacros.hpp"



namespace scene {



// ---------------------------------------------------------------------------- *structors

AdvancedLight::AdvancedLight()
{
    auto lightSource {
        std::make_unique<engine::actor::object::LightSourceCube>(m_ShaderMap["old/lightSource"])
    };
    lightSource->instances.move(-2.0F, 4.0F, -1.0F);
    this->pushActor(std::move(lightSource));


    auto cube {
        std::make_unique<engine::actor::object::ShadowCube>(m_ShaderMap["shadowMapping"], 3)
    };
    cube->instances.add(3.0F, 2.0F, 2.0F);
    cube->instances.add(0.0F, 0.5F, 0.0F);
    cube->instances.add(-1.0F, 1.0F, 3.0F);
    this->pushActor(std::move(cube));


    auto floor {
        std::make_unique<engine::actor::object::AdvancedEnlightenedCube>(m_ShaderMap["old/advancedLight"])
    };
    floor->addTexture("woodFloor.jpg", "texture1", false);
    this->pushActor(std::move(floor));
}

AdvancedLight::~AdvancedLight()
{}



// ---------------------------------------------------------------------------- hardcoded

void AdvancedLight::additionalDraws() const
{}



} // namespace scene
