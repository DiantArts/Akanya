/*
** EPITECH PROJECT, 2020
** threadPool
** File description:
** control a thread execution
*/

#include "threadPool.hpp"

static std::uint_fast8_t threadsId = 1;

threadPool::threadPool()
    : id(threadsId++)
{}

threadPool::~threadPool()
{}
