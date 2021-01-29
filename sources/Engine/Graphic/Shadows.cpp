//
// Akanya, Engine
// sources/Engine/Shadows
// frst try of shadows
//

#include "pch.hpp"

#include "Shadows.hpp"

const glm::mat4* shadowsSpaceMatrix;



namespace engine {



// ---------------------------------- *structors

Shadows::Shadows(::engine::graphic::opengl::Shader& shader) : m_shader(shader)
{
    glGenTextures(1, &m_map);
    glBindTexture(GL_TEXTURE_2D, m_map);
    for (auto i { 0 }; i < 6; ++i) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, this->width, this->height,
                     0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    m_fbo.bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_map, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Shadows::~Shadows()
{}



// ---------------------------------- SpaceMatrix

void Shadows::generateSpaceMatrix(const glm::vec3& lightPosition) const
{
    glm::mat4 lightProjection, lightView;
    float     near_plane = 1.0F, far_plane = 7.5F;
    lightProjection    = glm::ortho(-10.0F, 10.0F, -10.0F, 10.0F, near_plane, far_plane);
    lightView          = glm::lookAt(lightPosition, glm::vec3(0.0F), glm::vec3(0.0F, 1.0F, 0.0F));
    m_spaceMatrix      = lightProjection * lightView;
    shadowsSpaceMatrix = &m_spaceMatrix;
}

void Shadows::bindSpaceMatrix() const
{
    m_shader.use();
    m_shader.set("lightSpaceMatrix", m_spaceMatrix);
}

const glm::mat4& Shadows::getSpaceMatrix() const
{
    return m_spaceMatrix;
}



// ---------------------------------- Bindings

void Shadows::bind() const
{
    glViewport(0, 0, this->width, this->height);
    m_fbo.bind();
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Shadows::unbind() const
{
    m_fbo.unbind();
    glViewport(0, 0, this->width, this->height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


} // namespace engine
