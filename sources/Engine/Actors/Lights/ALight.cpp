/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#include "ALight.hpp"

#include "Container.hpp"



namespace { engine::actor::light::Container g_CachedLights; }



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

ALight::ALight(const engine::actor::Positions& instances, const std::string& name)
    : parameters(g_CachedLights.emplace_back(instances, name).parameters)
    , name(g_CachedLights.back().name)
{}

ALight::ALight(const engine::actor::Positions& instances, std::string&& name)
    : parameters(g_CachedLights.emplace_back(instances, std::move(name)).parameters)
    , name(g_CachedLights.back().name)
{}

ALight::~ALight()
{}



// ---------------------------------------------------------------------------- getEveryLights

const engine::actor::light::Container& ALight::getAll()
{
    return g_CachedLights;
}



} // namespace engine::actor::light
