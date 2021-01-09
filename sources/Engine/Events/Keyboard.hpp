/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/Keyboard
** File description:
** Every events of the keyboard category
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___

#include "AEvent.hpp"



namespace engine::event {



class AKey : public engine::AEvent {
public:
    explicit AKey(int keyCode) : m_KeyCode(keyCode) {}

    GET_CATEGORY(Input | Keyboard)

    int getCode() const { return this->m_KeyCode; }

private:
    int m_KeyCode;
};

KEY_EVENT(Pressed)
KEY_EVENT(Released)



} // namespace engine::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___
