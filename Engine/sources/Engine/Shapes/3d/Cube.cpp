/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <stb/stb_image.h>
#include "Engine/Window.hpp"
#include "debugMacros.hpp"
#include "Cube.hpp"

namespace engine::shape3d {

Cube::Cube(engine::Shader &shaderProgram)
    : m_Shader(shaderProgram)
{
    float vertices[] = {
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

       -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    cubePositions[0] = glm::vec3( 0.0f,  0.0f,  0.0f);
    cubePositions[1] = glm::vec3( 2.0f,  5.0f, -15.0f);
    cubePositions[2] = glm::vec3(-1.5f, -2.2f, -2.5f);
    cubePositions[3] = glm::vec3(-3.8f, -2.0f, -12.3f);
    cubePositions[4] = glm::vec3( 2.4f, -0.4f, -3.5f);
    cubePositions[5] = glm::vec3(-1.7f,  3.0f, -7.5f);
    cubePositions[6] = glm::vec3( 1.3f, -2.0f, -2.5f);
    cubePositions[7] = glm::vec3( 1.5f,  2.0f, -2.5f);
    cubePositions[8] = glm::vec3( 1.5f,  0.2f, -1.5f);
    cubePositions[9] = glm::vec3(-1.3f,  1.0f, -1.5f);

    this->m_Vao.bind();

    this->m_Vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->m_Texture1 = this->genTexture("data/textures/wall.jpg");
    this->m_Texture2 = this->genTexture("data/textures/awesomeface.png", true);

    this->m_Shader.use();
    this->m_Shader.set("texture1", 0);
    this->m_Shader.set("texture2", 1);

    this->m_Shader.set("projection", glm::perspective(glm::radians(45.0f),
                (float)Window::width / (float)Window::height, 0.1f, 100.0f));
}

Cube::~Cube()
{}

void Cube::draw(const engine::Camera& camera)
{
    this->bindTextures();
    this->m_Shader.use();
    this->m_Shader.set("view", camera.getView());
    this->m_Vao.bind();
    this->transform();
    // glDrawArrays(GL_TRIANGLES, 0, 36);

    for (unsigned int i = 0; i < 10; i++) {
        this->m_Shader.set("model", glm::rotate(glm::translate(glm::mat4(1.0f), cubePositions[i]),
                    glm::radians(20.0f * i),
                    glm::vec3(1.0f, 0.3f, 0.5f)));
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}

void Cube::transform()
{
    // glUniformMatrix4fv(glGetUniformLocation(this->m_Shader.get(), "model"), 1, GL_FALSE,
            // glm::value_ptr(glm::rotate(glm::mat4(1.0f), 0.5f, glm::vec3(0.5f, 1.0f, 0.0f))));

    // auto view  = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    // glUniformMatrix4fv(glGetUniformLocation(this->m_Shader.get(), "view"), 1, GL_FALSE, &view[0][0]);
}

void Cube::bindTextures()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->m_Texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, this->m_Texture2);
}


GLuint Cube::genTexture(char const * const filepath, bool isRGBA)
{
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, (isRGBA ? GL_RGBA : GL_RGB),
                GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        ERROR_MSG("Faled to load texture");
    }
    stbi_image_free(data);

    return texture;
}

} // namespace engine::shape3d
