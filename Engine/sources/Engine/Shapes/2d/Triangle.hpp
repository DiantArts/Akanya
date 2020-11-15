/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#pragma once

#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Vertexes/Vao.hpp"

namespace engine {

class Shader;

namespace shape2d {

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

} // namespace shape2d
} // namespace engine
