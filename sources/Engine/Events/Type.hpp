/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/Type
** File description:
** Defines every event types that exist
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_TYPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_TYPE_HPP___



namespace engine::event {



enum class Type {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};



} // namespace engine::event




#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_TYPE_HPP___
