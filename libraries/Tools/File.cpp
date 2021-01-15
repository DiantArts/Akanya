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

#ifdef __linux__
#include <sys/stat.h>
#endif



namespace tool::file {



std::string read(const std::string_view filepath)
{
    std::stringstream shaderStream;
    {
        std::ifstream shaderFile;
        shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try {
            shaderFile.open(std::string(filepath));
        } catch (const std::ifstream::failure& e) {
            throw std::runtime_error(std::string("unable to open '") + std::string(filepath) +
                                     std::string("' file (") + e.what() + ')');
        }


        shaderStream << shaderFile.rdbuf();
    }
    return shaderStream.str();
}

bool exists(const std::string& filepath)
{
#ifdef __linux__
    struct stat buffer;
    return stat(filepath.c_str(), &buffer) == 0;
#else
    return std::ifstream(filepath.c_str()).good();
#endif
}


} // namespace tool::file
