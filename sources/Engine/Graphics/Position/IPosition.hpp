/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Position/IPosition
** File description:
** Interface
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_IPOSITION_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_IPOSITION_HPP___

#include "Tools/Iterator.hpp"



namespace engine::graphic::position {

class Single;



class IPosition : public tool::Iterator<engine::graphic::position::Single> {
public:
    virtual engine::graphic::position::Single& operator[](size_t index)             = 0;
    virtual const engine::graphic::position::Single& operator[](size_t index) const = 0;
    virtual engine::graphic::position::Single* operator->()                         = 0;
    virtual const engine::graphic::position::Single* operator->() const             = 0;
};



} // namespace engine::graphic::position



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_IPOSITION_HPP___
