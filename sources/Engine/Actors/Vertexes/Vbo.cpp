/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vbo
** File description:
** Vertex Buffer Object: stores a large number of vertices
*/

#include "Vbo.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Vbo::Vbo()
{
    glGenBuffers(1, &m_Vbo);
}

Vbo::~Vbo()
{
    glDeleteBuffers(1, &m_Vbo);
}



// ---------------------------------------------------------------------------- get

GLuint Vbo::get() const
{
    return m_Vbo;
}



// ---------------------------------------------------------------------------- bind

void Vbo::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
}

void Vbo::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



} // namespace engine
