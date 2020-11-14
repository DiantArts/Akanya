/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#ifndef LIGHTSOURCECUBE_HPP
#define LIGHTSOURCECUBE_HPP

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class LightSourceCube : public engine::shape3d::Drawable {
public:
    LightSourceCube(engine::Shader& shaderProgram);
    ~LightSourceCube();

    void setAllIntoShader() override;
    glm::mat4 getModel(const glm::vec3& position) override;
    size_t getNumberOfArrayToDraw() override;

public:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d

#endif // LIGHTSOURCECUBE_HPP
