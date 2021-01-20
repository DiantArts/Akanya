/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Container
** File description:
** Container of every lights
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_CONTAINER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_CONTAINER_HPP___

#include <deque>
#include <string>

#include "Iterator.hpp"



namespace engine::actor::light {



struct ContainedLight {
    const engine::actor::Positions&  instances;
    const std::string                name;
};



class Container : engine::actor::light::Iterator {
public:
    const std::deque<engine::actor::light::ContainedLight>& get() const;
    engine::actor::light::ContainedLight& emplace_back(const engine::actor::Positions& instances,
                                                       const std::string&              name);
    engine::actor::light::ContainedLight&
    emplace_back(const engine::actor::Positions& instances, std::string&& name);
    engine::actor::light::ContainedLight& back();


    // ---------------------------------------------------------------------------- iterator
    Iterator::iterator       begin() override;
    Iterator::const_iterator begin() const override;
    Iterator::const_iterator cbegin() const override;

    Iterator::iterator       end() override;
    Iterator::const_iterator end() const override;
    Iterator::const_iterator cend() const override;


private:
    std::deque<engine::actor::light::ContainedLight> m_List;
};


} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_CONTAINER_HPP___
