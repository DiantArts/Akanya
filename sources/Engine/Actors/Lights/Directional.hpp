/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Directional
** File description:
** Light source comming from infinitly far away
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DIRECTIONAL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DIRECTIONAL_HPP___

#include <glm/vec3.hpp>

#include "ALight.hpp"



namespace engine::actor::light {



class Directional : engine::actor::ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    Directional(const std::string& name, glm::vec3 direction);
    ~Directional();


    // ---------------------------------------------------------------------------- set
    void setIntoThisShader(const engine::Shader& shader) const override final;


private:
    struct Parameters {
        glm::vec3 direction;

        glm::vec3 ambient  { 0.5F };
        glm::vec3 diffuse  { 0.3F };
        glm::vec3 specular { 1.0F };
    };
    Parameters m_Parameters;
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DIRECTIONAL_HPP___
