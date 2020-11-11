/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Rectangle.hpp"
#include "debugMacros.hpp"

int getShaderProgram();

namespace engine {

Rectangle::Rectangle(engine::Shader &shaderProgram)
    : m_shaderProgram(shaderProgram)
{
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
       -0.5f, -0.5f, 0.0f,  // bottom left
       -0.5f,  0.5f, 0.0f,  // top left
    };
    unsigned indices[] = {
        0, 1, 3,
        1, 2, 3,
    };

    glGenBuffers(1, &this->m_ebo);
    glGenBuffers(1, &this->m_vbo);

    this->m_vao.bind();

    // copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered
    // VBO as the vertex attribute's bound vertex buffer object so afterwards
    // we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally
    // modify this VAO, but this rarely happens. Modifying other VAOs requires
    // a call to glBindVertexArray anyways so we generally don't unbind VAOs
    // (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);

    DEBUG_MSG("Rectangle created");
}

Rectangle::~Rectangle()
{
    glDeleteBuffers(1, &this->m_ebo);
    DEBUG_MSG("Rectangle destroyed");
}

void Rectangle::draw()
{
    this->m_shaderProgram.use();
    this->m_vao.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    this->m_vao.unbind();
}

} // namespace engine
