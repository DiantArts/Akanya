/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef TESTTEXTURE_HPP
#define TESTTEXTURE_HPP

#include "DiEngine/Vao.hpp"
#include "DiEngine/Shader.hpp"

namespace DiEngine {

class Vao;

class TestTexture {
public:
    TestTexture(DiEngine::Shader &shaderProgram);
    ~TestTexture();

    void draw();

private:
    GLuint m_ebo;
    GLuint m_vbo;
    DiEngine::Vao m_vao;
    DiEngine::Shader &m_shaderProgram;
    GLuint m_texture;
};

} // namespace DiEngine

#endif // TESTTEXTURE_HPP
