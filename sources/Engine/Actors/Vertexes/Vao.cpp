/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vao
** File description:
** Vertex Array Object: Contains vertex attributes pointers to get a simple use of VBOs
*/

#include "Vao.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Vao::Vao()
{
    glGenVertexArrays(1, &this->m_Vao);
}

Vao::~Vao()
{
    glDeleteVertexArrays(1, &this->m_Vao);
}



// ---------------------------------------------------------------------------- get

GLuint Vao::get() const
{
    return this->m_Vao;
}



// ---------------------------------------------------------------------------- bind

void Vao::bind() const
{
    glBindVertexArray(this->m_Vao);
}

void Vao::unbind() const
{
    glBindVertexArray(0);
}



} // namespace engine
