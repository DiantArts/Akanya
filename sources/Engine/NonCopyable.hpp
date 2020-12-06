/*
** EPITECH PROJECT, 2020
** NonCopyable
** File description:
** NonCopyable
*/

#pragma once

namespace engine {



class NonCopyable {
public:
    NonCopyable()                   = default;
    ~NonCopyable()                  = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};



} // namespace engine
