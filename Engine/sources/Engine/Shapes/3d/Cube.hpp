/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#pragma once

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class Cube : public engine::shape3d::Drawable {
public:
    Cube(engine::Shader& shaderProgram, glm::vec3 position = glm::vec3(0, 0, 0));
    ~Cube();

    void setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
    size_t getNumberOfArrayToDraw() override;

public:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d
