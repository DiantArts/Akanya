/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Container
** File description:
** Container of every lights
*/

#include "Container.hpp"

#include "ALight.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- ContainerWrapper

ContainerWrapper::ContainerWrapper(const engine::actor::Positions& instancesParam, const std::string& name)
    : instances(instancesParam), name(name)
{}

ContainerWrapper::ContainerWrapper(const engine::actor::Positions& instancesParam, std::string&& name)
    : instances(instancesParam), name(std::move(name))
{}



// ---------------------------------------------------------------------------- Get

const std::deque<engine::actor::light::ContainerWrapper>& Container::get() const
{
    return this->m_List;
}



// ---------------------------------------------------------------------------- Container stuff

engine::actor::light::ContainerWrapper& Container::emplace_back(const engine::actor::Positions& instances,
                                                                const std::string&              name)
{
    return this->m_List.emplace_back(instances, name);
}

engine::actor::light::ContainerWrapper& Container::emplace_back(const engine::actor::Positions& instances,
                                                                std::string&&                   name)
{
    return this->m_List.emplace_back(instances, std::move(name));
}

engine::actor::light::ContainerWrapper& Container::back()
{
    return this->m_List.back();
}



// ---------------------------------------------------------------------------- iterator

Container::Iterator::iterator Container::begin()
{
    return Container::Iterator::iterator { &this->m_List[0] };
}

Container::Iterator::const_iterator Container::begin() const
{
    return Container::Iterator::const_iterator { &this->m_List[0] };
}

Container::Iterator::const_iterator Container::cbegin() const
{
    return Container::Iterator::const_iterator { &this->m_List[0] };
}



Container::Iterator::iterator Container::end()
{
    return Container::Iterator::iterator { &this->m_List[this->m_List.size()] };
}

Container::Iterator::const_iterator Container::end() const
{
    return Container::Iterator::const_iterator { &this->m_List[this->m_List.size()] };
}

Container::Iterator::const_iterator Container::cend() const
{
    return Container::Iterator::const_iterator { &this->m_List[this->m_List.size()] };
}



} // namespace engine::actor::light
