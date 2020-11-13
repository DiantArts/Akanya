/*
** EPITECH PROJECT, 2020
** Texture
** File description:
** Texture
*/

#include <glad/glad.h>       // GLuint, glBindTexture(), glTexParameteri
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>   // stbi_load(), stdbi_image_free()
#include <iostream>          // std::clog
#include "Engine/Shader.hpp"
#include "Texture.hpp"       // std::string_view, std::vector

namespace engine {

Texture::Texture(engine::Shader& shader, size_t sizeToAlloc)
    : m_Shader(shader)
{
    this->reserve(sizeToAlloc);
}

Texture::~Texture()
{}

void Texture::bindThemAll()
{
    auto enumValue = GL_TEXTURE0;
    for (const auto& texture : this->m_Texture) {
        glActiveTexture(enumValue);
        glBindTexture(GL_TEXTURE_2D, texture);
        enumValue++;
    }
}

// ---------------------------------------------------------------------------- std::vector things
void Texture::reserve(size_t size)
{
    this->m_Texture.reserve(size);
}

void Texture::push_back(const std::string_view filepath, const std::string_view name, int value)
{
    this->m_Texture.emplace_back();
    glGenTextures(1, &this->m_Texture.back());

    glBindTexture(GL_TEXTURE_2D, this->m_Texture.back());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(std::string(filepath).c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                (this->endsWith(filepath, ".png") ? GL_RGBA : GL_RGB), GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::clog << "ERROR: Failed to load '" << filepath << "' texture\n";
    }
    stbi_image_free(data);

    this->m_Shader.use();
    this->m_Shader.set(name, value);
}

std::vector<GLuint>::const_iterator Texture::cbegin() const
{
    return this->m_Texture.cbegin();
}

std::vector<GLuint>::const_iterator Texture::cend() const
{
    return this->m_Texture.cend();
}

std::vector<GLuint>::iterator Texture::begin()
{
    return this->m_Texture.begin();
}

std::vector<GLuint>::iterator Texture::end()
{
    return this->m_Texture.end();
}

// ---------------------------------------------------------------------------- private

bool Texture::endsWith(const std::string_view a, const std::string_view b)
{
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}

} // namespace engine
