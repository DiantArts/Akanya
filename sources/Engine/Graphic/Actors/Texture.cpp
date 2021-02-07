//
// Akanya, Engine
// sources/Texture
// Optimise texture loading as allow textures to be used multiple times
//

#include "pch.hpp"

#include "Texture.hpp"



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
            auto it { m_map.find(filename) };
            if (it != m_map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance( new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            m_map.erase(filename);
        });
        m_map.emplace(filename, instance);
        glGenTextures(1, instance.get());
        return instance;
    }

    DataPtr operator[](std::string&& filename)
    {
        {
            auto it { m_map.find(filename) };
            if (it != m_map.end()) {
                return it->second.lock();
            }
        }

        DataPtr instance( new DataType, [this, filename](DataType* id) {
            glDeleteTextures(1, id);
            delete id;
            m_map.erase(filename);
        });
        m_map.emplace(std::move(filename), instance);
        glGenTextures(1, instance.get());
        return instance;
    }


private:
    TextureContainer::Map m_map;
};

TextureContainer g_CachedTextures;

} // namespace



// ---------------------------------- *structors

::engine::graphic::actor::Texture::Texture(const std::string& filename)
    : m_id(g_CachedTextures[filename])
{}

::engine::graphic::actor::Texture::Texture(std::string&& filename)
    : m_id(g_CachedTextures[std::move(filename)])
{}

::engine::graphic::actor::Texture::~Texture() = default;



// ---------------------------------- Copy sementic

::engine::graphic::actor::Texture::Texture(
    const Texture&
) noexcept = default;

auto ::engine::graphic::actor::Texture::operator=(
    const Texture&
) noexcept -> Texture& = default;



// ---------------------------------- Move sementic

::engine::graphic::actor::Texture::Texture(
    Texture&&
) noexcept = default;

auto ::engine::graphic::actor::Texture::operator=(
    Texture&&
) noexcept -> Texture& = default;



// ---------------------------------- Get

GLuint ::engine::graphic::actor::Texture::get() const
{
    return *m_id;
}
