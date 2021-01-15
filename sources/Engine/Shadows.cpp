/*
** EPITECH PROJECT, 2020
** sources/Engine/Shadows
** File description:
** frst try of shadows
*/

#include "Shadows.hpp"

#include <glm/gtc/matrix_transform.hpp>

const glm::mat4* shadowsSpaceMatrix;



namespace engine {



// ---------------------------------------------------------------------------- *structors

Shadows::Shadows(engine::Shader& shader) : m_Shader(shader)
{
    glGenTextures(1, &m_Map);
    glBindTexture(GL_TEXTURE_2D, m_Map);
    for (auto i { 0 }; i < 6; ++i) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, this->width, this->height,
                     0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    m_Fbo.bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_Map, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Shadows::~Shadows()
{}



// ---------------------------------------------------------------------------- SpaceMatrix

void Shadows::generateSpaceMatrix(const glm::vec3& lightPosition) const
{
    glm::mat4 lightProjection, lightView;
    float     near_plane = 1.0F, far_plane = 7.5F;
    lightProjection    = glm::ortho(-10.0F, 10.0F, -10.0F, 10.0F, near_plane, far_plane);
    lightView          = glm::lookAt(lightPosition, glm::vec3(0.0F), glm::vec3(0.0F, 1.0F, 0.0F));
    m_SpaceMatrix      = lightProjection * lightView;
    shadowsSpaceMatrix = &m_SpaceMatrix;
}

void Shadows::bindSpaceMatrix() const
{
    m_Shader.use();
    m_Shader.set("lightSpaceMatrix", m_SpaceMatrix);
}

const glm::mat4& Shadows::getSpaceMatrix() const
{
    return m_SpaceMatrix;
}



// ---------------------------------------------------------------------------- Bindings

void Shadows::bind() const
{
    glViewport(0, 0, this->width, this->height);
    m_Fbo.bind();
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Shadows::unbind() const
{
    m_Fbo.unbind();
    glViewport(0, 0, this->width, this->height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, this->width, this->height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


} // namespace engine
