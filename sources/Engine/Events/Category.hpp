/*
** EPITECH PROJECT, 2020
** sources/Engine/Events/Category
** File description:
** Defines every event category that exist
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_CATEGORY_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_CATEGORY_HPP___



namespace engine::event {


#define BIT_SHIFT(x) (1 << x)

enum Category {
    None        = 0,
    Application = BIT_SHIFT(1),
    Input       = BIT_SHIFT(2),
    Keyboard    = BIT_SHIFT(3),
    Mouse       = BIT_SHIFT(4),
    MouseButton = BIT_SHIFT(5),
    Window      = BIT_SHIFT(6),
};



} // namespace engine::event



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_EVENTS_CATEGORY_HPP___
