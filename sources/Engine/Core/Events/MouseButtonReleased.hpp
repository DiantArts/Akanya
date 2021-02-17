//
// Akanya
// sources/Engine/Core/Events/MouseButtonReleased
// Event of a mouse released
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONRELEASED_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONRELEASED_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class MouseButtonReleased
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit MouseButtonReleased(
        int keyCode
    );

    ~MouseButtonReleased();



    // ---------------------------------- Copy sementic

    MouseButtonReleased(
        const MouseButtonReleased&
    ) noexcept;

    auto operator=(
        const MouseButtonReleased&
    ) noexcept -> MouseButtonReleased&;



    // ---------------------------------- Copy sementic

    MouseButtonReleased(
        MouseButtonReleased&&
    ) noexcept;

    auto operator=(
        MouseButtonReleased&&
    ) noexcept -> MouseButtonReleased&;



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

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEBUTTONRELEASED_HPP___
