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
#include "debugMacros.hpp"



namespace scene {



// ---------------------------------------------------------------------------- *structors

AdvancedLight::AdvancedLight()
{
    auto lightSource {
        std::make_unique<engine::actor::object::LightSourceCube>(this->m_ShaderMap["old/lightSource"])
    };
    lightSource->instances.move(0.0F, 10.0F, 0.0F);
    this->pushActor(std::move(lightSource));


    auto cube {
        std::make_unique<engine::actor::object::EnlightenedCube>(this->m_ShaderMap["old/multiEnlightened"], 3)
    };
    cube->addTexture("container.png", "material.diffuse");
    cube->addTexture("containerBorders.png", "material.specular");
    cube->instances.add(3.0F, 2.0F, 2.0F);
    cube->instances.add(0.0F, 0.5F, 0.0F);
    cube->instances.add(-1.0F, 1.0F, 3.0F);
    this->pushActor(std::move(cube));


    auto floor {
        std::make_unique<engine::actor::object::AdvancedEnlightenedCube>(this->m_ShaderMap["old/advancedLight"])
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
