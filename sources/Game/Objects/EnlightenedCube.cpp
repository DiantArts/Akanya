//
// Akanya, Engine
// sources/Objects/EnlightenedCube
// An enlightened cube lol
//

#include "pch.hpp"
#include "EnlightenedCube.hpp"

#include "Engine/Graphic/Actors/Lights/Directional.hpp"
#include "Engine/Graphic/Actors/Lights/Point.hpp"
#include "Engine/Graphic/Actors/Lights/Spot.hpp"



// ---------------------------------- *structors

::game::object::EnlightenedCube::EnlightenedCube(
    ::engine::graphic::opengl::Shader& shader,
    const size_t numberOfPositions,
    const std::function<void()>& setAttributesFunc,
    const std::string& verticesFilename
)
    : Cube(shader, numberOfPositions, 1, setAttributesFunc, verticesFilename)
{
    this->setBlockBindingIntoShader("LightInformations", 2);

    this->useShader();

    this->addTexture("container.png", "material.diffuse");
    this->addTexture("containerBorders.png", "material.specular");

    this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
    this->setIntoShader("material.shininess", 8.0F);
}

::game::object::EnlightenedCube::~EnlightenedCube() = default;



// ---------------------------------- override

void ::game::object::EnlightenedCube::configureShader(
    const ::engine::graphic::Camera& camera
) const
{
    ::engine::graphic::actor::ADrawable::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());
}
