/*
** EPITECH PROJECT, 2020
** sources/Engine/Shadows
** File description:
** frst try of shadows
*/

#include "Shadows.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Shadows::Shadows(engine::Shader& shader)
    : m_Shader(shader)
{
    glGenTextures(1, &m_Map);
    glBindTexture(GL_TEXTURE_2D, m_Map);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->width, this->height, 0, GL_DEPTH_COMPONENT,
                 GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    m_Fbo.bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_Map, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Shadows::~Shadows()
{}



// ---------------------------------------------------------------------------- Bindings

void Shadows::bind(glm::vec3& lightPosition) const
{
    glm::mat4 lightProjection, lightView;
    glm::mat4 lightSpaceMatrix;
    float near_plane = 1.0f, far_plane = 7.5f;
    lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    lightView = glm::lookAt(lightPosition, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
    lightSpaceMatrix = lightProjection * lightView;
    m_Shader.use();
    m_Shader.set("lightSpaceMatrix", lightSpaceMatrix);

    glViewport(0, 0, this->width, this->height);
    m_Fbo.bind();
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Shadows::unbind() const
{
    m_Fbo.unbind();
}


} // namespace engine
