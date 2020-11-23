/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Drawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Window.hpp"



namespace engine::shape3d::multiple {



Drawable::Drawable(engine::Shader&              shader,
                   const std::function<void()>& setAttributes,
                   const size_t                 numberOfTextures /* = 1 */)
    : m_Shader(shader), m_TextureVector(shader, numberOfTextures)
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
    for (const auto& position : this->m_VectorPositions) {
        this->m_Shader.set("model", glm::scale(this->getModel(position), this->m_Scale));
        glDrawArrays(GL_TRIANGLES, 0, this->getNumberOfArrayToDraw());
    }
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



// ---------------------------------------------------------------------------- Positions

void Drawable::addPosition(float x /* = 0 */, float y /* = 0 */, float z /* = 0 */)
{
    this->m_VectorPositions.push_back(glm::vec3(x, y, z));
}

void Drawable::addPosition(glm::vec3 position)
{
    this->m_VectorPositions.push_back(std::move(position));
}


const std::vector<glm::vec3>& Drawable::getPosition() const
{
    return this->m_VectorPositions;
}



} // namespace engine::shape3d::multiple