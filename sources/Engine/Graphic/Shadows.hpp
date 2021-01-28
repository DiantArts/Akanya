/*
** Akanya, Engine
** sources/Engine/Shadows
** frst try of shadows
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___

#include "OpenGL/Fbo.hpp"
#include "OpenGL/Shader.hpp"



namespace engine {



class Shadows {
public:
    // ---------------------------------- *structors
    Shadows(
        ::engine::graphic::opengl::Shader& shader
    );
    ~Shadows();


    // ---------------------------------- SpaceMatrix
    void             generateSpaceMatrix(
        const glm::vec3& lightPosition
    ) const;
    void             bindSpaceMatrix() const;
    const glm::mat4& getSpaceMatrix() const;


    // ---------------------------------- Bindings
    void bind() const;
    void unbind() const;


public:
    constexpr static size_t width { 1024 };
    constexpr static size_t height { 1024 };


private:
    GLuint            m_map;
    ::engine::graphic::opengl::Fbo       m_fbo;
    ::engine::graphic::opengl::Shader&   m_shader;
    mutable glm::mat4 m_spaceMatrix;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___