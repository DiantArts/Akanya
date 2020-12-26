/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Parameters
** File description:
** those parameters allow inheriting classes to illuminates others
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_PARAMETERS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_PARAMETERS_HPP___

#include <glm/vec3.hpp>



namespace engine::light::dynamic {



struct Parameters {
    glm::vec3 ambient { 0.5F };
    glm::vec3 diffuse { 0.3F };
    glm::vec3 specular { 1.0F };


    float constant { 0.3F };
    float linear { 0.3F };
    float quadratic { 0.016F };

    // float constant { 0.5F };
    // float linear { 0.3F };
    // float quadratic { 0.016F };

    // float constant { 1.0F };
    // float linear { 0.09F };
    // float quadratic { 0.032F };
};



} // namespace engine::light::dynamic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_PARAMETERS_HPP___
