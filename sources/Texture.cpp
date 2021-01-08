/*
** EPITECH PROJECT, 2020
** sources/Texture
** File description:
** Optimise texture loading as allow textures to be used multiple times
*/

#include "Texture.hpp"

#include <unordered_map>



namespace {

class TextureMap {
public:
    using data       = std::shared_ptr<GLuint>;
    using internData = std::weak_ptr<GLuint>;
    using map        = std::unordered_map<std::string, internData>;
    using iterator   = map::iterator;

    TextureMap()
    {
        for (auto& elem : this->m_Map) {
            glDeleteTextures(1, elem.second.lock().get());
        }
    }

    data operator[](const std::string& filename)
    {
        {
            auto it { this->m_Map.find(filename) };
            if (it != this->m_Map.end()) {
                return it->second.lock();
            }
        }

        auto instance { std::make_shared<GLuint>() };
        auto it { this->m_Map.emplace(filename, instance).first };
        glGenTextures(1, instance.get());
        return instance;
    }

    data operator[](std::string&& filename)
    {
        {
            auto it { this->m_Map.find(filename) };
            if (it != this->m_Map.end()) {
                return it->second.lock();
            }
        }

        auto instance { std::make_shared<GLuint>() };
        auto it { this->m_Map.emplace(std::move(filename), instance).first };
        glGenTextures(1, instance.get());
        return instance;
    }



private:
    TextureMap::map m_Map;
};

TextureMap g_CachedTextures;

} // namespace



namespace engine {



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



} // namespace engine
