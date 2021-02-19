//
// Akanya
// sources/Engine/Core/Events/MousePosition
// Event of a mouse position
//

#include "pch.hpp"
#include "MousePosition.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::MousePosition::MousePosition(
    float xPos,
    float yPos
)
    : m_position(xPos, yPos)
{}

::engine::core::event::MousePosition::~MousePosition() = default;



// ---------------------------------- Copy sementic

::engine::core::event::MousePosition::MousePosition(
    const MousePosition&
) noexcept = default;

auto ::engine::core::event::MousePosition::operator=(
    const MousePosition&
) noexcept -> MousePosition& = default;



// ---------------------------------- Move sementic

::engine::core::event::MousePosition::MousePosition(
    MousePosition&&
) noexcept = default;

auto ::engine::core::event::MousePosition::operator=(
    MousePosition&&
) noexcept -> MousePosition& = default;



// ---------------------------------- Resolver

void ::engine::core::event::MousePosition::resolve(
    engine::graphic::AScene& scene
)
{
    scene.m_camera.orienteFromCursorPosition(std::move(m_position));
}
