/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glm/gtc/matrix_transform.hpp> // glm::perspective, glm::rotate, glm:::translate
#include "Engine/Window.hpp"            // glad.h, glfw3.h, engine::Camera
#include "Drawable.hpp"                 // std::vector

namespace engine::shape3d {

Drawable::Drawable(engine::Shader& shader, size_t numberOfTextures /* = 1 */)
    : m_Shader(shader), m_TextureVector(shader, numberOfTextures)
{
    this->m_Vbo.bind();
    this->m_Vao.bind();
}

Drawable::~Drawable()
{}

void Drawable::changeShader(engine::Shader& shader)
{
    this->m_Shader = shader;
}

void Drawable::addPosition(float x /* = 0 */, float y /* = 0 */, float z /* = 0 */)
{
    this->m_Positions.push_back(glm::vec3(x, y, z));
}

void Drawable::addPosition(glm::vec3 vec)
{
    this->m_Positions.push_back(std::move(vec));
}

void Drawable::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}

void Drawable::draw(const engine::Camera& camera)
{
    this->m_TextureVector.bindThemAll();
    this->m_Shader.use();

    this->setAllIntoShader();
    this->m_Shader.set("view", camera.getView());
    this->m_Shader.set("projection", glm::perspective(glm::radians(camera.zoom),
                (float)Window::width / (float)Window::height, 0.1f, 100.0f));

    this->m_Vao.bind();

    float rotation = 140.0f;
    for (const auto& position : this->m_Positions) {
        auto model = glm::rotate(glm::translate(glm::mat4(1.0f), position), glm::radians(rotation += 20.0f),
                    glm::vec3(1.0f, 0.3f, 0.5f));
        this->m_Shader.set("model", model);
        glDrawArrays(GL_TRIANGLES, 0, this->numberOfArrayToDraw);
    }
}

} // namespace engine::shape3d
