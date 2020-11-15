/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** vaos
*/

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

class Vao {
public:
    Vao();
    ~Vao();

    GLuint get() const;

    void bind() const;
    void unbind() const;

private:
    GLuint m_Vao;
};

} // namespace engine
