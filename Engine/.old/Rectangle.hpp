/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Engine/Vao.hpp"
#include "Engine/Shader.hpp"

namespace engine {

class Vao;

class Rectangle {
public:
    Rectangle(engine::Shader &shaderProgram);
    ~Rectangle();

    void draw();

private:
    GLuint m_ebo;
    GLuint m_vbo;
    engine::Vao m_vao;
    engine::Shader &m_shaderProgram;
};

} // namespace engine

#endif // RECTANGLE_HPP
