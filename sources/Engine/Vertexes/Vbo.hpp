/*
** EPITECH PROJECT, 2020
** Vbo
** File description:
** Vbo
*/

#pragma once



// clang-format off

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// clang-format on



namespace engine {



class Vbo {
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
