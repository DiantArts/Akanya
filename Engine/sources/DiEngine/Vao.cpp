/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** s
*/

#include <glad/glad.h>
#include "Vao.hpp"

namespace DiEngine {

Vao::Vao() noexcept
{
    glGenVertexArrays(1, &this->m_vao);
}

Vao::~Vao() noexcept
{
    glDeleteVertexArrays(1, &this->m_vao);
}

GLuint Vao::get() const noexcept
{
    return this->m_vao;
}

void Vao::bind() noexcept
{
    glBindVertexArray(this->m_vao);
}

void Vao::unbind() noexcept
{
    glBindVertexArray(0);
}

} // namespace DiEngine
