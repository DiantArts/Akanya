//
// Akanya
// sources/Engine/Core/Events/KeyPressed
// Event of a key pressed
//

#include "pch.hpp"
#include "KeyPressed.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::KeyPressed::KeyPressed(
    int keyCode
)
    : m_keyCode(keyCode)
{
}

::engine::core::event::KeyPressed::~KeyPressed() = default;



// ---------------------------------- Copy sementic

::engine::core::event::KeyPressed::KeyPressed(
    const KeyPressed&
) noexcept = default;

auto ::engine::core::event::KeyPressed::operator=(
    const KeyPressed&
) noexcept -> KeyPressed& = default;



// ---------------------------------- Move sementic

::engine::core::event::KeyPressed::KeyPressed(
    KeyPressed&&
) noexcept = default;

auto ::engine::core::event::KeyPressed::operator=(
    KeyPressed&&
) noexcept -> KeyPressed& = default;



// ---------------------------------- Move sementic

void ::engine::core::event::KeyPressed::resolve(
    engine::graphic::AScene& scene
)
{
    switch (m_keyCode) {
    case GLFW_KEY_W:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Forward);
        break;
    case GLFW_KEY_S:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Backward);
        break;
    case GLFW_KEY_D:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Right);
        break;
    case GLFW_KEY_A:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Left);
        break;
    case GLFW_KEY_SPACE:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Up);
        break;
    case GLFW_KEY_X:
        scene.addCameraMovementState(engine::graphic::Camera::MovementState::Down);
        break;
    case GLFW_KEY_ESCAPE:
        scene.setToOver();
        break;
    }

}
