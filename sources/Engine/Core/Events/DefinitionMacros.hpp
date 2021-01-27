/*
** Akanya, Engine
** sources/Engine/Events/DefinitionMacros
** just an helper of .hpps
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___



#define GET_CATEGORY(value) inline ::engine::core::event::Category getCategory() const override \
    { return ::engine::core::event::Category(value); }

#define GET_TYPE(value) \
    static inline ::engine::core::event::Type getStaticType() { return   ::engine::core::event::Type::value;  } \
    inline ::engine::core::event::Type getType() const override { return ::engine::core::event::Type::value;  } \
    inline std::string         getName() const override { return "::engine::core::event::"#value; }



#define WINDOW_EVENT(eventClass) \
    class Window##eventClass : public ::engine::core::event::AWindow { \
    public: \
        explicit Window##eventClass(); \
        GET_TYPE(Window##eventClass) \
    };



#define KEY_EVENT(eventClass) \
    class Key##eventClass : public ::engine::core::event::AKey { \
    public: \
        explicit Key##eventClass(int keyCode) : ::engine::core::event::AKey(keyCode) {} \
        GET_TYPE(Key##eventClass) \
    };



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___
