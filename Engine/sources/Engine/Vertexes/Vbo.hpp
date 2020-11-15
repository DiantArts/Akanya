/*
** EPITECH PROJECT, 2020
** Vbo
** File description:
** Vbo
*/

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

class Vbo {
public:
    Vbo();
    ~Vbo();

    GLuint get();

    void bind() const;
    void unbind() const;

private:
    GLuint m_Vbo;
};

} // namespace engine
