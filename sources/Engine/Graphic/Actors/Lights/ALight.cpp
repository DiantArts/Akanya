/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/Lights/ALight
** Light base class
*/

#include "pch.hpp"

#include "ALight.hpp"



namespace { std::vector<std::reference_wrapper<engine::graphic::actor::ALight>> g_CachedLights; }



namespace engine::graphic::actor::light {



// ---------------------------------- *structors

ALight::ALight(std::string name) : m_name(std::move(name))
{
    g_CachedLights.emplace_back(*this);
}

ALight::~ALight()
{
    std::erase_if(g_CachedLights, [this](const auto& elem) { return &elem.get() == this; });
}



// ---------------------------------- static

const std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>& ALight::getAll()
{
    return g_CachedLights;
}

std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>::const_iterator ALight::begin()
{
    return g_CachedLights.begin();
}

std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>::const_iterator ALight::cbegin()
{
    return g_CachedLights.cbegin();
}

std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>::const_iterator ALight::end()
{
    return g_CachedLights.end();
}

std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>::const_iterator ALight::cend()
{
    return g_CachedLights.cend();
}



// ---------------------------------- Others

const std::string& ALight::getName() const
{
    return m_name;
}



} // namespace engine::graphic::actor::light
