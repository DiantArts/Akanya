/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#ifndef ENLIGHTENEDCUBE_HPP
#define ENLIGHTENEDCUBE_HPP

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class EnlightenedCube : public engine::shape3d::Drawable {
public:
    EnlightenedCube(engine::Shader& shaderProgram);
    ~EnlightenedCube();

    void setAllIntoShader() override;
};

} // namespace engine::shape3d

#endif // ENLIGHTENEDCUBE_HPP
