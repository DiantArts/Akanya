/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#include "ALight.hpp"



namespace { std::vector<std::reference_wrapper<engine::actor::ALight>> g_CachedLights; }



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

ALight::ALight(std::string name) : m_Name(std::move(name))
{
    g_CachedLights.emplace_back(*this);
}

ALight::~ALight()
{
    std::erase_if(g_CachedLights, [this](const auto& elem) { return &elem.get() == this; });
}



// ---------------------------------------------------------------------------- static

const std::vector<std::reference_wrapper<engine::actor::ALight>>& ALight::getAll()
{
    return g_CachedLights;
}

std::vector<std::reference_wrapper<engine::actor::ALight>>::const_iterator ALight::begin()
{
    return g_CachedLights.begin();
}

std::vector<std::reference_wrapper<engine::actor::ALight>>::const_iterator ALight::cbegin()
{
    return g_CachedLights.cbegin();
}

std::vector<std::reference_wrapper<engine::actor::ALight>>::const_iterator ALight::end()
{
    return g_CachedLights.end();
}

std::vector<std::reference_wrapper<engine::actor::ALight>>::const_iterator ALight::cend()
{
    return g_CachedLights.cend();
}



// ---------------------------------------------------------------------------- Others

const std::string& ALight::getName() const
{
    return m_Name;
}



} // namespace engine::actor::light
