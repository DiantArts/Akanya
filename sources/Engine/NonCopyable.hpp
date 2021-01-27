/*
** EPITECH PROJECT, 2020
** sources/Engine/NonCopyable
** File description:
** Turns inheriting classes NonCopyable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NONCOPYABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NONCOPYABLE_HPP___

namespace engine {



class NonCopyable {
public:
    NonCopyable()                   = default;
    ~NonCopyable()                  = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NONCOPYABLE_HPP___
