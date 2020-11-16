/*
** EPITECH PROJECT, 2020
** Vector
** File description:
** Vector
*/

#include <glad/glad.h>               // GLuint, glBindTexture(), glTexParameteri
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>           // stbi_load(), stdbi_image_free()
#include <iostream>                  // std::clog
#include "Engine/Shader.hpp"
#include "Engine/Texture/Vector.hpp" // std::string_view, std::vector

namespace engine::texture {

Vector::Vector(engine::Shader& shader, size_t sizeToAlloc)
    : m_Shader(shader)
{
    this->reserve(sizeToAlloc);
}

Vector::~Vector()
{}

void Vector::bindThemAll()
{
    auto enumValue = GL_TEXTURE0;
    for (const auto& texture : this->m_Texture) {
        glActiveTexture(enumValue++);
        glBindTexture(GL_TEXTURE_2D, texture);
    }
}

void Vector::unbindThemAll()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

// ---------------------------------------------------------------------------- std::vector things
void Vector::reserve(size_t size)
{
    this->m_Texture.reserve(size);
}

void Vector::push_back(const std::string_view textureFileName, const std::string_view name, int value)
{
    int width, height, nrComponents;
    std::string textureFilepath(engine::texture::directoryPath); textureFilepath += textureFileName;
    unsigned char* data = stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0);
    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1: format = GL_RED;  break;
        case 3: format = GL_RGB;  break;
        default: format = GL_RGBA; break;
        }

        this->m_Texture.emplace_back();
        glGenTextures(1, &this->m_Texture.back());
        glBindTexture(GL_TEXTURE_2D, this->m_Texture.back());

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else {
        std::clog << "ERROR: Failed to load '" << textureFilepath << "' texture\n";
    }
    stbi_image_free(data);

    this->m_Shader.use();
    this->m_Shader.set(name, value);
}

std::vector<GLuint>::const_iterator Vector::cbegin() const
{
    return this->m_Texture.cbegin();
}

std::vector<GLuint>::const_iterator Vector::cend() const
{
    return this->m_Texture.cend();
}

std::vector<GLuint>::iterator Vector::begin()
{
    return this->m_Texture.begin();
}

std::vector<GLuint>::iterator Vector::end()
{
    return this->m_Texture.end();
}

// ---------------------------------------------------------------------------- private

bool Vector::endsWith(const std::string_view a, const std::string_view b)
{
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}

} // namespace engine::texture
