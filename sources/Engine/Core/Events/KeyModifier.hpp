//
// Akanya
// sources/Engine/Core/Events/KeyModifier
// Event of a key pressed
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYMODIFIER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYMODIFIER_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class KeyModifier
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit KeyModifier(
        int keyCode
    );

    ~KeyModifier();



    // ---------------------------------- Copy sementic

    KeyModifier(
        const KeyModifier&
    ) noexcept;

    auto operator=(
        const KeyModifier&
    ) noexcept -> KeyModifier&;



    // ---------------------------------- Copy sementic

    KeyModifier(
        KeyModifier&&
    ) noexcept;

    auto operator=(
        KeyModifier&&
    ) noexcept -> KeyModifier&;



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

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYMODIFIER_HPP___
