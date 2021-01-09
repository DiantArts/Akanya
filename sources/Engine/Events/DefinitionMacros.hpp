/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/DefinitionMacros
** File description:
** just an helper of .hpps
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___



#define GET_CATEGORY(value) inline engine::event::Category getCategory() const override \
    { return engine::event::Category(value); }

#define GET_TYPE(value) \
    static inline engine::event::Type getStaticType() { return   engine::event::Type::value;  } \
    inline engine::event::Type getType() const override { return engine::event::Type::value;  } \
    inline std::string         getName() const override { return "engine::event::"#value; }



#define WINDOW_EVENT(eventClass) \
    class Window##eventClass : public engine::event::AWindow { \
    public: \
        explicit Window##eventClass(); \
        GET_TYPE(Window##eventClass) \
    };



#define KEY_EVENT(eventClass) \
    class Key##eventClass : public engine::event::AKey { \
    public: \
        explicit Key##eventClass(int keyCode) : engine::event::AKey(keyCode) {} \
        GET_TYPE(Key##eventClass) \
    };



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_DEFINITIONMACROS_HPP___
