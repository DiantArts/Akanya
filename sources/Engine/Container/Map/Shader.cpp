/*
** EPITECH PROJECT, 2020
** Shader
** File description:
** Shader
*/

#include "../Map/Shader.hpp"



namespace engine::container::map {



// ---------------------------------------------------------------------------- access
engine::Shader& Shader::operator[](const std::string& filename)
{
    try {
        // return it if already cached
        return this->m_ShaderMap.at(filename);

    } catch (const std::exception&) {
        // cache it
        return this->m_ShaderMap.emplace(filename, filename).first->second;
    }
}



} // namespace engine::container::map
