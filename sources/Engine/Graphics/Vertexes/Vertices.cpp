/*
** EPITECH PROJECT, 2020
** Vertices
** File description:
** coordonate to create a shape
*/

#include "Vertices.hpp"

#include <iostream>
#include <sstream>

#include <glad/glad.h>

#include "Engine/Filepaths.hpp"
#include "Tools/File.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Vertices::Vertices(const std::string_view filepath, size_t& numberOfArrayToDraw)
{
    std::string str { engine::filepath::vertices };
    str += filepath;
    str = tools::file::read(str);

    this->m_Vertices.reserve(std::count(str.begin(), str.end(), '\n'));
    std::istringstream iss(str);
    std::getline(iss, str);
    numberOfArrayToDraw = std::stol(str);
    while (std::getline(iss, str)) {
        this->m_Vertices.push_back(std::stof(str));
    }
}



// ---------------------------------------------------------------------------- buffer

void Vertices::createBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, this->m_Vertices.size() * sizeof(float), &this->m_Vertices.front(),
                 GL_STATIC_DRAW);
}



} // namespace engine
