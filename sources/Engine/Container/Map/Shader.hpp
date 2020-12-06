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


    // ---------------------------------------------------------------------------- iterators
    std::unordered_map<std::string, engine::Shader>::iterator begin();
    std::unordered_map<std::string, engine::Shader>::iterator end();

    std::unordered_map<std::string, engine::Shader>::const_iterator begin() const;
    std::unordered_map<std::string, engine::Shader>::const_iterator end() const;

    std::unordered_map<std::string, engine::Shader>::const_iterator cbegin() const;
    std::unordered_map<std::string, engine::Shader>::const_iterator cend() const;


private:
    std::unordered_map<std::string, engine::Shader> m_ShaderMap;
};



} // namespace engine::container::map
