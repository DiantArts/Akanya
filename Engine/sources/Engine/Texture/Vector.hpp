/*
** EPITECH PROJECT, 2020
** TextureVector
** File description:
** TextureVector
*/

#pragma once



#include <string_view>
#include <vector>

#include <glad/glad.h>



namespace engine {

class Shader;



namespace texture {



class Vector {
public:
    // ---------------------------------------------------------------------------- *structor
    explicit Vector(engine::Shader& shader, size_t sizeToAlloc);
    ~Vector() = default;


    // ---------------------------------------------------------------------------- bind
    void bindThemAll();
    void unbindThemAll();


    // ---------------------------------------------------------------------------- std::vector things
    void reserve(size_t size);
    void push_back(const std::string_view textureFileName, const std::string_view name, int val);

    std::vector<GLuint>::const_iterator cbegin() const;
    std::vector<GLuint>::const_iterator cend() const;

    std::vector<GLuint>::iterator       begin();
    std::vector<GLuint>::iterator       end();

private:
    std::vector<GLuint> m_Texture; // possible that cannot contain more than 42 textures
    engine::Shader&     m_Shader;
};



constexpr auto directoryPath { "./data/textures/" };



} // namespace texture
} // namespace engine
