//
// Akanya
// sources/Engine/Core/Events/AEvent
// Base class of every event
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_AEVENTS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_AEVENTS_HPP___

#include "Type.hpp"



namespace engine::graphic { class AScene; }



namespace engine::core::event {



class AEvent {

public:

    // ---------------------------------- *structors

    explicit AEvent();

    virtual ~AEvent() = 0;



    // ---------------------------------- Copy sementic

    AEvent(
        const AEvent&
    ) noexcept;

    auto operator=(
        const AEvent&
    ) noexcept -> AEvent&;



    // ---------------------------------- Copy sementic

    AEvent(
        AEvent&&
    ) noexcept;

    auto operator=(
        AEvent&&
    ) noexcept -> AEvent&;



    // ---------------------------------- Resolver

    virtual void resolve(
        engine::graphic::AScene& scene
    ) = 0;



public:
protected:
protected:
private:
private:

};



} // namespace engine::core::event



namespace engine::core { using AEvent = ::engine::core::event::AEvent; }

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_AEVENTS_HPP___
