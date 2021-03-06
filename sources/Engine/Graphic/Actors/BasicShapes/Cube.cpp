//
// Akanya, Engine
// sources/Engine/Graphic/Actors/BasicShapes/Cube
// this is a default built-in cube
//

#include "pch.hpp"
#include "Cube.hpp"



::engine::graphic::actor::basicShape::Cube::Cube(
    const std::string& shaderFilepath,
    const size_t numberOfPositions,
    const size_t numberOfTextures,
    const std::function<void()>& setAttributesFunc,
    const std::string&     verticesFilename
)
    : engine::graphic::actor::ABasicShape(
        shaderFilepath,
        setAttributesFunc,
        verticesFilename,
        numberOfPositions,
        numberOfTextures
    )
{}

::engine::graphic::actor::basicShape::Cube::~Cube() = default;
