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

Vbo::Vbo(size_t size)
{
    glGenBuffers(size, &this->m_Vbo);
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &this->m_Vbo);
}

GLuint Vbo::get()
{
    return this->m_Vbo;
}

void Vbo::bind(GLenum target)
{
    glBindBuffer(target, this->m_Vbo);
}

} // namespace engine
