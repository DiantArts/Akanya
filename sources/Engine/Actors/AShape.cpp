/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/AShape
** File description:
** A shape is drawable and transformable
*/

#include "AShape.hpp"


namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

AShape::AShape(engine::Shader& shader, const size_t numberOfPositions)
    : engine::actor::ADrawable(shader), engine::actor::ATransformable(numberOfPositions)
{}

AShape::~AShape()
{}



// ---------------------------------------------------------------------------- Drawable

glm::mat4 AShape::getModel(const glm::vec3& position) const
{
    return this->transformModel(position);
}



// ---------------------------------------------------------------------------- Transformable

void AShape::update(float)
{}



} // namespace engine::actor
