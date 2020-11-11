/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <GLFW/glfw3.h>
#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Shader.hpp"

namespace engine::shape2d {

class Vao;

class Triangle {
public:
    Triangle(const engine::Shader& shaderProgram);
    ~Triangle() = default;

    void draw();

private:
    const engine::Shader& m_ShaderProgram;
    engine::Vbo m_Vbo;
    engine::Vao m_Vao;
};

} // namespace engine::shape2d

#endif // TRIANGLE_HPP
