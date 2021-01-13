/*
** EPITECH PROJECT, 2020
** sources/Engine/Shadow
** File description:
** first try of shadows
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOW_HPP___

#include "Actors/Vertexes/Fbo.hpp"
#include <cstddef>


class Shadow {
public:
    // ---------------------------------------------------------------------------- *structors
    Shadow();
    ~Shadow();

    void draw() const;

public:
    constexpr static size_t width { 1024 };
    constexpr static size_t height { 1024 };

private:
    GLuint m_Map;
    engine::Fbo m_Fbo;
};



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOW_HPP___
