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
    void setIntoEnlightenedShader(const engine::Shader& shader) const override final;
    void setIntoLightSourceShader(const engine::Shader& shader) const override final;


    // ---------------------------------------------------------------------------- get
    static size_t getNbLight();


private:
    struct Parameters {
        const engine::actor::Positions& positions;

        glm::vec3 ambient  {  0.1F  };
        glm::vec3 diffuse  {  0.5F  };
        glm::vec3 specular {  1.0F  };
        float constant     {  1.0F  };
        float linear       {  1.0F };
        float quadratic    { 0.064F };

        glm::vec3 color { 1.0F, 1.0F, 1.0F };
    };
    Parameters m_Parameters;

    static inline size_t m_NbLight { 0 };
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_POINT_HPP___
