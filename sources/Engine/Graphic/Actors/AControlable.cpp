//
// Akanya
// sources/Engine/Graphic/Actors/AControlable
// Allow to controle the Scene
//

#include "pch.hpp"
#include "AControlable.hpp"



// ---------------------------------- *structors

::engine::graphic::actor::AControlable::AControlable() = default;

::engine::graphic::actor::AControlable::~AControlable() = default;



// ---------------------------------- Copy sementic

::engine::graphic::actor::AControlable::AControlable(
    const AControlable&
) noexcept = default;

auto ::engine::graphic::actor::AControlable::operator=(
    const AControlable&
) noexcept -> AControlable& = default;



// ---------------------------------- Move sementic

::engine::graphic::actor::AControlable::AControlable(
    AControlable&&
) noexcept = default;

auto ::engine::graphic::actor::AControlable::operator=(
    AControlable&&
) noexcept -> AControlable& = default;
