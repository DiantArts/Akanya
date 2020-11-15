/*
** EPITECH PROJECT, 2020
** Shader
** File description:
** links multiple object shaders to create a program that is able to execute
** tasks
*/

#pragma once

#include <string_view>
#include <glad/glad.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

namespace engine {

class Shader {
public:
// ---------------------------------------------------------------------------- *structors
    Shader(const std::string_view vertexPath, const std::string_view fragmentPath);
    ~Shader();

// ---------------------------------------------------------------------------- Use
    void use() const;

// ---------------------------------------------------------------------------- Set
    void set(const std::string_view name, bool value)  const;
    void set(const std::string_view name, int value)   const;
    void set(const std::string_view name, float value) const;
    void set(const std::string_view name, const glm::vec2& value) const;
    void set(const std::string_view name, const float x, const float y) const;
    void set(const std::string_view name, const glm::vec3& value) const;
    void set(const std::string_view name, const float x, const float y, const float z) const;
    void set(const std::string_view name, const glm::vec4& value) const;
    void set(const std::string_view name, const float x, const float y, const float z, const float w) const;
    void set(const std::string_view name, const glm::mat2& mat) const;
    void set(const std::string_view name, const glm::mat3& mat) const;
    void set(const std::string_view name, const glm::mat4& mat) const;

public:
    constexpr static auto directoryPath = "./data/shaders/";

private:
    GLuint m_ShaderId;
};

} // namespace engine
