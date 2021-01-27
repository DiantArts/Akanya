/*
** Akanya, Engine
** sources/Engine/Actors/AActor
** An actor is a drawable and a transformable
*/

#include "pch.hpp"

#include "AActor.hpp"


namespace engine::graphic::actor {



// ---------------------------------- *structors

AActor::AActor(::engine::graphic::opengl::Shader& shader, const size_t numberOfPositions)
    : engine::graphic::actor::ADrawable(shader), engine::graphic::actor::ATransformable(numberOfPositions)
{}

AActor::~AActor()
{}



// ---------------------------------- Drawable

glm::mat4 AActor::getModel(const glm::vec3& position) const
{
    return this->transformModel(position);
}



// ---------------------------------- Transformable

void AActor::update(float)
{}



} // namespace engine::graphic::actor
