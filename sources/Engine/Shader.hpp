/*
** EPITECH PROJECT, 2020
** Shader
** File description:
** links multiple object shaders to create a program that is able to execute
** tasks
*/

#pragma once


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



namespace engine {



class Shader {
public:
    // ---------------------------------------------------------------------------- *structors
    Shader(const std::string_view vertexPath, const std::string_view fragmentPath);
    Shader(const std::string_view filepathes);
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

    void set(const std::string& name, const float x, const float y) const;
    void set(std::string&& name, const float x, const float y) const;

    void set(const std::string& name, const glm::vec3& value) const;
    void set(std::string&& name, const glm::vec3& value) const;

    void set(const std::string& name, const float x, const float y, const float z) const;
    void set(std::string&& name, const float x, const float y, const float z) const;

    void set(const std::string& name, const glm::vec4& value) const;
    void set(std::string&& name, const glm::vec4& value) const;

    void set(const std::string& name, const float x, const float y, const float z, const float w) const;
    void set(std::string&& name, const float x, const float y, const float z, const float w) const;



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


public:
    constexpr static auto directoryPath { "./data/shaders/" };


private:
    GLint                                           m_ShaderId;
    mutable std::unordered_map<std::string, GLuint> m_UniformsLocationCache;
};

} // namespace engine
