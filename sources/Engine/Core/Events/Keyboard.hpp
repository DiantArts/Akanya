//
// Akanya, Engine
// sources/Engine/Core/Events/Keyboard
// Every events of the keyboard category
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYBOARD_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYBOARD_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class AKey : public engine::core::AEvent {
public:
    explicit AKey(int keyCode) : m_keyCode(keyCode) {}

    ::engine::core::event::Category getCategory() const override { return m_category; }
    int getCode() const { return m_keyCode; }

private:
    int m_keyCode;
    constexpr ::engine::core::event::Category m_category { Input | Keyboard };

};

class KeyPressed : public ::engine::core::event::AKey {
public:
    explicit KeyPressed(int keyCode) : ::engine::core::event::AKey(keyCode) {}

    static ::engine::core::event::Type getStaticType() { return ::engine::core::event::Type::KeyPressed;  }
    ::engine::core::event::Type getType() const override { return ::engine::core::event::Type::KeyPressed;  }
    std::string getName() const override { return "::engine::core::event::KeyPressed"; }
};

class KeyReleased : public ::engine::core::event::AKey {
public:
    explicit KeyReleased(int keyCode) : ::engine::core::event::AKey(keyCode) {}

    static ::engine::core::event::Type getStaticType() { return ::engine::core::event::Type::KeyReleased; }
    ::engine::core::event::Type getType() const override { return ::engine::core::event::Type::KeyReleased; }
    std::string getName() const override { return "::engine::core::event::KeyReleased"; }
};



} // namespace engine::core::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_KEYBOARD_HPP___
