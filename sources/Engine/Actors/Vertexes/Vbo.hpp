/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vbo
** File description:
** Vertex Buffer Object: stores a large number of vertices
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VBO_HPP___

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../NonCopyable.hpp"



namespace engine {



class Vbo : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- *structors
    Vbo();
    ~Vbo();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Vbo;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VBO_HPP___
