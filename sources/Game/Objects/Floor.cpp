//
// Akanya, Engine
// sources/Objects/Floor
// Just a floor lol
//

#include "pch.hpp"
#include "Floor.hpp"

#include "Engine/Graphic/Lights/Directional.hpp"
#include "Engine/Graphic/Lights/Point.hpp"
#include "Engine/Graphic/Lights/Spot.hpp"



// ---------------------------------- *structors

::game::object::Floor::Floor(
    const size_t numberOfPositions,
    const std::string& shaderFilepath,
    const std::function<void()>& setAttributesFunc,
    const std::string& verticesFilename
)
    : Cube(shaderFilepath, numberOfPositions, 1, setAttributesFunc, verticesFilename)
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
    this->setIntoShader("material.shininess", 1000.0F);
}

::game::object::Floor::~Floor() = default;



// ---------------------------------- override

void ::game::object::Floor::configureShader() const
{}
