/*
** EPITECH PROJECT, 2020
** sources/Engine/Container/Map/Shader
** File description:
** ShaderVector
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_MAP_SHADER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_MAP_SHADER_HPP___

#include <string>
#include <unordered_map>

#include <glad/glad.h>

#include "../../Shader.hpp"



namespace engine::container::map {



class Shader {
public:
    // ---------------------------------------------------------------------------- ACCESS
    engine::Shader& operator[](const std::string& filename); // note: string_view doesn't work

private:
    std::unordered_map<std::string, engine::Shader> m_ShaderMap;
};



} // namespace engine::container::map



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CONTAINER_MAP_SHADER_HPP___
