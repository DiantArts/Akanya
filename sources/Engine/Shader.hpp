/*
** EPITECH PROJECT, 2020
** sources/Engine/Shader
** File description:
** Controls graphic pipeline
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___

#include <span>
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
    Shader(std::string_view filepathes);
    Shader(std::string_view vertexFilename, std::string_view fragmentFilename);
    Shader(std::string_view vertexFilename,
           std::string_view fragmentFilename,
           std::string_view geometryFilename);
    ~Shader();


    // ---------------------------------------------------------------------------- Use
    void use() const;


    // ---------------------------------------------------------------------------- Set (must be used before)
    void set(const std::string& name, bool value) const;
    void set(std::string&& name, bool value) const;

    void set(const std::string& name, int value) const;
    void set(std::string&& name, int value) const;

    void set(const std::string& name, size_t value) const;
    void set(std::string&& name, size_t value) const;

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



    void set(const std::string& name, std::span<int> array) const;
    void set(std::string&& name, std::span<int> array) const;

    void set(const std::string& name, std::span<float> array) const;
    void set(std::string&& name, std::span<float> array) const;



    void set(const std::string& name, std::span<glm::vec2> array) const;
    void set(std::string&& name, std::span<glm::vec2> array) const;

    void set(const std::string& name, std::span<glm::vec3> array) const;
    void set(std::string&& name, std::span<glm::vec3> array) const;

    void set(const std::string& name, std::span<glm::vec4> array) const;
    void set(std::string&& name, std::span<glm::vec4> array) const;



    void set(const std::string& name, std::span<glm::mat2> array) const;
    void set(std::string&& name, std::span<glm::mat2> array) const;

    void set(const std::string& name, std::span<glm::mat3> array) const;
    void set(std::string&& name, std::span<glm::mat3> array) const;

    void set(const std::string& name, std::span<glm::mat4> array) const;
    void set(std::string&& name, std::span<glm::mat4> array) const;



private:
    void compile(std::string&& vertexFilepath, std::string&& fragmentFilepath);
    void
    compile(std::string&& vertexFilepath, std::string&& fragmentFilepath, std::string&& geometryFilepath);

    // ---------------------------------------------------------------------------- Opti
    GLint getOrCacheUniformLocation(const std::string& uniformId) const;
    GLint getOrCacheUniformLocation(std::string&& uniformId) const;


private:
    GLint                                           m_ShaderId;
    mutable std::unordered_map<std::string, GLuint> m_UniformsLocationCache;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SHADER_HPP___
