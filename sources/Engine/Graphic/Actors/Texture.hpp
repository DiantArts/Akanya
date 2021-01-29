//
// Akanya, Engine
// sources/Texture
// Optimise texture loading as allow textures to be used multiple times
//

#ifndef ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___
#define ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___

namespace engine::graphic::actor {



class Texture {
public:
    // ---------------------------------- *structors
    Texture(const std::string& filename);
    Texture(std::string&& filename);
    ~Texture();


    // ---------------------------------- bind
    GLuint get() const;


public: // TODO: tmp
    std::shared_ptr<GLuint> m_id;
};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___
