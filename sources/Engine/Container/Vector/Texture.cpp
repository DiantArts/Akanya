/*
** EPITECH PROJECT, 2020
** Texture
** File description:
** Texture
*/

#include "../../Filepaths.hpp"

// clang-format off

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// clang-format on

#include <iostream>

#include <stb/stb_image.h>
#include "../../Shader.hpp"
#include "Texture.hpp"



namespace engine::container::vector {



// ---------------------------------------------------------------------------- *structor

Texture::Texture(engine::Shader& shader, size_t sizeToAlloc) : m_Shader(shader)
{
    this->reserve(sizeToAlloc);
}



// ---------------------------------------------------------------------------- bind

void Texture::bindThemAll()
{
    auto enumValue { GL_TEXTURE0 };
    for (const auto& texture : this->m_Texture) {
        glActiveTexture(enumValue++);
        glBindTexture(GL_TEXTURE_2D, texture);
    }
}

void Texture::unbindThemAll()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}



// ---------------------------------------------------------------------------- std::vector things
void Texture::reserve(size_t size)
{
    this->m_Texture.reserve(size);
}

void Texture::push_back(const std::string_view textureFileName, const std::string_view name, const int value)
{
    std::string textureFilepath;
    textureFilepath.reserve(engine::filepath::textures.size() + textureFileName.size());
    textureFilepath += engine::filepath::textures;
    textureFilepath += textureFileName;

    int                        width, height, nrComponents;
    const unsigned char* const data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1: format = GL_RED; break;
        case 3: format = GL_RGB; break;
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
    stbi_image_free(const_cast<unsigned char*>(data));

    this->m_Shader.use();
    this->m_Shader.set(std::string { name }, value);
}



std::vector<GLuint>::iterator Texture::begin()
{
    return this->m_Texture.begin();
}

std::vector<GLuint>::iterator Texture::end()
{
    return this->m_Texture.end();
}

std::vector<GLuint>::const_iterator Texture::begin() const
{
    return this->m_Texture.begin();
}

std::vector<GLuint>::const_iterator Texture::end() const
{
    return this->m_Texture.end();
}

std::vector<GLuint>::const_iterator Texture::cbegin() const
{
    return this->m_Texture.cbegin();
}

std::vector<GLuint>::const_iterator Texture::cend() const
{
    return this->m_Texture.cend();
}



} // namespace engine::container::vector
