//
// Akanya
// sources/Engine/Core/Events/MouseButtonReleased
// Event of a mouse released
//

#include "pch.hpp"
#include "MouseButtonReleased.hpp"
#include "../../Graphic/Camera.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::MouseButtonReleased::MouseButtonReleased(
    int keyCode
)
    : m_keyCode(keyCode)
{
}

::engine::core::event::MouseButtonReleased::~MouseButtonReleased() = default;



// ---------------------------------- Copy sementic

::engine::core::event::MouseButtonReleased::MouseButtonReleased(
    const MouseButtonReleased&
) noexcept = default;

auto ::engine::core::event::MouseButtonReleased::operator=(
    const MouseButtonReleased&
) noexcept -> MouseButtonReleased& = default;



// ---------------------------------- Move sementic

::engine::core::event::MouseButtonReleased::MouseButtonReleased(
    MouseButtonReleased&&
) noexcept = default;

auto ::engine::core::event::MouseButtonReleased::operator=(
    MouseButtonReleased&&
) noexcept -> MouseButtonReleased& = default;



// ---------------------------------- Resolver

void ::engine::core::event::MouseButtonReleased::resolve(
    engine::graphic::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_MOUSE_BUTTON_LEFT:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Forward);
        break;
    case GLFW_MOUSE_BUTTON_RIGHT:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Backward);
        break;
    case GLFW_MOUSE_BUTTON_MIDDLE:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Forward);
        break;
    }

}
