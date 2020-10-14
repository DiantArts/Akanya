/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "DiEngine/Vao.hpp"
#include "DiEngine/Shader.hpp"

namespace DiEngine {

class Vao;

class Triangle {
public:
    Triangle(DiEngine::Shader &shaderProgram);
    ~Triangle();

    void draw();

private:
    GLuint m_vbo;
    DiEngine::Vao m_vao;
    DiEngine::Shader &m_shaderProgram;
};

} // namespace DiEngine

#endif // TRIANGLE_HPP
