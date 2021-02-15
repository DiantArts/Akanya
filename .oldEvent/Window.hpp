//
// Akanya, Engine
// sources/Engine/Core/Events/Window
// Every events of the window category
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_WINDOW_HPP___

#include "AEvent.hpp"



namespace engine::core::event {



class AWindow : public engine::core::AEvent {
public:
    virtual ~AWindow() = 0;
    GET_CATEGORY(::engine::core::event::Category::Application | ::engine::core::event::Category::Window)
};

WINDOW_EVENT(Close)
WINDOW_EVENT(Resize)
WINDOW_EVENT(Focus)
WINDOW_EVENT(LostFocus)
WINDOW_EVENT(Moved)



} // namespace engine::core::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_WINDOW_HPP___
