/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** opengl time abstraction
*/

// clang-format off

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// clang-format on

#include "Clock.hpp"

namespace engine {

Clock::Clock()
{}

Clock::~Clock()
{}

float Clock::getElapsedTime()
{
    float currentFrameTime = glfwGetTime();
    float deltaTime        = currentFrameTime - this->m_LastFrameTime;
    this->m_LastFrameTime  = currentFrameTime;
    return deltaTime;
}

} // namespace engine
