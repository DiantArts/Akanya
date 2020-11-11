/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef TESTTEXTURE_HPP
#define TESTTEXTURE_HPP

#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Shader.hpp"

namespace engine::shape3d {

class Vao;

class TestTexture {
public:
    TestTexture(engine::Shader &shaderProgram);
    ~TestTexture();

    void draw();

private:
    void transform();
    void bindTextures();
    GLuint genTexture(char const * const filepath, bool isRGBA = false);

private:
    engine::Shader &m_ShaderProgram;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    GLuint m_Ebo;
    GLuint m_Texture1;
    GLuint m_Texture2;

    glm::vec3 cubePositions[10];
};

} // namespace engine::shape3d

#endif // TESTTEXTURE_HPP
