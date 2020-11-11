/*
** EPITECH PROJECT, 2020
** ModelMatrix
** File description:
** Model
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ModelMatrix.hpp"

namespace engine::shape3d {

ModelMatrix::ModelMatrix(const engine::Shader& shaderProgram)
    : m_ShaderProgram(shaderProgram)
{
    float vertices[] = {
        0.5f, 0.5f, 0.0f, // left
       -0.5f, 0.5f, 0.0f, // right
        0.0f, -0.5f, 0.0f  // top
    };

    this->m_Vao.bind();
    this->m_Vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void ModelMatrix::draw()
{
    this->m_ShaderProgram.use();
    this->transform();
    this->m_ShaderProgram.use();
    this->m_Vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void ModelMatrix::transform()
{
    glm::mat4 model         = glm::mat4(1.0f);
    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);

    model = glm::rotate(model, glm::radians(-75.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), 1920.0f / 1080.0f, 0.1f, 100.0f);

    // retrieve the matrix uniform locations
    unsigned int modelLoc = glGetUniformLocation(this->m_ShaderProgram.get(), "model");
    unsigned int viewLoc  = glGetUniformLocation(this->m_ShaderProgram.get(), "view");

    // pass them to the shaders (3 different ways)
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

    // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    this->m_ShaderProgram.set("projection", projection);
}

} // namespace engine::shape3d
