/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Ebo
** File description:
** Element Buffer Object: help to determine which vertex to draw
*/

#include "Ebo.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Ebo::Ebo()
{
    glGenBuffers(1, &this->m_Ebo);
}

Ebo::~Ebo()
{
    glDeleteBuffers(1, &this->m_Ebo);
}



// ---------------------------------------------------------------------------- get

GLuint Ebo::get() const
{
    return this->m_Ebo;
}



// ---------------------------------------------------------------------------- bind

void Ebo::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_Ebo);
}

void Ebo::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}



} // namespace engine
