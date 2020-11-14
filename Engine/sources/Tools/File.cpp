/*
** EPITECH PROJECT, 2020
** File
** File description:
** file tools to help easier code
*/

#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
#include "File.hpp" // std::string_view

#include <iostream>

namespace tools::file {

std::string read(const std::string_view filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(std::string(filepath).c_str());
        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

std::string read(const std::string& filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(filepath.c_str());
        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

std::string read(const std::string&& filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(filepath.c_str());
        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

} // namespace tools::file
