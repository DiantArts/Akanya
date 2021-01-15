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


Shader::Shader(const std::string_view filepaths) : m_ShaderId(glCreateProgram())
{
    std::string vertexFilepath;
    vertexFilepath.reserve(engine::filepath::shader::vertexes.size() + filepaths.size() + 5);
    vertexFilepath += engine::filepath::shader::vertexes;
    vertexFilepath += filepaths;
    vertexFilepath += ".glsl";

    std::string fragmentFilepath;
    fragmentFilepath.reserve(engine::filepath::shader::fragments.size() + filepaths.size() + 5);
    fragmentFilepath += engine::filepath::shader::fragments;
    fragmentFilepath += filepaths;
    fragmentFilepath += ".glsl";

    std::string geometryFilepath;
    geometryFilepath.reserve(engine::filepath::shader::geometries.size() + filepaths.size() + 5);
    geometryFilepath += engine::filepath::shader::geometries;
    geometryFilepath += filepaths;
    geometryFilepath += ".glsl";


    if (tool::file::exists(geometryFilepath)) {
        this->compile(std::move(vertexFilepath), std::move(fragmentFilepath), std::move(geometryFilepath));
    } else {
        this->compile(std::move(vertexFilepath), std::move(fragmentFilepath));
    }
}

Shader::Shader(const std::string_view vertexFilename, const std::string_view fragmentFilename)
    : m_ShaderId(glCreateProgram())
{
    std::string vertexFilepath;
    vertexFilepath.reserve(engine::filepath::shader::vertexes.size() + vertexFilename.size() + 5);
    vertexFilepath += engine::filepath::shader::vertexes;
    vertexFilepath += vertexFilename;
    vertexFilepath += ".glsl";

    std::string fragmentFilepath;
    fragmentFilepath.reserve(engine::filepath::shader::fragments.size() + fragmentFilename.size() + 5);
    fragmentFilepath += engine::filepath::shader::fragments;
    fragmentFilepath += fragmentFilename;
    fragmentFilepath += ".glsl";

    this->compile(std::move(vertexFilepath), std::move(fragmentFilepath));
}


Shader::Shader(const std::string_view vertexFilename,
               const std::string_view fragmentFilename,
               const std::string_view geometryFilename)
    : m_ShaderId(glCreateProgram())
{
    std::string vertexFilepath;
    vertexFilepath.reserve(engine::filepath::shader::vertexes.size() + vertexFilename.size() + 5);
    vertexFilepath += engine::filepath::shader::vertexes;
    vertexFilepath += vertexFilename;
    vertexFilepath += ".glsl";

    std::string fragmentFilepath;
    fragmentFilepath.reserve(engine::filepath::shader::fragments.size() + fragmentFilename.size() + 5);
    fragmentFilepath += engine::filepath::shader::fragments;
    fragmentFilepath += fragmentFilename;
    fragmentFilepath += ".glsl";

    std::string geometryFilepath;
    geometryFilepath.reserve(engine::filepath::shader::geometries.size() + geometryFilename.size() + 5);
    geometryFilepath += engine::filepath::shader::geometries;
    geometryFilepath += geometryFilename;
    geometryFilepath += ".glsl";

    this->compile(std::move(vertexFilepath), std::move(fragmentFilepath), std::move(geometryFilepath));
}

Shader::~Shader()
{
    glDeleteProgram(m_ShaderId);
}



// ---------------------------------------------------------------------------- Use

void Shader::use() const
{
    glUseProgram(m_ShaderId);
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
    glUniform2f(this->getOrCacheUniformLocation(name), value.x, value.y);
}

void Shader::set(std::string&& name, const glm::vec2& value) const
{
    glUniform2f(getOrCacheUniformLocation(std::move(name)), value.x, value.y);
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
    glUniform3f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z);
}

void Shader::set(std::string&& name, const glm::vec3& value) const
{
    glUniform3f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z);
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
    glUniform4f(this->getOrCacheUniformLocation(name), value.x, value.y, value.z, value.w);
}

void Shader::set(std::string&& name, const glm::vec4& value) const
{
    glUniform4f(this->getOrCacheUniformLocation(std::move(name)), value.x, value.y, value.z, value.w);
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

//


void Shader::set(const std::string& name, const std::span<int> array) const
{
    glUniform1iv(this->getOrCacheUniformLocation(name), array.size(), &array.front());
}

void Shader::set(std::string&& name, const std::span<int> array) const
{
    glUniform1iv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front());
}

//

