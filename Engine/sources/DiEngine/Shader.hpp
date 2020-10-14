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

namespace DiEngine {

class Shader {
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader() noexcept;

    void use() noexcept;

    void set(const std::string &name, bool value) const noexcept;
    void set(const std::string &name, int value) const noexcept;
    void set(const std::string &name, float value) const noexcept;

private:
    GLuint m_id;
};

} // namespace DiEngine

#endif // SHADERS_HPP
