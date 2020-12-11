/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_DEFAULT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_DEFAULT_HPP___

#include "Parameters.hpp"



namespace engine::light::dynamic {



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

    void setLightConstant(const float constant);

    void setLightLinear(const float linear);

    void setLightQuadratic(const float quadratic);

    const engine::light::dynamic::Parameters& getParameters() const;


private:
    engine::light::dynamic::Parameters m_Parameters {};
};



} // namespace engine::light::dynamic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_DEFAULT_HPP___
