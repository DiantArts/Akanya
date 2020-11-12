/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef SHAPE3D_IMPROVED_CUBE_HPP
#define SHAPE3D_IMPROVED_CUBE_HPP

#include <vector>
#include "Engine/Texture.hpp"
#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Vertexes/Vbo.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Camera.hpp"

namespace engine::shape3d {

class Vao;

class ImprovedCube {
public:
    ImprovedCube(engine::Shader &shaderProgram);
    ~ImprovedCube();

    void addPosition(float x = 0, float y = 0, float z = 0);
    void addPosition(glm::vec3& vec);

    void draw(const engine::Camera& camera);

public:
    static constexpr size_t numberOfArrayToDraw = 36;

private:
    engine::Shader& m_Shader;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    engine::Texture m_Textures;

    GLuint m_Ebo;
    std::vector<glm::vec3> m_Positions;
};

} // namespace engine::shape3d

#endif // SHAPE3D_IMPROVED_CUBE_HPP
