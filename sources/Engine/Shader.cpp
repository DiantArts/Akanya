/*
** EPITECH PROJECT, 2020
** sources/Engine/Shader
** File description:
** Controls graphic pipeline
*/

#include "Shader.hpp"

#include <fstream>
#include <iostream>

#include "Engine/Filepaths.hpp"
#include "Tools/File.hpp"



static GLuint compileShader(GLenum shaderType, const std::string filepath);
static void   checkCompilationStatus(GLuint shader, const std::string_view filepath);
static void   checkLinkageStatus(GLuint shader);



namespace engine {



// ---------------------------------------------------------------------------- *structors

Shader::Shader(const std::string_view vertexFileName, const std::string_view fragmentFileName)
    : m_ShaderId(glCreateProgram())
{
    std::string vertexFilepath;
    vertexFilepath.reserve(engine::filepath::shader::vertexes.size() + vertexFileName.size());
    vertexFilepath += engine::filepath::shader::vertexes;
    vertexFilepath += vertexFileName;

    std::string fragmentFilepath;
    vertexFilepath.reserve(engine::filepath::shader::vertexes.size() + fragmentFileName.size());
    fragmentFilepath += engine::filepath::shader::fragments;
    fragmentFilepath += fragmentFileName;

    auto vertex { compileShader(GL_VERTEX_SHADER, vertexFilepath) };
    auto fragment { compileShader(GL_FRAGMENT_SHADER, fragmentFilepath) };

    if (vertex && fragment) {
        glAttachShader(this->m_ShaderId, vertex);
        glAttachShader(this->m_ShaderId, fragment);
        glLinkProgram(this->m_ShaderId);
        checkLinkageStatus(this->m_ShaderId);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::Shader(const std::string_view filepathes) : Shader(filepathes, filepathes)
{}


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

void Shader::set(const std::string& name, const bool value) const
{
    glUniform1i(this->getOrCacheUniformLocation(name), static_cast<int>(value));
}

void Shader::set(std::string&& name, const bool value) const
{
    glUniform1i(this->getOrCacheUniformLocation(std::move(name)), static_cast<int>(value));
}

//

void Shader::set(const std::string& name, const int value) const
{
    glUniform1i(this->getOrCacheUniformLocation(name), value);
}

void Shader::set(std::string&& name, const int value) const
{
    glUniform1i(this->getOrCacheUniformLocation(std::move(name)), value);
}

//

void Shader::set(const std::string& name, const float value) const
{
    glUniform1f(this->getOrCacheUniformLocation(name), value);
}

void Shader::set(std::string&& name, const float value) const
{
    glUniform1f(this->getOrCacheUniformLocation(std::move(name)), value);
}

//

void Shader::set(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(this->getOrCacheUniformLocation(name), 1, &value[0]);
}

void Shader::set(std::string&& name, const glm::vec2& value) const
{
    glUniform2fv(getOrCacheUniformLocation(std::move(name)), 1, &value[0]);
}

//

void Shader::set(const std::string& name, const float x, const float y) const
{
    glUniform2f(this->getOrCacheUniformLocation(name), x, y);
}

void Shader::set(std::string&& name, const float x, const float y) const
{
    glUniform2f(this->getOrCacheUniformLocation(std::move(name)), x, y);
}

//

void Shader::set(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(this->getOrCacheUniformLocation(name), 1, &value[0]);
}

void Shader::set(std::string&& name, const glm::vec3& value) const
{
    glUniform3fv(this->getOrCacheUniformLocation(std::move(name)), 1, &value[0]);
}

//

void Shader::set(const std::string& name, const float x, const float y, const float z) const
{
    glUniform3f(this->getOrCacheUniformLocation(name), x, y, z);
}

void Shader::set(std::string&& name, const float x, const float y, const float z) const
{
    glUniform3f(this->getOrCacheUniformLocation(std::move(name)), x, y, z);
}

//

void Shader::set(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(this->getOrCacheUniformLocation(name), 1, &value[0]);
}

void Shader::set(std::string&& name, const glm::vec4& value) const
{
    glUniform4fv(this->getOrCacheUniformLocation(std::move(name)), 1, &value[0]);
}

//

void Shader::set(const std::string& name, const float x, const float y, const float z, const float w) const
{
    glUniform4f(this->getOrCacheUniformLocation(name), x, y, z, w);
}

void Shader::set(std::string&& name, const float x, const float y, const float z, const float w) const
{
    glUniform4f(this->getOrCacheUniformLocation(std::move(name)), x, y, z, w);
}

//

void Shader::set(const std::string& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::set(std::string&& name, const glm::mat2& mat) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}

//

void Shader::set(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::set(std::string&& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}

//

void Shader::set(const std::string& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::set(std::string&& name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(std::move(name)), 1, GL_FALSE, &mat[0][0]);
}



// ---------------------------------------------------------------------------- Opti
GLint Shader::getOrCacheUniformLocation(const std::string& uniformId) const
{
    try {
        // return it if already cached
        return this->m_UniformsLocationCache.at(uniformId);

    } catch (const std::exception&) {
        // cache it
        return this->m_UniformsLocationCache
            .emplace(uniformId, glGetUniformLocation(this->m_ShaderId, uniformId.c_str()))
            .first->second;
    }
}

GLint Shader::getOrCacheUniformLocation(std::string&& uniformId) const
{
    try {
        // return it if already cached
        return this->m_UniformsLocationCache.at(uniformId);

    } catch (const std::exception&) {
        // cache it
        return this->m_UniformsLocationCache
            .emplace(std::move(uniformId), glGetUniformLocation(this->m_ShaderId, uniformId.c_str()))
            .first->second;
    }
}



} // namespace engine



// ---------------------------------------------------------------------------- Static

static GLuint compileShader(GLenum shaderType, const std::string filepath)
{
    GLuint vertex { glCreateShader(shaderType) };

    try {
        const std::string readenFile { tools::file::read(filepath) };
        const char*       shaderCode { readenFile.c_str() };
        glShaderSource(vertex, 1, &shaderCode, nullptr);
    } catch (const std::ifstream::failure& e) {
        std::clog << "Shader file '" << filepath << "' unsuccesfully read\n";
        return 0;
    }

    glCompileShader(vertex);
    checkCompilationStatus(vertex, filepath);

    return vertex;
}

static void checkCompilationStatus(GLuint shader, const std::string_view filepath)
{
    GLint status { 0 };
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLchar infoLog[512] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::clog << "Shader '" << filepath << "' compilation failed: " << infoLog << "\n";
    }
}

// Display program linkage's errors if needed
static void checkLinkageStatus(GLuint shader)
{
    GLint status { 0 };
    glGetProgramiv(shader, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLchar infoLog[1024] = { 0 };
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::clog << "Program linkage failed (type: " << status << "):" << infoLog << "\n";
    }
}
