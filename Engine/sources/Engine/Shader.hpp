/*
** EPITECH PROJECT, 2020
** Shader
** File description:
** links multiple object shaders to create a program that is able to execute
** tasks
*/

#ifndef SHADERS_HPP
#define SHADERS_HPP

#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace engine {

class Shader {
public:
// ---------------------------------------------------------------------------- *structors
    Shader(const std::string_view vertexPath, const std::string_view fragmentPath);
    ~Shader();

    GLuint get() const { return this->m_ShaderId; };

// ---------------------------------------------------------------------------- Use
    void use() const;

// ---------------------------------------------------------------------------- Set
    void set(const std::string_view name, bool value)  const;
    void set(const std::string_view name, int value)   const;
    void set(const std::string_view name, float value) const;
    void set(const std::string_view name, const glm::vec2 &value) const;
    void set(const std::string_view name, const float x, const float y) const;
    void set(const std::string_view name, const glm::vec3 &value) const;
    void set(const std::string_view name, const float x, const float y, const float z) const;
    void set(const std::string_view name, const glm::vec4 &value) const;
    void set(const std::string_view name, const float x, const float y, const float z, const float w) const;
    void set(const std::string_view name, const glm::mat2 &mat) const;
    void set(const std::string_view name, const glm::mat3 &mat) const;
    void set(const std::string_view name, const glm::mat4 &mat) const;

private:
    GLuint m_ShaderId;
};

} // namespace engine

#endif // SHADERS_HPP
