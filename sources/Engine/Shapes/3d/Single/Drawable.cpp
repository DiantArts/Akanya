/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Drawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Window.hpp"



namespace engine::shape3d::single {



Drawable::Drawable(engine::Shader&              shader,
                   const glm::vec3&             position,
                   const std::function<void()>& setAttributes,
                   const size_t                 numberOfTextures /* = 1 */)
    : engine::shape3d::Drawable(shader, setAttributes, numberOfTextures), m_Position(position)
{}

Drawable::~Drawable()
{}



// ---------------------------------------------------------------------------- Draw

void Drawable::draw(const engine::Camera& camera)
{
    this->m_TextureVector.bindThemAll();
    this->getShader().use();

    this->setAllIntoShader(camera);
    this->getShader().set("view", camera.getView());
    this->getShader().set("projection",
                          glm::perspective(glm::radians(camera.getZoom()),
                                           (float)Window::width / (float)Window::height, 0.1F, 100.0F));

    this->m_Vao.bind();
    this->getShader().set("model", glm::scale(this->getModel(this->m_Position), this->m_Scale));
    glDrawArrays(GL_TRIANGLES, 0, this->getNumberOfArrayToDraw());
}



// ---------------------------------------------------------------------------- Position

void Drawable::setPosition(float positionX /* = 0 */, float positionY /* = 0 */, float positionZ /* = 0 */)
{
    this->m_Position.x = positionX;
    this->m_Position.y = positionY;
    this->m_Position.z = positionZ;
}

void Drawable::setPosition(const glm::vec3& position)
{
    this->m_Position = position;
}

void Drawable::setPosition(glm::vec3&& position)
{
    this->m_Position = std::move(position);
}

const glm::vec3& Drawable::getPosition() const
{
    return this->m_Position;
}



} // namespace engine::shape3d::single
