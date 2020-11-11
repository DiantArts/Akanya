/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef SHAPE3D_CUBE_HPP
#define SHAPE3D_CUBE_HPP

#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Camera.hpp"

namespace engine::shape3d {

class Vao;

class Cube {
public:
    Cube(engine::Shader &shaderProgram);
    ~Cube();

    void draw(const engine::Camera& camera);

private:
    void transform();
    void bindTextures();
    GLuint genTexture(char const * const filepath, bool isRGBA = false);

private:
    engine::Shader& m_Shader;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    GLuint m_Ebo;
    GLuint m_Texture1;
    GLuint m_Texture2;

    glm::vec3 cubePositions[10]; // tmp
};

} // namespace engine::shape3d

#endif // SHAPE3D_CUBE_HPP
