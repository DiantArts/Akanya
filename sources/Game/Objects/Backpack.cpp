/*
** EPITECH PROJECT, 2020
** sources/Objects/Backpack
** File description:
** basic model backpack
*/

#include "pch.hpp"

#include "Backpack.hpp"

#include "Engine/Actors/Lights/ALight.hpp"



namespace game::object {



// ---------------------------------------------------------------------------- *structors

Backpack::Backpack(engine::Shader& shader, const size_t numberOfPositions)
    : engine::actor::Model(shader, "backpack/backpack.obj", numberOfPositions)
{}

Backpack::~Backpack()
{}



// ---------------------------------------------------------------------------- override
void Backpack::configureShader(const engine::Camera& camera) const
{
    engine::actor::ADrawable::configureShader(camera);

    for (const auto& light : engine::actor::ALight::getAll()) {
        this->setIntoShader(light);
    }

    this->setIntoShader("material.shininess", 32.0F);
}



} // namespace game::object
