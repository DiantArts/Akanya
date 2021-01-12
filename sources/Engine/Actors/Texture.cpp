/*
** EPITECH PROJECT, 2020
** sources/Texture
** File description:
** Optimise texture loading as allow textures to be used multiple times
*/

#include "Texture.hpp"
#include <iostream>

#include <unordered_map>



namespace {

class TextureContainer {
public:
    using DataType   = GLuint;
    using DataPtr    = std::shared_ptr<DataType>;
    using InternData = std::weak_ptr<DataType>;
    using Map        = std::unordered_map<std::string, InternData>;
    using iterator   = Map::iterator;

    DataPtr operator[](const std::string& filename)
    {
        {
            auto it { this->m_Map.find(filename) };
            if (it != this->m_Map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance( new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            this->m_Map.erase(filename);
        });
        this->m_Map.emplace(filename, instance);
        glGenTextures(1, instance.get());
        return instance;
    }

    DataPtr operator[](std::string&& filename)
    {
        {
            auto it { this->m_Map.find(filename) };
            if (it != this->m_Map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance( new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            this->m_Map.erase(filename);
        });
        this->m_Map.emplace(std::move(filename), instance);
        glGenTextures(1, instance.get());
        return instance;
    }


private:
    TextureContainer::Map m_Map;
};

TextureContainer g_CachedTextures;

} // namespace



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

Texture::Texture(const std::string& filename)
    : m_Id(g_CachedTextures[filename])
{}

Texture::Texture(std::string&& filename)
    : m_Id(g_CachedTextures[std::move(filename)])
{}

Texture::~Texture()
{}



GLuint Texture::get() const
{
    return *this->m_Id;
}



} // namespace engine::actor
