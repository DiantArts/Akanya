/*
** EPITECH PROJECT, 2020
** File
** File description:
** file tools to help easier code
*/

#include <fstream>
#include <sstream>
#include "File.hpp"

namespace tools::file {

std::string read(const std::string_view filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        shaderFile.open(std::string(filepath).c_str());
        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

} // namespace tools::file
