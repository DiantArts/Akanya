//
// Akanya
// sources/Engine/Core/Events/KeyReleased
// Event of a key pressed
//

#include "pch.hpp"
#include "KeyReleased.hpp"
#include "../../Graphic/Camera.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::KeyReleased::KeyReleased(
    int keyCode
)
    : m_keyCode(keyCode)
{
}

::engine::core::event::KeyReleased::~KeyReleased() = default;



// ---------------------------------- Copy sementic

::engine::core::event::KeyReleased::KeyReleased(
    const KeyReleased&
) noexcept = default;

auto ::engine::core::event::KeyReleased::operator=(
    const KeyReleased&
) noexcept -> KeyReleased& = default;



// ---------------------------------- Move sementic

::engine::core::event::KeyReleased::KeyReleased(
    KeyReleased&&
) noexcept = default;

auto ::engine::core::event::KeyReleased::operator=(
    KeyReleased&&
) noexcept -> KeyReleased& = default;



// ---------------------------------- Move sementic

void ::engine::core::event::KeyReleased::resolve(
    engine::graphic::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_KEY_W:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Forward);
        break;
    case GLFW_KEY_S:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Backward);
        break;
    case GLFW_KEY_D:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Right);
        break;
    case GLFW_KEY_A:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Left);
        break;
    case GLFW_KEY_SPACE:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Up);
        break;
    case GLFW_KEY_X:
        scene.removeCameraMovementState(engine::graphic::Camera::MovementState::Down);
        break;
    }

}
