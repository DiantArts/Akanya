/*
** EPITECH PROJECT, 2020
** sources/Engine/Shader
** File description:
** Controls graphic pipeline
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___

#include <string>
#include <string_view>
#include <unordered_map>

#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glad/glad.h>

#include "NonCopyable.hpp"



namespace engine {



class Shader : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- *structors
    Shader(std::string_view vertexPath, std::string_view fragmentPath);
    Shader(std::string_view filepathes);
    ~Shader();


    // ---------------------------------------------------------------------------- Use
    void use() const;


    // ---------------------------------------------------------------------------- Set
    void set(const std::string& name, bool value) const;
    void set(std::string&& name, bool value) const;

    void set(const std::string& name, int value) const;
    void set(std::string&& name, int value) const;

    void set(const std::string& name, float value) const;
    void set(std::string&& name, float value) const;



    void set(const std::string& name, const glm::vec2& value) const;
    void set(std::string&& name, const glm::vec2& value) const;

    void set(const std::string& name, float x, float y) const;
    void set(std::string&& name, float x, float y) const;

    void set(const std::string& name, const glm::vec3& value) const;
    void set(std::string&& name, const glm::vec3& value) const;

    void set(const std::string& name, float x, float y, float z) const;
    void set(std::string&& name, float x, float y, float z) const;

    void set(const std::string& name, const glm::vec4& value) const;
    void set(std::string&& name, const glm::vec4& value) const;

    void set(const std::string& name, float x, float y, float z, float w) const;
    void set(std::string&& name, float x, float y, float z, float w) const;



    void set(const std::string& name, const glm::mat2& mat) const;
    void set(std::string&& name, const glm::mat2& mat) const;

    void set(const std::string& name, const glm::mat3& mat) const;
    void set(std::string&& name, const glm::mat3& mat) const;

    void set(const std::string& name, const glm::mat4& mat) const;
    void set(std::string&& name, const glm::mat4& mat) const;



private:
    // ---------------------------------------------------------------------------- Opti
    GLint getOrCacheUniformLocation(const std::string& uniformId) const;
    GLint getOrCacheUniformLocation(std::string&& uniformId) const;


private:
    GLint                                           m_ShaderId;
    mutable std::unordered_map<std::string, GLuint> m_UniformsLocationCache;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___
