/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Fbo
** File description:
** FrameBuffer Object
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_FBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_FBO_HPP___

#include "pch.hpp"



namespace engine {



class Fbo {
public:
    // ---------------------------------------------------------------------------- *structors
    Fbo();
    ~Fbo();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Fbo;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_FBO_HPP___
