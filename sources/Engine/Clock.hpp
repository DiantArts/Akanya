/*
** EPITECH PROJECT, 2020
** sources/Engine/Clock
** File description:
** OpenGL time abstraction
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CLOCK_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CLOCK_HPP___



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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CLOCK_HPP___
