/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Default
** File description:
** Default light that needs to be improve somehow
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DEFAULT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DEFAULT_HPP___

#include "Parameters.hpp"



namespace engine::light {



class Default {
public:
    // ---------------------------------------------------------------------------- *structors
    Default() = default;
    explicit Default(const engine::light::dynamic::Parameters& parameters);
    explicit Default(engine::light::dynamic::Parameters&& parameters);
    virtual ~Default() = 0;


    // ---------------------------------------------------------------------------- Parameters
    void setLightParameters(const engine::light::dynamic::Parameters& parameters);
    void setLightParameters(engine::light::dynamic::Parameters&& parameters);

    void setLightAmbient(const glm::vec3& ambient);
    void setLightAmbient(glm::vec3&& ambient);

    void setLightDiffuse(const glm::vec3& diffuse);
    void setLightDiffuse(glm::vec3&& diffuse);

    void setLightSpecular(const glm::vec3& specular);
    void setLightSpecular(glm::vec3&& specular);

    void setLightConstant(float constant);

    void setLightLinear(float linear);

    void setLightQuadratic(float quadratic);

    const engine::light::dynamic::Parameters& getParameters() const;


private:
    engine::light::dynamic::Parameters m_Parameters {};
};



} // namespace engine::light



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_DEFAULT_HPP___
