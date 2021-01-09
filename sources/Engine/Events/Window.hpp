/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/Window
** File description:
** Every events of the window category
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_WINDOW_HPP___

#include "AEvent.hpp"



namespace engine::event {



class AWindow : public engine::AEvent {
public:
    virtual ~AWindow() = 0;
    GET_CATEGORY(engine::event::Category::Application | engine::event::Category::Window)
};

WINDOW_EVENT(Close)
WINDOW_EVENT(Resize)
WINDOW_EVENT(Focus)
WINDOW_EVENT(LostFocus)
WINDOW_EVENT(Moved)



} // namespace engine::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_WINDOW_HPP___
