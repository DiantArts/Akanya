/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#include "ALight.hpp"

#include <functional>

#include "Container.hpp"


namespace {
engine::actor::light::Container g_CachedLights;
}



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

ALight::ALight(const engine::actor::Positions& instances, const std::string& name)
    : m_ContainedLight(g_CachedLights.emplace_back(instances, name))
{}

ALight::ALight(const engine::actor::Positions& instances, std::string&& name)
    : m_ContainedLight(g_CachedLights.emplace_back(instances, name))
{}

ALight::~ALight()
{}



// ---------------------------------------------------------------------------- static

const engine::actor::light::Container& ALight::getAll()
{
    return g_CachedLights;
}



} // namespace engine::actor::light
