/*
** EPITECH PROJECT, 2020
** sources/Engine/Clock
** File description:
** Simple OpenGL abstractiong of the time
*/

#include "Clock.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>



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
