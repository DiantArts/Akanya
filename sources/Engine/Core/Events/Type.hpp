//
// Akanya, Engine
// sources/Engine/Core/Events/Type
// Defines every event types that exist
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_TYPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_TYPE_HPP___



namespace engine::core::event {



enum class Type {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};



} // namespace engine::core::event




#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_TYPE_HPP___
