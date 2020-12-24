/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Vertexes/Vertices
** File description:
** coordonate to create a shape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VERTICES_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VERTICES_HPP___

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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VERTICES_HPP___
