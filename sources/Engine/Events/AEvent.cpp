/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/AEvent
** File description:
** Event main class that defines what an event is and that should be inherient from every events
*/

#include "AEvent.hpp"



namespace engine::event {



// ---------------------------------------------------------------------------- *structors

AEvent::~AEvent()
{}



// ---------------------------------------------------------------------------- Category

bool AEvent::isOfCategory(engine::event::Category category) const
{
    return this->getCategory() & category;
}




} // namespace engine::event
