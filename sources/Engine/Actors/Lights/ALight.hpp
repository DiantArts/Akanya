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

#include "../../Shadows.hpp"
#include "../Positions.hpp"



namespace engine { class Shader; }



namespace engine::actor::light {



class ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit ALight(std::string name);
    virtual ~ALight() = 0;


    ALight(const ALight&) = delete;
    ALight(ALight&&) = delete;

    ALight& operator=(const ALight&) = delete;
    ALight& operator=(ALight&&) = delete;

    // ---------------------------------------------------------------------------- static
    static const std::vector<std::reference_wrapper<ALight>>& getAll();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator begin();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator cbegin();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator end();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator cend();


    // ---------------------------------------------------------------------------- Others
    virtual void setIntoThisShader(const engine::Shader& shader) const = 0;
    const std::string& getName() const;

private:
    const std::string& m_Name;
};



} // namespace engine::actor::light

namespace engine::actor { using ALight = engine::actor::light::ALight; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ALIGHT_HPP___
