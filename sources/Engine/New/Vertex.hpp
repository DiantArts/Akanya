/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Vertex
** File description:
** Vertex
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>



namespace engine {



struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};



} // engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___
