/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Fbo
** File description:
** FrameBuffer Object
*/

#include "Fbo.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Fbo::Fbo()
{
    glGenFramebuffers(1, &this->m_Fbo);
}

Fbo::~Fbo()
{
    glDeleteFramebuffers(1, &this->m_Fbo);
}



// ---------------------------------------------------------------------------- get

GLuint Fbo::get() const
{
    return this->m_Fbo;
}



// ---------------------------------------------------------------------------- bind

void Fbo::bind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, this->m_Fbo);
}

void Fbo::unbind() const
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}



} // namespace engine
