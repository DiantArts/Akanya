/*
** EPITECH PROJECT, 2020
** sources/Engine/Shadow
** File description:
** first try of shadows
*/

#include "Shadow.hpp"


// ---------------------------------------------------------------------------- *structors

Shadow::Shadow()
{
    glGenTextures(1, &this->m_Map);
    glBindTexture(GL_TEXTURE_2D, this->m_Map);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->width, this->height, 0, GL_DEPTH_COMPONENT,
                 GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, this->m_Fbo.get());
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, this->m_Map, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Shadow::~Shadow()
{}

void Shadow::draw() const
{
    // glViewport(0, 0, this->width, this-height);
    // glBindFramebuffer(GL_FRAMEBUFFER, this->m_Fbo.get());
    // glClear(GL_DEPTH_BUFFER_BIT);
    // ConfigureShaderAndMatrices();
    // RenderScene();
    // glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
