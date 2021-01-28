/*
** Akanya, Engine
** sources/Objects/Floor
** Just a floor lol
*/

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
    const std::string_view verticesFilename
)
    : Cube(shader, numberOfPositions, 1, setAttributesFunc, verticesFilename)
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
    this->setIntoShader("material.shininess", 1000.0F);
}

::game::object::Floor::~Floor() = default;



// ---------------------------------- override

void ::game::object::Floor::configureShader(
    const ::engine::graphic::Window& window,
    const ::engine::graphic::Camera& camera
) const
{
    ::engine::graphic::actor::ADrawable::configureShader(window, camera);
    this->setIntoShader("viewPos", camera.getPosition());

    this->setIntoShader("gamma", window.getConfig().gamma);
    this->setIntoShader("blinn", window.getConfig().blinn);

    this->setIntoShader("nrDirLight", ::engine::graphic::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", ::engine::graphic::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", ::engine::graphic::actor::light::Spot::getNbLight());
    for (const auto& light : ::engine::graphic::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }
}
