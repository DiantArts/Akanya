/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/AEvent
** File description:
** Event main class that defines what an event is and that should be inherient from every events
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_AEVENT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_AEVENT_HPP___

#include "../Events/Category.hpp"
#include "../Events/DefinitionMacros.hpp"
#include "../Events/Type.hpp"



namespace engine::event {



class AEvent {
public:
    // ---------------------------------------------------------------------------- *structors
    virtual ~AEvent() = 0;


    // ---------------------------------------------------------------------------- Category
    bool isOfCategory(engine::event::Category category) const;


    // ---------------------------------------------------------------------------- Get
    virtual engine::event::Category getCategory() const = 0;
    virtual engine::event::Type     getType() const     = 0;
    virtual std::string             getName() const     = 0;


    // ---------------------------------------------------------------------------- Dispatcher
    template <typename EventType>
    bool handleWith(std::function<void(EventType&)>& func)
    {
        if (this->getType() == EventType::getStaticType()) {
            func(*(EventType*)this);
            return true;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const AEvent& event)
    {
        os << event.getName();
        return os;
    }
};



} // namespace engine::event

namespace engine {
using AEvent = engine::event::AEvent;
}



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_AEVENT_HPP___
