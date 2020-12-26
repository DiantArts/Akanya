/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Ebo
** File description:
** Element Buffer Object: help to determine which vertex to draw
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_EBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_EBO_HPP___

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../NonCopyable.hpp"



namespace engine {



class Ebo : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- *structors
    Ebo();
    ~Ebo();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Ebo;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_EBO_HPP___
