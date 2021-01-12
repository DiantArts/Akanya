/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#include "ALight.hpp"



namespace {

class LightContainer {
public:
    const std::list<engine::actor::ALight::Wrapper>& get() const
    {
        return this->m_List;
    }

    engine::actor::ALight::Wrapper& emplace_back(const engine::actor::Positions& instances)
    {
        return this->m_List.emplace_back(instances);
    }

    engine::actor::ALight::Wrapper& back()
    {
        return this->m_List.back();
    }

private:
    std::list<engine::actor::ALight::Wrapper> m_List;
};

LightContainer g_CachedLights;

} // namespace



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

ALight::ALight(const engine::actor::Positions& instances)
    : parameters(g_CachedLights.emplace_back(instances).parameters)
    , instancesRef(g_CachedLights.back().instances)
{}

ALight::~ALight()
{}



// ---------------------------------------------------------------------------- getEveryLights
const std::list<engine::actor::ALight::Wrapper>& ALight::getAll()
{
    return g_CachedLights.get();
}


// ---------------------------------------------------------------------------- iterator
ALight::Iterator::iterator ALight::begin()
{
    return ALight::Iterator::iterator { this };
}

ALight::Iterator::const_iterator ALight::begin() const
{
    return ALight::Iterator::const_iterator { this };
}

ALight::Iterator::const_iterator ALight::cbegin() const
{
    return ALight::Iterator::const_iterator { this };
}



ALight::Iterator::iterator ALight::end()
{
    return ALight::Iterator::iterator { this };
}

ALight::Iterator::const_iterator ALight::end() const
{
    return ALight::Iterator::const_iterator { this };
}

ALight::Iterator::const_iterator ALight::cend() const
{
    return ALight::Iterator::const_iterator { this };
}



} // namespace engine::actor::light
