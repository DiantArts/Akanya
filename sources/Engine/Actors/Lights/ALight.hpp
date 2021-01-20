/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___

#include <list>
#include <string>

#include "Container.hpp"

#include "../../Shadows.hpp"
#include "../Positions.hpp"



namespace engine::actor::light {



class ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit ALight(const engine::actor::Positions& instances, const std::string& name);
    explicit ALight(const engine::actor::Positions& instances, std::string&& name);
    virtual ~ALight() = 0;


    // ---------------------------------------------------------------------------- static
    static const engine::actor::light::Container& getAll();


    // ---------------------------------------------------------------------------- getters
    const std::string& getName() const;

private:
    engine::actor::light::ContainedLight& m_ContainedLight;

public:
    const std::string&                      name { m_ContainedLight.name };
};



} // namespace engine::actor::light

namespace engine::actor { using ALight = engine::actor::light::ALight; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___
