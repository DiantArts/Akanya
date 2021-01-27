/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/AActor
** File description:
** An actor is a drawable and a transformable
*/

#include "pch.hpp"

#include "AActor.hpp"


namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

AActor::AActor(engine::Shader& shader, const size_t numberOfPositions)
    : engine::actor::ADrawable(shader), engine::actor::ATransformable(numberOfPositions)
{}

AActor::~AActor()
{}



// ---------------------------------------------------------------------------- Drawable

glm::mat4 AActor::getModel(const glm::vec3& position) const
{
    return this->transformModel(position);
}



// ---------------------------------------------------------------------------- Transformable

void AActor::update(float)
{}



} // namespace engine::actor
