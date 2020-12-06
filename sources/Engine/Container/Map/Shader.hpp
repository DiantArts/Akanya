/*
** EPITECH PROJECT, 2020
** ShaderVector
** File description:
** ShaderVector
*/

#pragma once


#include <string>
#include <unordered_map>

#include <glad/glad.h>

#include "../../Shader.hpp"



namespace engine::container::map {



class Shader {
public:
    // ---------------------------------------------------------------------------- access
    engine::Shader& operator[](const std::string& filename); // note: string_view doesn't work


private:
    std::unordered_map<std::string, engine::Shader> m_ShaderMap;
};



} // namespace engine::container::map
