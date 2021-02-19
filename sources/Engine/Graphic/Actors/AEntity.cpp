//
// Akanya
// sources/Engine/Graphic/Actors/AEntity
// Actor controlable
//

#include "pch.hpp"
#include "AEntity.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::AEntity::AEntity(
    const std::string& shaderFilepath,
    size_t numberOfPositions
)
    : ::engine::graphic::AActor(shaderFilepath, numberOfPositions)
{}

::engine::graphic::actor::AEntity::~AEntity() = default;
