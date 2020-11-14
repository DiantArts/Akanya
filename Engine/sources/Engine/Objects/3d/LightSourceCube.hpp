/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#ifndef LIGHTSOURCECUBE_HPP
#define LIGHTSOURCECUBE_HPP

#include <Engine/Shapes/3d/UpdatedCube.hpp>

namespace engine::object3d {

class LightSourceCube : public engine::shape3d::UpdatedCube {
public:
    LightSourceCube(engine::Shader& shaderProgram);
    ~LightSourceCube();

    void setAllIntoShader() override;
};

} // namespace engine::object3d

#endif // LIGHTSOURCECUBE_HPP
