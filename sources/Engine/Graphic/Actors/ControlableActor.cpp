//
// Akanya
// sources/Engine/Graphic/Actors/ControlableActor
// Allow actor to be controlable
//

#include "pch.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::ControlableActor::ControlableActor() = default;

::engine::graphic::actor::ControlableActor::~ControlableActor() = default;



// ---------------------------------- Move sementic

::engine::graphic::actor::ControlableActor::ControlableActor(
    ControlableActor&&
) noexcept = default;

auto ::engine::graphic::actor::ControlableActor::operator=(
    ControlableActor&&
) noexcept -> ControlableActor& = default;
