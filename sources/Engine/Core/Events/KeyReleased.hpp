//
// Akanya
// sources/Engine/Core/Events/KeyReleased
// Event of a key pressed
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYRELEASED_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYRELEASED_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class KeyReleased
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit KeyReleased(
        int keyCode
    );

    ~KeyReleased();



    // ---------------------------------- Copy sementic

    KeyReleased(
        const KeyReleased&
    ) noexcept;

    auto operator=(
        const KeyReleased&
    ) noexcept -> KeyReleased&;



    // ---------------------------------- Copy sementic

    KeyReleased(
        KeyReleased&&
    ) noexcept;

    auto operator=(
        KeyReleased&&
    ) noexcept -> KeyReleased&;



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

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYRELEASED_HPP___
