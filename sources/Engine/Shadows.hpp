/*
** EPITECH PROJECT, 2020
** sources/Engine/Shadows
** File description:
** frst try of shadows
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___

#include "Actors/Vertexes/Fbo.hpp"
#include "Shader.hpp"



namespace engine {



class Shadows {
public:
    // ---------------------------------------------------------------------------- *structors
    Shadows(engine::Shader& shader);
    ~Shadows();


    // ---------------------------------------------------------------------------- SpaceMatrix
    void             generateSpaceMatrix(const glm::vec3& lightPosition) const;
    void             bindSpaceMatrix() const;
    const glm::mat4& getSpaceMatrix() const;


    // ---------------------------------------------------------------------------- Bindings
    void bind() const;
    void unbind() const;


public:
    constexpr static size_t width { 1024 };
    constexpr static size_t height { 1024 };


private:
    GLuint            m_Map;
    engine::Fbo       m_Fbo;
    engine::Shader&   m_Shader;
    mutable glm::mat4 m_SpaceMatrix;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SHADOWS_HPP___
