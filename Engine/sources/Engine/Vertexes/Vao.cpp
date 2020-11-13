/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** s
*/

#include "Vao.hpp"

namespace engine {

Vao::Vao()
{
    glGenVertexArrays(1, &this->m_Vao);
    this->bind();
}

Vao::~Vao()
{
    glDeleteVertexArrays(1, &this->m_Vao);
}

GLuint Vao::get() const
{
    return this->m_Vao;
}

void Vao::bind()
{
    glBindVertexArray(this->m_Vao);
}

void Vao::unbind()
{
    glBindVertexArray(0);
}

} // namespace engine
