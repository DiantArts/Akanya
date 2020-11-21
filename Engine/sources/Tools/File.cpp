/*
** EPITECH PROJECT, 2020
** File
** File description:
** file tools to help easier code
*/

#include "File.hpp" // std::string_view

#include <fstream> // std::ifstream
#include <iostream>
#include <sstream> // std::stringstream
#include <string>  // std::string



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



} // namespace tools::file
