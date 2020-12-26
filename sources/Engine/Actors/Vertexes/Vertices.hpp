/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vertices
** File description:
** Extract vertices from files and alloc buffers to binded ones
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VERTICES_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VERTICES_HPP___

#include <string_view>
#include <vector>



namespace engine {



class Vertices {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Vertices(std::string_view filepath, size_t& numberOfArrayToDraw);


    // ---------------------------------------------------------------------------- buffer

    void createBuffer();


private:
    std::vector<float> m_Vertices;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VERTICES_HPP___
