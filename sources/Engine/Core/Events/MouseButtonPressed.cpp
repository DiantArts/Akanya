//
// Akanya
// sources/Engine/Core/Events/MouseButtonPressed
// Event of a mouse pressed
//

#include "pch.hpp"
#include "MouseButtonPressed.hpp"
#include "../../Graphic/Camera.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::MouseButtonPressed::MouseButtonPressed(
    int keyCode
)
    : m_keyCode(keyCode)
{
}

::engine::core::event::MouseButtonPressed::~MouseButtonPressed() = default;



// ---------------------------------- Copy sementic

::engine::core::event::MouseButtonPressed::MouseButtonPressed(
    const MouseButtonPressed&
) noexcept = default;

auto ::engine::core::event::MouseButtonPressed::operator=(
    const MouseButtonPressed&
) noexcept -> MouseButtonPressed& = default;



// ---------------------------------- Move sementic

::engine::core::event::MouseButtonPressed::MouseButtonPressed(
    MouseButtonPressed&&
) noexcept = default;

auto ::engine::core::event::MouseButtonPressed::operator=(
    MouseButtonPressed&&
) noexcept -> MouseButtonPressed& = default;



// ---------------------------------- Resolver

void ::engine::core::event::MouseButtonPressed::resolve(
    engine::graphic::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_MOUSE_BUTTON_LEFT:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Forward);
        break;
    case GLFW_MOUSE_BUTTON_RIGHT:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Backward);
        break;
    case GLFW_MOUSE_BUTTON_MIDDLE:
        scene.centerCursorWindow();
        break;
    }

}
