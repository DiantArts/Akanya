/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Drawable
** File description:
** Drawable
*/

#include "Drawable.hpp"

namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Drawable::Drawable(engine::Shader&              shader,
                   const std::function<void()>& setAttributes,
                   const size_t                 numberOfTextures)
    : m_Shader(shader), m_TextureVector(shader, numberOfTextures)
{
    this->m_Vbo.bind();
    this->m_Vao.bind();
    setAttributes();
}

Drawable::~Drawable()
{}



// ---------------------------------------------------------------------------- Draw
void Drawable::draw(const engine::Camera& camera) const
{
    this->m_TextureVector.bindThemAll();
    this->getShader().use();

    this->transformShape(camera);

    this->m_Vao.bind();
    this->drawModels();
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



// ---------------------------------------------------------------------------- Textures

void Drawable::addTexture(const std::string_view filepath, const std::string_view name, int index)
{
    this->m_TextureVector.push_back(filepath, name, index);
}


const engine::container::vector::Texture& Drawable::getTextures() const
{
    return this->m_TextureVector;
}



} // namespace engine::graphic
