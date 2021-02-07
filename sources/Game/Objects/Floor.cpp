//
// Akanya, Engine
// sources/Objects/Floor
// Just a floor lol
//

#include "pch.hpp"
#include "Floor.hpp"

#include "Engine/Graphic/Actors/Lights/Directional.hpp"
#include "Engine/Graphic/Actors/Lights/Point.hpp"
#include "Engine/Graphic/Actors/Lights/Spot.hpp"



// ---------------------------------- *structors

::game::object::Floor::Floor(
    ::engine::graphic::opengl::Shader& shader,
    const size_t numberOfPositions,
    const std::function<void()>& setAttributesFunc,
    const std::string& verticesFilename
)
    : Cube(shader, numberOfPositions, 1, setAttributesFunc, verticesFilename)
{
    this->setBlockBindingIntoShader("LightInformations", 2);

    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
    this->setIntoShader("material.shininess", 1000.0F);
}

::game::object::Floor::~Floor() = default;



// ---------------------------------- override

void ::game::object::Floor::configureShader(
    const ::engine::graphic::Camera& camera
) const
{
    ::engine::graphic::actor::ADrawable::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());
}
