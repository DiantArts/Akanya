/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#ifndef ENLIGHTENEDCUBE_HPP
#define ENLIGHTENEDCUBE_HPP

#include <Engine/Shapes/3d/UpdatedCube.hpp>

namespace engine::object3d {

class EnlightenedCube : public engine::shape3d::UpdatedCube {
public:
    EnlightenedCube(engine::Shader& shaderProgram);
    ~EnlightenedCube();

    void setAllIntoShader() override;
    glm::mat4 getModel(const glm::vec3& position) override;
};

} // namespace engine::object3d

#endif // ENLIGHTENEDCUBE_HPP
