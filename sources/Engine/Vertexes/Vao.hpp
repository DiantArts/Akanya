/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** vaos
*/

#pragma once



// clang-format off

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// clang-format on



namespace engine {



class Vao {
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
