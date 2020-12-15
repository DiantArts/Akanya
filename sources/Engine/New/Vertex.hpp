/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Vertex
** File description:
** Vertex
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>



namespace engine {



struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_VERTEX_HPP___
