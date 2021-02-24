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
        case GLFW_KEY_W: scene.m_camera.startMovingForward(); return;
        case GLFW_KEY_S: scene.m_camera.startMovingBackward(); return;
        case GLFW_KEY_D: scene.m_camera.startMovingRight(); return;
        case GLFW_KEY_A: scene.m_camera.startMovingLeft(); return;
        case GLFW_KEY_SPACE: scene.m_camera.startMovingUp(); return;
        case GLFW_KEY_X: scene.m_camera.startMovingDown(); return;
        }
    } else {
        switch (m_keyCode) {
        case GLFW_KEY_W: scene.m_player->get().control().startMovingForward(); return;
        case GLFW_KEY_S: scene.m_player->get().control().startMovingBackward(); return;
        case GLFW_KEY_D: scene.m_player->get().control().startMovingRight(); return;
        case GLFW_KEY_A: scene.m_player->get().control().startMovingLeft(); return;
        case GLFW_KEY_SPACE: scene.m_player->get().control().startMovingUp(); return;
        case GLFW_KEY_X: scene.m_player->get().control().startMovingDown(); return;
        }
    }
    switch (m_keyCode) {
    case GLFW_KEY_ESCAPE: scene.setToOver(); return;
    }

}
