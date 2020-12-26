/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vao
** File description:
** Vertex Array Object: Contains vertex attributes pointers to get a simple use of VBOs
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "../../NonCopyable.hpp"



namespace engine {



class Vao : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- *structors
    Vao();
    ~Vao();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Vao;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___
