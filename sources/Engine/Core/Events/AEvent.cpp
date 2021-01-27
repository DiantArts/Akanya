/*
** Akanya, Engine
** sources/Engine/Events/AEvent
** Event main class that defines what an event is and that should be inherient from every events
*/

#include "pch.hpp"

#include "AEvent.hpp"



namespace engine::core::event {



// ---------------------------------- *structors

AEvent::~AEvent()
{}



// ---------------------------------- Category

bool AEvent::isOfCategory(::engine::core::event::Category category) const
{
    return this->getCategory() & category;
}




} // namespace engine::core::event
