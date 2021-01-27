/*
** EPITECH PROJECT, 2020
** sources/Engine/Clock
** File description:
** Simple OpenGL abstractiong of the time
*/

#include "pch.hpp"

#include "Clock.hpp"



namespace engine {



Clock::Clock()
{}

Clock::~Clock()
{}



float Clock::getElapsedTime()
{
    float currentFrameTime = glfwGetTime();
    float deltaTime        = currentFrameTime - m_LastFrameTime;
    m_LastFrameTime  = currentFrameTime;
    return deltaTime;
}



} // namespace engine
