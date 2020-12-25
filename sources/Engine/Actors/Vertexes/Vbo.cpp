/*
** EPITECH PROJECT, 2020
** Vbo
** File description:
** Vbo
*/

#include "Vbo.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Vbo::Vbo()
{
    glGenBuffers(1, &this->m_Vbo);
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &this->m_Vbo);
}



// ---------------------------------------------------------------------------- get

GLuint Vbo::get() const
{
    return this->m_Vbo;
}



// ---------------------------------------------------------------------------- bind

void Vbo::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, this->m_Vbo);
}

void Vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



} // namespace engine
