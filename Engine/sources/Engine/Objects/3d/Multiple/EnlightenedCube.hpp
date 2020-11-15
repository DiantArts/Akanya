/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#pragma once

#include <Engine/Shapes/3d/Multiple/UpdatedCube.hpp>

namespace engine::object3d::multiple {

class EnlightenedCube : public engine::shape3d::multiple::UpdatedCube {
public:
    EnlightenedCube(engine::Shader& shaderProgram);
    ~EnlightenedCube();

    void setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
};

} // namespace engine::object3d::multiple
