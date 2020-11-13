/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Engine/Vertexes/Vertices.hpp" // std::string_view
#include "Engine/Shader.hpp"            // glad.h, glm.h
#include "Engine/Window.hpp"            // glad.h, glfw3.h, engine::Camera
#include "Cube.hpp"                     // std::vector

namespace engine::shape3d {

Cube::Cube(engine::Shader &shaderProgram)
    : m_Shader(shaderProgram), m_Textures(this->m_Shader, 2)
{
    this->m_Positions = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    engine::Vertices("data/vertices/cube").createBuffer();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->m_Textures.push_back("data/textures/wall.jpg", "texture1", 0);
    this->m_Textures.push_back("data/textures/awesomeface.png", "texture2", 1);
}

Cube::~Cube()
{}

void Cube::addPosition(float x /* = 0 */, float y /* = 0 */, float z /* = 0 */)
{
    this->m_Positions.push_back(glm::vec3(x, y, z));
}
void Cube::addPosition(glm::vec3& vec)
{
    this->m_Positions.push_back(vec);
}

void Cube::draw(const engine::Camera& camera)
{
    this->m_Textures.bindThemAll();
    this->m_Shader.use();

    this->m_Shader.set("view", camera.getView());
    this->m_Shader.set("projection", glm::perspective(glm::radians(camera.zoom),
                (float)Window::width / (float)Window::height, 0.1f, 100.0f));

    this->m_Vao.bind();

    float rotation = 0.0f;
    for (const auto& position : this->m_Positions) {
        auto model = glm::rotate(glm::translate(glm::mat4(1.0f), position), glm::radians(rotation += 20.0f),
                    glm::vec3(1.0f, 0.3f, 0.5f));
        this->m_Shader.set("model", model);
        glDrawArrays(GL_TRIANGLES, 0, this->numberOfArrayToDraw);
    }
}

} // namespace engine::shape3d
