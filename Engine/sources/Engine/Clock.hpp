/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** opengl time abstraction
*/

#pragma once

namespace engine {

class Clock {
public:
    Clock();
    ~Clock();

    float getElapsedTime();

private:
    float m_LastFrameTime { 0.0F };
};

} // namespace engine
