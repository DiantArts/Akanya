/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Spot
** File description:
** Light source shooting in a specifique direction
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___

#include <glm/vec3.hpp>

#include "ALight.hpp"



namespace engine::actor::light {



class Spot : engine::actor::ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    Spot();
    ~Spot();


private:
    struct Parameters {
        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 ambient  {   0.5F };
        glm::vec3 diffuse  {   0.3F };
        glm::vec3 specular {   1.0F };
        float cutOff
        float constant     {   0.3F };
        float linear       {   0.3F };
        float quadratic    { 0.016F };
    };
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___
