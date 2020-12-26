/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/Cube
** File description:
** BasicCube
*/

#include "Cube.hpp"

namespace engine::actor::basicShape {



Cube::Cube(engine::Shader&              shader,
           const size_t                 numberOfPositions  /* = 1 */,
           const size_t                 numberOfTextures /* = 1 */,
           const std::function<void()>& setAttributesFunc /* = Cube::setAttributes */,
           const std::string_view       verticesFilename /* = "cube" */)
    : engine::actor::ABasicShape(shader,
                                 setAttributesFunc,
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

} // namespace engine::actor::basicShape
