/*
** EPITECH PROJECT, 2020
** sources/Engine/Container/Vector/Texture
** File description:
** TextureVector
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_VECTOR_TEXTURE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_VECTOR_TEXTURE_HPP___

#include <string_view>
#include <vector>

#include <glad/glad.h>



namespace engine {

class Shader;



namespace container::vector {



class Texture {
public:
    // ---------------------------------------------------------------------------- *structor
    explicit Texture(engine::Shader& shader, size_t sizeToAlloc);
    ~Texture() = default;


    // ---------------------------------------------------------------------------- bind
    void bindThemAll() const;
    void unbindThemAll() const;


    // ---------------------------------------------------------------------------- std::vector things
    void reserve(size_t size);
    void push_back(const std::string_view textureFileName, const std::string_view name, int val);

    std::vector<GLuint>::iterator begin();
    std::vector<GLuint>::iterator end();

    std::vector<GLuint>::const_iterator begin() const;
    std::vector<GLuint>::const_iterator end() const;

    std::vector<GLuint>::const_iterator cbegin() const;
    std::vector<GLuint>::const_iterator cend() const;

private:
    std::vector<GLuint> m_Texture; // possible that cannot contain more than 42 textures
    engine::Shader&     m_Shader;
};



} // namespace container::vector
} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_VECTOR_TEXTURE_HPP___
