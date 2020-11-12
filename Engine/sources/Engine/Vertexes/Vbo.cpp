/*
** EPITECH PROJECT, 2020
** Vbo
** File description:
** Vbo
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Vbo.hpp"

namespace engine {

Vbo::Vbo()
{
    glGenBuffers(1, &this->m_Vbo);
    this->bind();
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &this->m_Vbo);
}

GLuint Vbo::get()
{
    return this->m_Vbo;
}

void Vbo::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, this->m_Vbo);
}

} // namespace engine
