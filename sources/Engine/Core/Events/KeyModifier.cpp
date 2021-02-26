//
// Akanya
// sources/Engine/Core/Events/KeyModifier
// Event of a key pressed
//

#include "pch.hpp"
#include "KeyModifier.hpp"
#include "../../Graphic/Camera.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::KeyModifier::KeyModifier(
    unsigned int codepoint,
    int mods
)
    : m_codepoint(codepoint)
    , m_mods(mods)
{
}

::engine::core::event::KeyModifier::~KeyModifier() = default;



// ---------------------------------- Copy sementic

::engine::core::event::KeyModifier::KeyModifier(
    const KeyModifier&
) noexcept = default;

auto ::engine::core::event::KeyModifier::operator=(
    const KeyModifier&
) noexcept -> KeyModifier& = default;



// ---------------------------------- Move sementic

::engine::core::event::KeyModifier::KeyModifier(
    KeyModifier&&
) noexcept = default;

auto ::engine::core::event::KeyModifier::operator=(
    KeyModifier&&
) noexcept -> KeyModifier& = default;



// ---------------------------------- Resolver

void ::engine::core::event::KeyModifier::resolve(
    engine::graphic::AScene& scene
)
{
    switch (m_codepoint) {
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
