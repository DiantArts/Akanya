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



// ---------------------------------- Resolver

void ::engine::core::event::KeyPressed::resolve(
    engine::graphic::AScene& scene
)
{
    if (scene.m_camera.isAttached()) {
        switch (m_keyCode) {
        case GLFW_KEY_W: scene.m_camera.startMovingForward(); break;
        case GLFW_KEY_S: scene.m_camera.startMovingBackward(); break;
        case GLFW_KEY_D: scene.m_camera.startMovingRight(); break;
        case GLFW_KEY_A: scene.m_camera.startMovingLeft(); break;
        case GLFW_KEY_SPACE: scene.m_camera.startMovingUp(); break;
        case GLFW_KEY_X: scene.m_camera.startMovingDown(); break;
        case GLFW_KEY_ESCAPE: scene.setToOver(); break;
        }
    } else {
        // switch (m_keyCode) {
        // case GLFW_KEY_W: scene.m_player->startMovingForward(); break;
        // case GLFW_KEY_S: scene.m_player->startMovingBackward(); break;
        // case GLFW_KEY_D: scene.m_player->startMovingRight(); break;
        // case GLFW_KEY_A: scene.m_player->startMovingLeft(); break;
        // case GLFW_KEY_SPACE: scene.m_player->startMovingUp(); break;
        // case GLFW_KEY_X: scene.m_player->startMovingDown(); break;
        // case GLFW_KEY_ESCAPE: scene.setToOver(); break;
        // }
    }

}
