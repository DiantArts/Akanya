/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Vertexes/Vertices
** File description:
** Extract vertices from files and alloc buffers to binded ones
*/

#include "pch.hpp"

#include "Vertices.hpp"

#include "Tools/File.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Vertices::Vertices(const std::string_view filepath, size_t& numberOfArrayToDraw)
{
    std::string str { engine::filepath::vertices };
    str += filepath;
    str = tool::file::read(str);

    m_Vertices.reserve(std::count(str.begin(), str.end(), '\n'));
    std::istringstream iss(str);
    std::getline(iss, str);
    numberOfArrayToDraw = std::stol(str);
    while (std::getline(iss, str)) {
        try {
            m_Vertices.push_back(std::stof(str));
        } catch (...) {
            throw std::runtime_error(std::string("stof: '") + str + '\'');
        }
    }
}



// ---------------------------------------------------------------------------- buffer

void Vertices::createBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, m_Vertices.size() * sizeof(float), &m_Vertices.front(),
                 GL_STATIC_DRAW);
}



} // namespace engine
