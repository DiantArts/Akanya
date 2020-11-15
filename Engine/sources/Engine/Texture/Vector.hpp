/*
** EPITECH PROJECT, 2020
** TextureVector
** File description:
** TextureVector
*/

#pragma once

#include <glad/glad.h>
#include <vector>
#include <string_view>

namespace engine {

class Shader;

namespace texture {

class Vector {
public:
    Vector(engine::Shader& shader, size_t sizeToAlloc);
    ~Vector();

    void bindThemAll();
    void unbindThemAll();

// ---------------------------------------------------------------------------- std::vector things
    void reserve(size_t size);
    void push_back(const std::string_view textureFileName, const std::string_view name, int val);
    std::vector<GLuint>::const_iterator cbegin() const;
    std::vector<GLuint>::const_iterator cend() const;
    std::vector<GLuint>::iterator begin();
    std::vector<GLuint>::iterator end();

private:
    bool endsWith(const std::string_view a, const std::string_view b);

private:
    std::vector<GLuint> m_Texture; // possible that cannot contain more than 42 textures
    engine::Shader& m_Shader;
};

constexpr auto directoryPath = "./data/textures/";

} // namespace texture
} // namespace engine
