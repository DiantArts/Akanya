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
    UpdatedCube(engine::Shader& shaderProgram, const glm::vec3& position = glm::vec3(0, 0, 0),
        const std::string_view verticesFileName = "updatedCube",
        const std::function<void()>& attributesSetter = []{
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
        }, const size_t numberOfTextures = 1);
    virtual ~UpdatedCube();

    size_t getNumberOfArrayToDraw() override final;

    virtual void setAllIntoShader(const engine::Camera& camera);
    virtual glm::mat4 getModel(const glm::vec3& position);

protected:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d
