/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#ifndef SHAPE3D_CUBE_HPP
#define SHAPE3D_CUBE_HPP

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class Cube : public engine::shape3d::Drawable {
public:
    Cube(engine::Shader& shaderProgram);
    ~Cube();

    void setAllIntoShader() override;
    glm::mat4 getModel(const glm::vec3& position) override;
    size_t getNumberOfArrayToDraw() override;

public:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d

#endif // SHAPE3D_CUBE_HPP
