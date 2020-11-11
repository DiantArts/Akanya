/*
** EPITECH PROJECT, 2020
** ModelMatrix
** File description:
** Model
*/

#ifndef MODELMATRIX_HPP
#define MODELMATRIX_HPP

#include <GLFW/glfw3.h>
#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Shader.hpp"

namespace engine::shape3d {

class ModelMatrix {
public:
    ModelMatrix(const engine::Shader& shaderProgram);
    ~ModelMatrix() = default;

    void draw();
    void transform();

private:
    const engine::Shader& m_ShaderProgram;
    engine::Vbo m_Vbo;
    engine::Vao m_Vao;
};

} // namespace engine::shape3d

#endif // MODELMATRIX_HPP
