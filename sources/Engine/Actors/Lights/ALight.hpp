/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/ALight
** File description:
** Light base class
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___

#include <list>

#include "Iterator.hpp"
#include "Parameters.hpp"



namespace engine::actor::light {

class Iterator;



class ALight : engine::actor::light::Iterator {
public:
    struct Wrapper {
        Wrapper(const engine::actor::Positions& instancesParam) : instances(instancesParam) {}

        engine::actor::light::Parameters parameters;
        const engine::actor::Positions&  instances;
    };

public:
    // ---------------------------------------------------------------------------- *structors
    explicit ALight(const engine::actor::Positions& instances);
    ~ALight();


    // ---------------------------------------------------------------------------- getEveryLights
    static const std::list<engine::actor::light::ALight::Wrapper>& getAll();


    // ---------------------------------------------------------------------------- iterator
    Iterator::iterator       begin() override;
    Iterator::const_iterator begin() const override;
    Iterator::const_iterator cbegin() const override;

    Iterator::iterator       end() override;
    Iterator::const_iterator end() const override;
    Iterator::const_iterator cend() const override;


public:
    engine::actor::light::Parameters& parameters;

private:
    const engine::actor::Positions& instancesRef;
    friend class engine::actor::light::Iterator;
};



} // namespace engine::actor::light

namespace engine::actor { using ALight = engine::actor::light::ALight; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___
