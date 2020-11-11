/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.hpp"

static std::string readFile(const std::string& filepath);
static GLuint compileShader(GLenum shaderType, const std::string filepath);
static void checkCompilationStatus(GLuint shader);
static void checkLinkageStatus(GLuint shader);

namespace engine {

// ---------------------------------------------------------------------------- *structors

Shader::Shader(const std::string_view vertexPath, const std::string_view fragmentPath)
    : m_ShaderId(glCreateProgram())
{
    GLuint vertex = compileShader(GL_VERTEX_SHADER, std::string(vertexPath));
    GLuint fragment = compileShader(GL_FRAGMENT_SHADER, std::string(fragmentPath));

    if (vertex && fragment) {
        glAttachShader(this->m_ShaderId, vertex);
        glAttachShader(this->m_ShaderId, fragment);
        glLinkProgram(this->m_ShaderId);
        checkLinkageStatus(this->m_ShaderId);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(this->m_ShaderId);
}

// ---------------------------------------------------------------------------- Use

void Shader::use() const
{
    glUseProgram(this->m_ShaderId);
}

// ---------------------------------------------------------------------------- Set

void Shader::set(const std::string_view name, bool value) const
{
    glUniform1i(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), (int)value);
}

void Shader::set(const std::string_view name, int value) const
{
    glUniform1i(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), value);
}

void Shader::set(const std::string_view name, float value) const
{
    glUniform1f(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), value);
}

void Shader::set(const std::string_view name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), 1, &value[0]);
}

void Shader::set(const std::string_view name, const float x, const float y) const
{
    glUniform2f(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), x, y);
}

void Shader::set(const std::string_view name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), 1, &value[0]);
}

void Shader::set(const std::string_view name, const float x, const float y, const float z) const
{
    glUniform3f(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), x, y, z);
}

void Shader::set(const std::string_view name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), 1, &value[0]);
}

void Shader::set(const std::string_view name, const float x, const float y, const float z, const float w) const
{
    glUniform4f(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()), x, y, z, w);
}

void Shader::set(const std::string_view name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()),
            1, GL_FALSE, &mat[0][0]);
}
void Shader::set(const std::string_view name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()),
            1, GL_FALSE, &mat[0][0]);
}

void Shader::set(const std::string_view name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(this->m_ShaderId, std::string(name).c_str()),
            1, GL_FALSE, &mat[0][0]);
}

} // namespace engine

// ---------------------------------------------------------------------------- Static

static GLuint compileShader(GLenum shaderType, const std::string filepath)
{
    GLuint vertex = glCreateShader(shaderType);

    try {
        const std::string readenFile(readFile(filepath));
        const char* shaderCode = readenFile.c_str();
        glShaderSource(vertex, 1, &shaderCode, nullptr);
    } catch(const std::ifstream::failure& e) {
        std::clog << "Shader file unsuccesfully read\n";
        return 0;
    }

    glCompileShader(vertex);
    checkCompilationStatus(vertex);

    return vertex;
}

static std::string readFile(const std::string& filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(std::string(filepath).c_str());
        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

static void checkCompilationStatus(GLuint shader)
{
    GLint status = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLchar infoLog[512] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::clog << "Shader compilation failed: " << infoLog << "\n";
    }
}

// Display program linkage's errors if needed
static void checkLinkageStatus(GLuint shader)
{
    GLint status = 0;
    glGetProgramiv(shader, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLchar infoLog[1024] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::clog << "Program linkage failed (type: " << status << "):" << infoLog << "\n";
    }
}
