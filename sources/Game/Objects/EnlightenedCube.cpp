/*
** Akanya, Engine
** sources/Objects/EnlightenedCube
** An enlightened cube lol
*/

#include "pch.hpp"

#include "EnlightenedCube.hpp"

#include "Engine/Graphic/Actors/Lights/ALight.hpp"
#include "Engine/Graphic/Actors/Lights/Directional.hpp"
#include "Engine/Graphic/Actors/Lights/Point.hpp"
#include "Engine/Graphic/Actors/Lights/Spot.hpp"



// ---------------------------------- *structors

::game::object::EnlightenedCube::EnlightenedCube(
    ::engine::graphic::opengl::Shader& shader,
    const size_t numberOfPositions
)
    : Cube(shader, numberOfPositions, 1, EnlightenedCube::setAttributes, "lightningMap")
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

void ::game::object::EnlightenedCube::configureShader(const engine::graphic::Window& window) const
{
    engine::graphic::actor::ABasicShape::configureShader(window);
    this->setIntoShader("viewPos", window.getCamera().getPosition());

    this->setIntoShader("gamma", window.getConfig().gamma);
    this->setIntoShader("blinn", window.getConfig().blinn);

    this->setIntoShader("nrDirLight", engine::graphic::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", engine::graphic::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", engine::graphic::actor::light::Spot::getNbLight());
    for (const auto& light : engine::graphic::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }
}



// ---------------------------------- Attributes

void ::game::object::EnlightenedCube::setAttributes()
{
    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // normal attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}
