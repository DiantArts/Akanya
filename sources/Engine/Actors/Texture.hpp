/*
** EPITECH PROJECT, 2020
** sources/Texture
** File description:
** Optimise texture loading as allow textures to be used multiple times
*/

#ifndef ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___
#define ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___

#include <string>
#include <memory>

#include <glad/glad.h>


namespace engine::actor {



class Texture {
public:
    // ---------------------------------------------------------------------------- *structors
    Texture(const std::string& filename);
    Texture(std::string&& filename);
    ~Texture();


    // ---------------------------------------------------------------------------- bind
    GLuint get() const;


public: // TODO: tmp
    std::shared_ptr<GLuint> m_Id;
};



} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_TEXTURE_HPP___
