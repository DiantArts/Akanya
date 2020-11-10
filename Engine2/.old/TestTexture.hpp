/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef TESTTEXTURE_HPP
#define TESTTEXTURE_HPP

#include "Engine/Vao.hpp"
#include "Engine/Shader.hpp"

namespace engine {

class Vao;

class TestTexture {
public:
    TestTexture(engine::Shader &shaderProgram);
    ~TestTexture();

    void draw();

private:
    GLuint m_ebo;
    GLuint m_vbo;
    engine::Vao m_vao;
    engine::Shader &m_shaderProgram;
    GLuint m_texture;
};

} // namespace engine

#endif // TESTTEXTURE_HPP
