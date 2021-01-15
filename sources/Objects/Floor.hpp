/*
** EPITECH PROJECT, 2020
** sources/Objects/Floor
** File description:
** Just a floor lol
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___

#include "Engine/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class Floor : public engine::actor::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Floor(engine::Shader& shader, size_t numberOfPositions = 1);
    ~Floor() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
