/*
** Akanya, Engine
** sources/Objects/Floor
** Just a floor lol
*/

#include "pch.hpp"

#include "Floor.hpp"

#include "Engine/Graphic/Actors/Lights/ALight.hpp"
#include "Engine/Graphic/Actors/Lights/Directional.hpp"
#include "Engine/Graphic/Actors/Lights/Point.hpp"
#include "Engine/Graphic/Actors/Lights/Spot.hpp"

extern bool gammaEnabled;
extern bool blinnEnabled;



namespace game::object {



// ---------------------------------- *structors

Floor::Floor(::engine::graphic::opengl::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, Floor::setAttributes, "floor")
{
    this->useShader();
    this->addTexture("woodFloor.jpg", "material.texture");
    this->setIntoShader("material.shininess", 1000.0F);
}

Floor::~Floor() = default;



// ---------------------------------- override

void Floor::configureShader(
    const engine::graphic::Window& window
) const
{
    engine::graphic::actor::ABasicShape::configureShader(window);
    this->setIntoShader("viewPos", window.getCamera().getPosition());

    this->setIntoShader("gamma", window.getConfig().gamma);
    this->setIntoShader("blinn", window.getConfig().blinn);

    this->setIntoShader("nrDirLight", ::engine::graphic::actor::light::Directional::getNbLight());
    this->setIntoShader("nrPointLight", ::engine::graphic::actor::light::Point::getNbLight());
    this->setIntoShader("nrSpotLight", ::engine::graphic::actor::light::Spot::getNbLight());
    for (auto light : ::engine::graphic::actor::light::ALight::getAll()) {
        this->setIntoShader(light);
    }
}



// ---------------------------------- Attributes

void Floor::setAttributes()
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


} // namespace game::object
