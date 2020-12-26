/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Cube
** File description:
** BasicCube
*/

#include "Cube.hpp"

namespace engine::actor::shape3d {



Cube::Cube(engine::Shader&              shader,
           const std::function<void()>& setAttributes /* = Cube::setAttributes */,
           const std::string_view       verticesFilename /* = "cube" */,
           const size_t                 numberOfPositions  /* = 1 */,
           const size_t                 numberOfTextures /* = 1 */)
    : engine::actor::shape3d::Basic(shader,
                                      setAttributes,
                                      verticesFilename,
                                      numberOfPositions,
                                      numberOfTextures)
{}

Cube::~Cube()
{}



// ---------------------------------------------------------------------------- Attributes

void Cube::setAttributes()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

} // namespace engine::actor::shape3d
