/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Fbo
** File description:
** FrameBuffer Object
*/

#include "pch.hpp"

#include "Fbo.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Fbo::Fbo()
{
    glGenFramebuffers(1, &m_Fbo);
}

Fbo::~Fbo()
{
    glDeleteFramebuffers(1, &m_Fbo);
}



// ---------------------------------------------------------------------------- get

GLuint Fbo::get() const
{
    return m_Fbo;
}



// ---------------------------------------------------------------------------- bind

void Fbo::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_Fbo);
}

void Fbo::unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



} // namespace engine
