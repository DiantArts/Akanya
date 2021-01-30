//
// Akanya, Engine
// sources/Engine/Graphic/Actors/AActor
// An actor is a drawable and a transformable
//

#include "pch.hpp"


namespace engine::graphic::actor {



// ---------------------------------- *structors

AActor::AActor(
    ::engine::graphic::opengl::Shader& shader,
    const glm::mat4& projection,
    const size_t numberOfPositions
)
    : engine::graphic::actor::ADrawable(shader, projection)
    , engine::graphic::actor::ATransformable(numberOfPositions)
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
