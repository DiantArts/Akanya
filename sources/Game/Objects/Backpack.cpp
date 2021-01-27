/*
** Akanya, Engine
** sources/Objects/Backpack
** basic model backpack
*/

#include "pch.hpp"

#include "Backpack.hpp"

#include "Engine/Graphic/Actors/Lights/ALight.hpp"



namespace game::object {



// ---------------------------------- *structors

Backpack::Backpack(::engine::graphic::opengl::Shader& shader, const size_t numberOfPositions)
    : engine::graphic::actor::Model(shader, "backpack/backpack.obj", numberOfPositions)
{}

Backpack::~Backpack()
{}



// ---------------------------------- override
void Backpack::configureShader(const engine::graphic::Camera& camera) const
{
    engine::graphic::actor::ADrawable::configureShader(camera);

    for (const auto& light : engine::graphic::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }

    this->setIntoShader("material.shininess", 32.0F);
}



} // namespace game::object
