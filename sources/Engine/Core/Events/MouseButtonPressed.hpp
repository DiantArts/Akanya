//
// Akanya
// sources/Engine/Core/Events/MouseButtonPressed
// Event of a mouse pressed
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONPRESSED_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONPRESSED_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class MouseButtonPressed
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit MouseButtonPressed(
        int keyCode
    );

    ~MouseButtonPressed();



    // ---------------------------------- Copy sementic

    MouseButtonPressed(
        const MouseButtonPressed&
    ) noexcept;

    auto operator=(
        const MouseButtonPressed&
    ) noexcept -> MouseButtonPressed&;



    // ---------------------------------- Copy sementic

    MouseButtonPressed(
        MouseButtonPressed&&
    ) noexcept;

    auto operator=(
        MouseButtonPressed&&
    ) noexcept -> MouseButtonPressed&;



    // ---------------------------------- Resolver

    virtual void resolve(
        engine::graphic::AScene& scene
    ) override final;



public:
protected:
protected:
private:
private:

    int m_keyCode;

};



} // namespace engine::core::event

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONPRESSED_HPP___
