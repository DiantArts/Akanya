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
    Point(const std::string& name, const engine::actor::Positions& positions);
    ~Point();


    // ---------------------------------------------------------------------------- set
    void setIntoThisShader(const engine::Shader& shader) const override final;


private:
    struct Parameters {
        const engine::actor::Positions& positions;

        glm::vec3 ambient  {   0.5F };
        glm::vec3 diffuse  {   0.3F };
        glm::vec3 specular {   1.0F };
        float constant     {   0.3F };
        float linear       {   0.3F };
        float quadratic    { 0.016F };
    };
    Parameters m_Parameters;
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_POINT_HPP___
