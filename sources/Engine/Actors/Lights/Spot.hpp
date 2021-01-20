/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Spot
** File description:
** Light source shooting in a specifique direction
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ALight.hpp"



namespace engine::actor::light {



class Spot : engine::actor::ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    Spot(const std::string& name, const engine::actor::Positions& positions, glm::vec3 direction);
    ~Spot();


    // ---------------------------------------------------------------------------- set
    void setIntoThisShader(const engine::Shader& shader) const override final;


private:
    struct Parameters {
        const engine::actor::Positions& positions;
        glm::vec3 direction;

        glm::vec3 ambient  {   0.5F };
        glm::vec3 diffuse  {   0.3F };
        glm::vec3 specular {   1.0F };
        float constant     {   0.3F };
        float linear       {   0.3F };
        float quadratic    { 0.016F };
        float cutOff       { glm::cos(glm::radians(12.5F)) };
        float outerCutOff  { glm::cos(glm::radians(15.0F)) };
    };
    Parameters m_Parameters;
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_SPOT_HPP___
