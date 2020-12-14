/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Light/Dynamic/Parameters
** File description:
** Dynamic light parameters
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_PARAMETERS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_PARAMETERS_HPP___

#include <glm/vec3.hpp>



namespace engine::light::dynamic {



struct Parameters {
    Parameters();

    glm::vec3 ambient { 0.1F };
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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_LIGHT_DYNAMIC_PARAMETERS_HPP___
