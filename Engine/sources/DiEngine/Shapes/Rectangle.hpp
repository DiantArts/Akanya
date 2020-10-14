/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "DiEngine/Vao.hpp"
#include "DiEngine/Shader.hpp"

namespace DiEngine {

class Vao;

class Rectangle {
public:
    Rectangle(DiEngine::Shader &shaderProgram);
    ~Rectangle();

    void draw();

private:
    GLuint m_ebo;
    GLuint m_vbo;
    DiEngine::Vao m_vao;
    DiEngine::Shader &m_shaderProgram;
};

} // namespace DiEngine

#endif // RECTANGLE_HPP
