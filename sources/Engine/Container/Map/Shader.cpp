/*
** EPITECH PROJECT, 2020
** Shader
** File description:
** Shader
*/

#include "../Map/Shader.hpp"

#include "debugMacros.hpp"



namespace engine::container::map {



// ---------------------------------------------------------------------------- access
engine::Shader& Shader::operator[](const std::string& filename)
{
    try {
        // return it if already cached
        return this->m_ShaderMap.at(filename);

    } catch (const std::exception&) {
        DEBUG_MSG(filename);
        // cache it
        return this->m_ShaderMap.emplace(filename, filename).first->second;
    }
}



// ---------------------------------------------------------------------------- iterators

std::unordered_map<std::string, engine::Shader>::iterator Shader::begin()
{
    return this->m_ShaderMap.begin();
}

std::unordered_map<std::string, engine::Shader>::iterator Shader::end()
{
    return this->m_ShaderMap.end();
}

std::unordered_map<std::string, engine::Shader>::const_iterator Shader::begin() const
{
    return this->m_ShaderMap.begin();
}

std::unordered_map<std::string, engine::Shader>::const_iterator Shader::end() const
{
    return this->m_ShaderMap.end();
}

std::unordered_map<std::string, engine::Shader>::const_iterator Shader::cbegin() const
{
    return this->m_ShaderMap.cbegin();
}

std::unordered_map<std::string, engine::Shader>::const_iterator Shader::cend() const
{
    return this->m_ShaderMap.cend();
}



} // namespace engine::container::map
