/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Cube
** File description:
** BasicCube
*/

#include "Cube.hpp"

namespace engine::graphic::shape3d {



Cube::Cube(engine::Shader&              shader,
           const bool                   isMultiplePositionShape /* = false */,
           const std::function<void()>& setAttributes /* = Cube::setAttributes */,
           const std::string_view       verticesFilename /* = "cube" */,
           const size_t                 numberOfTextures /* = 1 */)
    : engine::graphic::shape3d::Basic(shader,
                                      setAttributes,
                                      verticesFilename,
                                      isMultiplePositionShape,
                                      numberOfTextures)
{}

Cube::~Cube()
{}


// ---------------------------------------------------------------------------- Virtual
void Cube::transformShape(const engine::Camera&) const
{}


// ---------------------------------------------------------------------------- Attributes

void Cube::setAttributes()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

} // namespace engine::graphic::shape3d
