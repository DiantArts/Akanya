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

static std::string readFile(const std::string_view filepath);
static GLuint compileShader(GLenum shaderType, const std::string_view filepath);
static void checkCompilationStatus(GLuint shader);
static void checkLinkageStatus(GLuint shader);

namespace engine {

// ---------------------------------------------------------------------------- *structors

Shader::Shader(const std::string_view vertexPath, const std::string_view fragmentPath)
    : m_id(glCreateProgram())
{
    GLuint vertex = compileShader(GL_VERTEX_SHADER, std::string(vertexPath).c_str());
    GLuint fragment = compileShader(GL_FRAGMENT_SHADER, std::string(fragmentPath).c_str());

    if (vertex && fragment) {
        glAttachShader(this->m_id, vertex);
        glAttachShader(this->m_id, fragment);
        glLinkProgram(this->m_id);
        checkLinkageStatus(this->m_id);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader()
{
    glDeleteProgram(this->m_id);
}

// ---------------------------------------------------------------------------- Use

void Shader::use() const
{
    glUseProgram(this->m_id);
}

// ---------------------------------------------------------------------------- Set

void Shader::set(const std::string_view name, bool value) const
{
    glUniform1f(glGetUniformLocation(this->m_id, std::string(name).c_str()), value);
}

void Shader::set(const std::string_view name, int value) const
{
    glUniform1f(glGetUniformLocation(this->m_id, std::string(name).c_str()), value);
}

void Shader::set(const std::string_view name, float value) const
{
    glUniform1f(glGetUniformLocation(this->m_id, std::string(name).c_str()), value);
}

} // namespace engine

// ---------------------------------------------------------------------------- Static

static std::string readFile(const std::string_view filepath)
{
    std::stringstream shaderStream;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    shaderFile.open(std::string(filepath).c_str());
    shaderStream << shaderFile.rdbuf();
    shaderFile.close();
    return shaderStream.str();
}

static GLuint compileShader(GLenum shaderType, const std::string_view filepath)
{
    GLuint vertex = glCreateShader(shaderType);

    try {
        // don't try to strdup in cade of std::ifstream::failure
        const std::string readenFile(readFile(filepath));
        const char* shaderCode = strdup(readenFile.c_str());
        glShaderSource(vertex, 1, &shaderCode, nullptr);
        free(const_cast<char*>(shaderCode));
    } catch(const std::ifstream::failure& e) {
        ERROR_MSG("Shader file unsuccesfully read");
        return 0;
    }

    glCompileShader(vertex);
    checkCompilationStatus(vertex);

    return vertex;
}

// Display program compilation's errors if needed
static void checkCompilationStatus(GLuint shader)
{
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    DEBUG_MSG(success);
    if (success == GL_FALSE) {
        GLchar infoLog[512] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        ERROR_MSG("Shader compilation failed: " << infoLog);
    }
}

// Display program linkage's errors if needed
static void checkLinkageStatus(GLuint shader)
{
    GLint success = 0;
    glGetShaderiv(shader, GL_LINK_STATUS, &success);
    DEBUG_MSG(success);
    if (success == GL_FALSE) {
        GLchar infoLog[512] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        ERROR_MSG("Program linkage failed: " << infoLog);
    }
}
