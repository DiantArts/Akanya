/*
** Akanya, Engine
** sources/Engine/Events/Keyboard
** Every events of the keyboard category
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class AKey : public engine::core::AEvent {
public:
    explicit AKey(int keyCode) : m_keyCode(keyCode) {}

    GET_CATEGORY(Input | Keyboard)

    int getCode() const { return m_keyCode; }

private:
    int m_keyCode;
};

KEY_EVENT(Pressed)
KEY_EVENT(Released)



} // namespace engine::core::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_KEYBOARD_HPP___
