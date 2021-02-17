//
// Akanya
// sources/Engine/Core/Events/MouseScroll
// Event of a mouse scroll
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSESCROLL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSESCROLL_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class MouseScroll
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit MouseScroll(
        int xoffset,
        int yoffset
    );

    ~MouseScroll();



    // ---------------------------------- Copy sementic

    MouseScroll(
        const MouseScroll&
    ) noexcept;

    auto operator=(
        const MouseScroll&
    ) noexcept -> MouseScroll&;



    // ---------------------------------- Copy sementic

    MouseScroll(
        MouseScroll&&
    ) noexcept;

    auto operator=(
        MouseScroll&&
    ) noexcept -> MouseScroll&;



    // ---------------------------------- Resolver

    virtual void resolve(
        engine::graphic::AScene& scene
    ) override final;



public:
protected:
protected:
private:
private:

    int m_xoffset;
    int m_yoffset;

};



} // namespace engine::core::event

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSESCROLL_HPP___
