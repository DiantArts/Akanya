/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Container
** File description:
** Container of every lights
*/

#include "Container.hpp"

#include "ALight.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- ContainedLight

ContainedLight::ContainedLight(const engine::actor::Positions& instancesParam,
                               const std::string&              name)
    : instances(instancesParam), name(name)
{}

ContainedLight::ContainedLight(const engine::actor::Positions& instancesParam,
                               std::string&&                   name)
    : instances(instancesParam), name(std::move(name))
{}



// ---------------------------------------------------------------------------- Get

const std::deque<engine::actor::light::ContainedLight>& Container::get() const
{
    return m_List;
}



// ---------------------------------------------------------------------------- Container stuff

engine::actor::light::ContainedLight& Container::emplace_back(const engine::actor::Positions& instances,
                                                              const std::string&              name)
{
    return m_List.emplace_back(instances, name);
}

engine::actor::light::ContainedLight& Container::emplace_back(const engine::actor::Positions& instances,
                                                              std::string&&                   name)
{
    return m_List.emplace_back(instances, std::move(name));
}

engine::actor::light::ContainedLight& Container::back()
{
    return m_List.back();
}



// ---------------------------------------------------------------------------- iterator

Container::Iterator::iterator Container::begin()
{
    return Container::Iterator::iterator { &m_List[0] };
}

Container::Iterator::const_iterator Container::begin() const
{
    return Container::Iterator::const_iterator { &m_List[0] };
}

Container::Iterator::const_iterator Container::cbegin() const
{
    return Container::Iterator::const_iterator { &m_List[0] };
}



Container::Iterator::iterator Container::end()
{
    return Container::Iterator::iterator { &m_List[m_List.size()] };
}

Container::Iterator::const_iterator Container::end() const
{
    return Container::Iterator::const_iterator { &m_List[m_List.size()] };
}

Container::Iterator::const_iterator Container::cend() const
{
    return Container::Iterator::const_iterator { &m_List[m_List.size()] };
}



} // namespace engine::actor::light
