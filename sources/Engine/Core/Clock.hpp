/*
** Akanya, Engine
** sources/Engine/Core/Clock
** Simple OpenGL abstractiong of the time
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CLOCK_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CLOCK_HPP___

namespace engine::core {



class Clock {

public:

    // ---------------------------------- *structors

    Clock();
    ~Clock();

    // ---------------------------------- Copy sementic

    Clock(
        const Clock&
    ) noexcept;

    auto operator=(
        const Clock&
    ) noexcept -> Clock&;



    // ---------------------------------- Move sementic

    Clock(
        Clock&&
    ) noexcept;

    auto operator=(
        Clock&&
    ) noexcept -> Clock&;



    // ---------------------------------- Methods

    auto getElapsedTime()
        -> float;


public:
protected:
protected:
private:
private:

    float m_lastFrameTime { 0.0f };

};



} // namespace engine::core

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CLOCK_HPP___
