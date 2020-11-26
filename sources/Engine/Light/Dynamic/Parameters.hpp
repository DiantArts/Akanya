/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#pragma once


#include <glm/vec3.hpp>



namespace engine::light::dynamic {



struct Parameters {
    Parameters();

    glm::vec3 ambient { 0.2F, 0.2F, 0.2F };
    glm::vec3 diffuse { 0.5F, 0.5F, 0.5F };
    glm::vec3 specular { 1.0F, 1.0F, 1.0F };

    float constant { 0.5F };
    float linear { 0.3F };
    float quadratic { 0.016F };

    // float constant { 1.0F };
    // float linear { 0.09F };
    // float quadratic { 0.032F };
};



} // namespace engine::light::dynamic
