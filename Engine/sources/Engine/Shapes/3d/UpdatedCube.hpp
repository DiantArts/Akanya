/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#pragma once

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class UpdatedCube : public engine::shape3d::Drawable {
public:
    UpdatedCube(engine::Shader& shaderProgram, glm::vec3 position = glm::vec3(0, 0, 0));
    virtual ~UpdatedCube();

    size_t getNumberOfArrayToDraw() override final;

    virtual void setAllIntoShader(const engine::Camera& camera);
    virtual glm::mat4 getModel(const glm::vec3& position);

protected:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d
