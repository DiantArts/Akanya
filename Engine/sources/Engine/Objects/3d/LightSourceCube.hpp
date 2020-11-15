/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#pragma once

#include <Engine/Shapes/3d/UpdatedCube.hpp>

namespace engine::object3d {

class LightSourceCube : public engine::shape3d::UpdatedCube {
public:
    LightSourceCube(engine::Shader& shaderProgram, glm::vec3 position = glm::vec3(0, 0, 0));
    ~LightSourceCube();

    void setAllIntoShader(const engine::Camera&) override;
};

} // namespace engine::object3d
