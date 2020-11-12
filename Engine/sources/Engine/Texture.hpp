/*
** EPITECH PROJECT, 2020
** Texture
** File description:
** Texture
*/

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <vector>
#include <string_view>

namespace engine {

class Shader;

class Texture {
public:
    Texture(engine::Shader& shader, size_t sizeToAlloc);
    ~Texture();

    void bindThemAll();

// ---------------------------------------------------------------------------- std::vector things
    void reserve(size_t size);
    void push_back(const std::string_view filepath, const std::string_view name, int val);
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

} // namespace engine

#endif // TEXTURE_HPP
