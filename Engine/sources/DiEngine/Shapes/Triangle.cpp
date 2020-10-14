/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Triangle.hpp"
#include "debugMacros.hpp"

int getShaderProgram();

namespace DiEngine {

Triangle::Triangle(DiEngine::Shader &shaderProgram)
    : m_shaderProgram(shaderProgram)
{
    float vertices[] = {
        0.5f, -0.5f, 0.0f, // left
       -0.5f, -0.5f, 0.0f, // right
       -0.0f,  0.5f, 0.0f  // top
    };

    // float vertices[] = {
        // positions        // colors
        // 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
       // -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
        // 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
    // };

    glGenBuffers(1, &this->m_vbo);

    this->m_vao.bind();

    // copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // then set our vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

    // note that this is allowed, the call to glVertexAttribPointer registered
    // VBO as the vertex attribute's bound vertex buffer object so afterwards
    // we can safely unbind
    // glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally
    // modify this VAO, but this rarely happens. Modifying other VAOs requires
    // a call to glBindVertexArray anyways so we generally don't unbind VAOs
    // (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);

    this->m_vao.unbind();
    DEBUG_MSG("Triangle created");
}

Triangle::~Triangle()
{
    glDeleteBuffers(1, &this->m_vbo);
    DEBUG_MSG("Triangle destroyed");
}

void Triangle::draw()
{
    this->m_shaderProgram.use();
    this->m_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    this->m_vao.unbind();
}

} // namespace DiEngine
