/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Point
** File description:
** Light source illuminating in all direction from a point
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_POINT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_POINT_HPP___

#include <glm/vec3.hpp>

#include "ALight.hpp"



namespace engine::actor::light {



class Point : engine::actor::ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    Point();
    ~Point();


private:
    struct Parameters {
        glm::vec3 position;
        glm::vec3 ambient  {   0.5F };
        glm::vec3 diffuse  {   0.3F };
        glm::vec3 specular {   1.0F };
        float constant     {   0.3F };
        float linear       {   0.3F };
        float quadratic    { 0.016F };
    };
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_POINT_HPP___
