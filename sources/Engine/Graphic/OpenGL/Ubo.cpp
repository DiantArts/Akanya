//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Ubo
// Uniform Buffer Object : Share memory with multiple shaders
//

#include "pch.hpp"

#include "Ubo.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Ubo::Ubo(
    size_t size,
    int index
)
    : m_size(size)
{
    glGenBuffers(1, &m_ubo);

    this->bind();
    glBufferData(GL_UNIFORM_BUFFER, m_size, nullptr, GL_DYNAMIC_DRAW);
    this->unbind();

    glBindBufferRange(GL_UNIFORM_BUFFER, index, m_ubo, 0, m_size);
}

Ubo::~Ubo()
{
    glDeleteBuffers(1, &m_ubo);
}



// ---------------------------------- get

GLuint Ubo::get() const
{
    return m_ubo;
}



// ---------------------------------- bind

void Ubo::bind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_ubo);
}

void Ubo::unbind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}



} // namespace engine::graphic::opengl
