/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Engine/Shader.hpp"
#include "Triangle.hpp"

int getShaderProgram();

namespace engine::shape2d {


    // this->m_Positions = {
        // glm::vec3( 0.0f,  0.0f,  0.0f),
        // glm::vec3( 2.0f,  5.0f, -15.0f),
        // glm::vec3(-1.5f, -2.2f, -2.5f),
        // glm::vec3(-3.8f, -2.0f, -12.3f),
        // glm::vec3( 2.4f, -0.4f, -3.5f),
        // glm::vec3(-1.7f,  3.0f, -7.5f),
        // glm::vec3( 1.3f, -2.0f, -2.5f),
        // glm::vec3( 1.5f,  2.0f, -2.5f),
        // glm::vec3( 1.5f,  0.2f, -1.5f),
        // glm::vec3(-1.3f,  1.0f, -1.5f)
    // };

Triangle::Triangle(const engine::Shader& shaderProgram)
    : m_ShaderProgram(shaderProgram)
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

    this->m_Vao.bind();

    // copy our vertices array in a buffer for OpenGL to use
    this->m_Vbo.bind();
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
}

void Triangle::draw()
{
    this->m_ShaderProgram.use();
    this->m_Vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    this->m_Vao.unbind();
}

} // namespace engine::shape2d
