//
// Akanya
// sources/Engine/Core/Events/KeyPressed
// Event of a key pressed
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYPRESSED_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYPRESSED_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class KeyPressed
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit KeyPressed(
        int keyCode
    );

    ~KeyPressed();



    // ---------------------------------- Copy sementic

    KeyPressed(
        const KeyPressed&
    ) noexcept;

    auto operator=(
        const KeyPressed&
    ) noexcept -> KeyPressed&;



    // ---------------------------------- Copy sementic

    KeyPressed(
        KeyPressed&&
    ) noexcept;

    auto operator=(
        KeyPressed&&
    ) noexcept -> KeyPressed&;



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

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYPRESSED_HPP___
