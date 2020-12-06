/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Drawable.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../Window.hpp"



namespace engine::shape3d {



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



// ---------------------------------------------------------------------------- Textures

void Drawable::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}


const engine::container::vector::Texture& Drawable::getTextures() const
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
    return this->m_Shader.get();
}

engine::Shader& Drawable::getShader()
{
    return this->m_Shader.get();
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



} // namespace engine::shape3d
