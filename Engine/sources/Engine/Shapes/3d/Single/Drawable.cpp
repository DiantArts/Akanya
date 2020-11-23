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
    : m_Shader(shader), m_Position(position), m_TextureVector(shader, numberOfTextures)
{
    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributes();
}

Drawable::~Drawable()
{}



// ---------------------------------------------------------------------------- Draw

void Drawable::draw(const engine::Camera& camera)
{
    this->m_TextureVector.bindThemAll();
    this->m_Shader.use();

    this->setAllIntoShader(camera);
    this->m_Shader.set("view", camera.getView());
    this->m_Shader.set("projection",
                       glm::perspective(glm::radians(camera.getZoom()),
                                        (float)Window::width / (float)Window::height, 0.1F, 100.0F));

    this->m_Vao.bind();
    this->m_Shader.set("model", glm::scale(this->getModel(this->m_Position), this->m_Scale));
    glDrawArrays(GL_TRIANGLES, 0, this->getNumberOfArrayToDraw());
}



// ---------------------------------------------------------------------------- Textures

void Drawable::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}


const engine::texture::Vector& Drawable::getTextures() const
{
    return this->m_TextureVector;
}



// ---------------------------------------------------------------------------- Shader

void Drawable::setShader(engine::Shader& shader)
{
    this->m_Shader = shader;
}


const engine::Shader& Drawable::getShader() const
{
    return this->m_Shader;
}



// ---------------------------------------------------------------------------- Scale

void Drawable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x = scaleX;
    this->m_Scale.y = scaleY;
    this->m_Scale.z = scaleZ;
}

void Drawable::setScale(const glm::vec3& scale)
{
    this->m_Scale = scale;
}

void Drawable::setScale(glm::vec3&& scale)
{
    this->m_Scale = std::move(scale);
}


const glm::vec3& Drawable::getScale() const
{
    return this->m_Scale;
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
