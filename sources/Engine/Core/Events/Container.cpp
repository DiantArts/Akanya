//
// Akanya
// sources/Engine/Core/Events/Container
// contain every event
//

#include "pch.hpp"



// ---------------------------------- *structors

::engine::core::event::Container::Container() = default;

::engine::core::event::Container::~Container() = default;



// ---------------------------------- Move sementic

::engine::core::event::Container::Container(
    Container&&
) noexcept = default;

auto ::engine::core::event::Container::operator=(
    Container&&
) noexcept -> Container& = default;



// ---------------------------------- Resolver

void ::engine::core::event::Container::resolve(
    engine::graphic::AScene& scene
)
{
    for (auto& event : m_events) {
        event->resolve(scene);
    }
    m_events.clear();

}
