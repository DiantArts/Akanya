//
// Akanya
// sources/Engine/Core/Events/AEvent
// Base class of every event
//

#include "pch.hpp"
#include "AEvent.hpp"



// ---------------------------------- *structors

::engine::core::event::AEvent::AEvent() = default;

::engine::core::event::AEvent::~AEvent() = default;



// ---------------------------------- Copy sementic

::engine::core::event::AEvent::AEvent(
    const AEvent&
) noexcept = default;

auto ::engine::core::event::AEvent::operator=(
    const AEvent&
) noexcept -> AEvent& = default;



// ---------------------------------- Move sementic

::engine::core::event::AEvent::AEvent(
    AEvent&&
) noexcept = default;

auto ::engine::core::event::AEvent::operator=(
    AEvent&&
) noexcept -> AEvent& = default;
