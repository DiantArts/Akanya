/*
** Akanya, Engine
** sources/Engine/Clock
** Simple OpenGL abstractiong of the time
*/

#include "pch.hpp"
#include "Clock.hpp"


// ---------------------------------- *structors

::engine::core::Clock::Clock() = default;

::engine::core::Clock::~Clock() = default;



// ---------------------------------- Copy sementic

::engine::core::Clock::Clock(
    const Clock&
) noexcept = default;

auto ::engine::core::Clock::operator=(
    const Clock&
) noexcept -> Clock& = default;



// ---------------------------------- Move sementic

::engine::core::Clock::Clock(
    Clock&&
) noexcept = default;

auto ::engine::core::Clock::operator=(
    Clock&&
) noexcept -> Clock& = default;



// ---------------------------------- Methods

auto ::engine::core::Clock::getElapsedTime()
    -> float
{
    auto currentFrameTime { glfwGetTime() };
    auto deltaTime { currentFrameTime - m_lastFrameTime };
    m_lastFrameTime  = currentFrameTime;
    return deltaTime;
}
