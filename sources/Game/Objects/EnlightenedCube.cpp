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
    const glm::mat4& projection,
    const size_t numberOfPositions,
    const std::function<void()>& setAttributesFunc,
    const std::string_view verticesFilename
)
    : Cube(shader, projection, numberOfPositions, 1, setAttributesFunc, verticesFilename)
{
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

    this->setIntoShader("gamma", camera.getConfig().gamma);
    this->setIntoShader("blinn", camera.getConfig().blinn);

    this->setIntoShader("nrDirLight", ::engine::graphic::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", ::engine::graphic::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", ::engine::graphic::actor::light::Spot::getNbLight());
    for (const auto& light : ::engine::graphic::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }
}
