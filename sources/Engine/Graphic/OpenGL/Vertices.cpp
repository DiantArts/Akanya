/*
** Akanya, Engine
** sources/Engine/Actors/Vertexes/Vertices
** Extract vertices from files and alloc buffers to binded ones
*/

#include "pch.hpp"

#include "Vertices.hpp"

#include "Tools/File.hpp"



namespace engine::graphic::opengl {



// ---------------------------------- *structors

Vertices::Vertices(const std::string_view filepath, size_t& numberOfArrayToDraw)
{
    std::string str { ::engine::core::config::filepath::vertices };
    str += filepath;
    str = tool::file::read(str);

    m_vertices.reserve(std::count(str.begin(), str.end(), '\n'));
    std::istringstream iss(str);
    std::getline(iss, str);
    numberOfArrayToDraw = std::stol(str);
    while (std::getline(iss, str)) {
        try {
            m_vertices.push_back(std::stof(str));
        } catch (...) {
            throw std::runtime_error("stof: '"s + str + '\'');
        }
    }
}



// ---------------------------------- buffer

void Vertices::createBuffer()
{
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices.front(),
                 GL_STATIC_DRAW);
}



} // namespace engine::graphic::opengl
