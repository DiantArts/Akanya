/*
** Akanya, Engine
** sources/Engine/Actors/BasicShapes/Cube
** this is a default built-in cube
*/

#include "pch.hpp"

#include "Cube.hpp"

namespace engine::graphic::actor::basicShape {



Cube::Cube(::engine::graphic::opengl::Shader&              shader,
           const size_t                 numberOfPositions /* = 1 */,
           const size_t                 numberOfTextures /* = 1 */,
           const std::function<void()>& setAttributesFunc /* = Cube::setAttributes */,
           const std::string_view       verticesFilename /* = "cube" */)
    : engine::graphic::actor::ABasicShape(shader,
                                 setAttributesFunc,
                                 verticesFilename,
                                 numberOfPositions,
                                 numberOfTextures)
{}

Cube::~Cube()
{}



// ---------------------------------- Attributes

void Cube::setAttributes()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

} // namespace engine::graphic::actor::basicShape
