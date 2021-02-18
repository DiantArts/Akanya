//
// Akanya, Engine
// sources/Engine/Graphic/Actors/AActor
// An actor is a drawable and a transformable
//

#include "pch.hpp"


// ---------------------------------- *structors

::engine::graphic::actor::AActor::AActor(
    const std::string& shaderFilepath,
    const size_t numberOfPositions
)
    : engine::graphic::actor::ADrawable(shaderFilepath)
    , engine::graphic::actor::ATransformable(numberOfPositions)
{}

::engine::graphic::actor::AActor::~AActor()
{}



// ---------------------------------- Drawable

auto ::engine::graphic::actor::AActor::getModel(const glm::vec3& position) const
    -> glm::mat4
{
    return this->transformModel(position);
}



// ---------------------------------- Transformable

void ::engine::graphic::actor::AActor::update(float)
{}
