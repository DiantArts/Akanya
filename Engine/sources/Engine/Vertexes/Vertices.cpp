/*
** EPITECH PROJECT, 2020
** Vertices
** File description:
** coordonate to create a shape
*/

#include <sstream>        // std::istringstream
#include <glad/glad.h>    // glBufferData
#include "Tools/File.hpp" // tools::file::read()
#include "Vertices.hpp"   // std::vector, std::string_view

#include <iostream>
namespace engine {

Vertices::Vertices(const std::string_view filepath)
{
    std::string str(engine::Vertices::directoryPath);
    str += filepath;
    str = tools::file::read(std::move(str));
    this->m_Vertices.reserve(std::count(str.begin(), str.end(), '\n'));
    std::istringstream iss(str);
    while (std::getline(iss, str)) {
        this->m_Vertices.push_back(std::stof(str));
    }
}

Vertices::~Vertices()
{}

void Vertices::createBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, this->m_Vertices.size() * sizeof(float), &this->m_Vertices.front(),
            GL_STATIC_DRAW);
}

} // namespace engine
