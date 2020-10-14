/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <string.h>
#include <sstream>
#include <fstream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "debugMacros.hpp"
#include "Shader.hpp"

static std::string readFile(const char *const filepath);
static GLuint compileShader(GLenum shaderType, const char *const filepath) noexcept;
static void checkCompilationStatus(GLuint shader) noexcept;
static void checkLinkageStatus(GLuint program) noexcept;

namespace DiEngine {

Shader::Shader(const char *vertexPath, const char *fragmentPath)
    : m_id(glCreateProgram())
{
    GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexPath);
    GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragmentPath);

    glAttachShader(this->m_id, vertex);
    glAttachShader(this->m_id, fragment);
    glLinkProgram(this->m_id);
    checkLinkageStatus(this->m_id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() noexcept
{
    glDeleteProgram(this->m_id);
}

void Shader::use() noexcept
{
    glUseProgram(this->m_id);
}

void Shader::set(const std::string &name, bool value) const noexcept
{
    glUniform1f(glGetUniformLocation(this->m_id, name.c_str()), (int)value);
}

void Shader::set(const std::string &name, int value) const noexcept
{
    glUniform1f(glGetUniformLocation(this->m_id, name.c_str()), value);
}

void Shader::set(const std::string &name, float value) const noexcept
{
    glUniform1f(glGetUniformLocation(this->m_id, name.c_str()), value);
}

} // namespace DiEngine

static std::string readFile(const char *const filepath)
{
    std::stringstream shaderStream;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    shaderFile.open(filepath);
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    return std::string(shaderStream.str());
}

static GLuint compileShader(GLenum shaderType, const char *const filepath) noexcept
{
    GLuint vertex = glCreateShader(shaderType);

    try {
        // don't try to strdup in cade of std::ifstream::failure
        const std::string readenFile(readFile(filepath));
        const char *shaderCode = strdup(readenFile.c_str());
        glShaderSource(vertex, 1, &shaderCode, nullptr);
        free(const_cast<char *>(shaderCode));
    } catch(const std::ifstream::failure &e) {
        ERROR_MSG("Shader file unsuccesfully read");
        return 0;
    }

    glCompileShader(vertex);
    checkCompilationStatus(vertex);

    return vertex;
}

// Display program compilation's errors if needed
static void checkCompilationStatus(GLuint shader) noexcept
{
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    DEBUG_MSG(success);
    if (success == GL_FALSE) {
        GLchar infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        ERROR_MSG("Shader compilation failed: " << infoLog);
    }
}

// Display program linkage's errors if needed
static void checkLinkageStatus(GLuint program) noexcept
{
    GLint success = 0;
    glGetShaderiv(program, GL_LINK_STATUS, &success);
    DEBUG_MSG(success);
    if (success == GL_FALSE) {
        GLchar infoLog[512];
        glGetShaderInfoLog(program, 512, nullptr, infoLog);
        ERROR_MSG("Program linkage failed: " << infoLog);
    }
}