void Shader::set(const std::string& name, const std::span<float> array) const
{
    glUniform1fv(this->getOrCacheUniformLocation(name), array.size(), &array.front());
}

void Shader::set(std::string&& name, const std::span<float> array) const
{
    glUniform1fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front());
}

//

void Shader::set(const std::string& name, const std::span<glm::vec2> array) const
{
    glUniform2fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void Shader::set(std::string&& name, const std::span<glm::vec2> array) const
{
    glUniform2fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}

//

void Shader::set(const std::string& name, const std::span<glm::vec3> array) const
{
    glUniform3fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void Shader::set(std::string&& name, const std::span<glm::vec3> array) const
{
    glUniform3fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}

//

void Shader::set(const std::string& name, const std::span<glm::vec4> array) const
{
    glUniform4fv(this->getOrCacheUniformLocation(name), array.size(), &array.front()[0]);
}

void Shader::set(std::string&& name, const std::span<glm::vec4> array) const
{
    glUniform4fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), &array.front()[0]);
}

//

void Shader::set(const std::string& name, const std::span<glm::mat2> array) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void Shader::set(std::string&& name, const std::span<glm::mat2> array) const
{
    glUniformMatrix2fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}

//

void Shader::set(const std::string& name, const std::span<glm::mat3> array) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void Shader::set(std::string&& name, const std::span<glm::mat3> array) const
{
    glUniformMatrix3fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}

//

void Shader::set(const std::string& name, const std::span<glm::mat4> array) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(name), array.size(), GL_FALSE, &array.front()[0][0]);
}

void Shader::set(std::string&& name, const std::span<glm::mat4> array) const
{
    glUniformMatrix4fv(this->getOrCacheUniformLocation(std::move(name)), array.size(), GL_FALSE,
                       &array.front()[0][0]);
}



// ---------------------------------------------------------------------------- Compilation

void Shader::compile(std::string&& vertexFilepath, std::string&& fragmentFilepath)
{
    auto vertex { compileShader(GL_VERTEX_SHADER, vertexFilepath) };
    auto fragment { compileShader(GL_FRAGMENT_SHADER, fragmentFilepath) };

    if (vertex && fragment) {
        glAttachShader(m_ShaderId, vertex);
        glAttachShader(m_ShaderId, fragment);
        glLinkProgram(m_ShaderId);
        checkLinkageStatus(m_ShaderId);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::compile(std::string&& vertexFilepath,
                     std::string&& fragmentFilepath,
                     std::string&& geometryFilepath)
{
    auto vertex { compileShader(GL_VERTEX_SHADER, vertexFilepath) };
    auto fragment { compileShader(GL_FRAGMENT_SHADER, fragmentFilepath) };
    auto geometry { compileShader(GL_GEOMETRY_SHADER, geometryFilepath) };


    if (vertex && fragment && geometry) {
        glAttachShader(m_ShaderId, vertex);
        glAttachShader(m_ShaderId, fragment);
        glAttachShader(m_ShaderId, geometry);
        glLinkProgram(m_ShaderId);
        checkLinkageStatus(m_ShaderId);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    glDeleteShader(geometry);
}



// ---------------------------------------------------------------------------- Opti

GLint Shader::getOrCacheUniformLocation(const std::string& uniformId) const
{
    try {
        // return it if already cached
        return m_UniformsLocationCache.at(uniformId);

    } catch (const std::exception&) {
        // cache it
        return m_UniformsLocationCache.emplace(uniformId, glGetUniformLocation(m_ShaderId, uniformId.c_str()))
            .first->second;
    }
}

GLint Shader::getOrCacheUniformLocation(std::string&& uniformId) const
{
    try {
        // return it if already cached
        return m_UniformsLocationCache.at(uniformId);

    } catch (const std::exception&) {
        // cache it
        return m_UniformsLocationCache
            .emplace(std::move(uniformId), glGetUniformLocation(m_ShaderId, uniformId.c_str()))
            .first->second;
    }
}



} // namespace engine



// ---------------------------------------------------------------------------- Static

static GLuint compileShader(GLenum shaderType, const std::string filepath)
{
    GLuint vertex { glCreateShader(shaderType) };

    try {
        const std::string readenFile { tool::file::read(filepath) };
        const char*       shaderCode { readenFile.c_str() };
        glShaderSource(vertex, 1, &shaderCode, nullptr);
    } catch (const std::ifstream::failure& e) {
        std::clog << "Shader file '" << filepath << "' unsuccesfully read (" << e.what() << ")" << std::endl;
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
