/*
** EPITECH PROJECT, 2020
** Clock
** File description:
** opengl time abstraction
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

namespace engine {

class Clock {
public:
    Clock();
    ~Clock();

    float getElapsedTime();

private:
    float m_LastFrameTime = 0.0f;
};

} // engine

#endif // CLOCK_HPP
