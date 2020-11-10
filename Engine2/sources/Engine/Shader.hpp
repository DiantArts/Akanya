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

private:
    GLuint m_id;
};

} // namespace engine

#endif // SHADERS_HPP
