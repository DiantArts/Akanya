/*
** EPITECH PROJECT, 2020
** LightCube
** File description:
** Light source as cube
*/

#ifndef LIGHTCUBE_HPP
#define LIGHTCUBE_HPP

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class LightCube : public engine::shape3d::Drawable {
public:
    LightCube(engine::Shader& shaderProgram);
    ~LightCube();

    void setAllIntoShader() override;
};

} // namespace engine::shape3d

#endif // LIGHTCUBE_HPP
