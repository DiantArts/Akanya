/*
** EPITECH PROJECT, 2020
** sources/Objects/EnlightenedCube
** File description:
** An enlightened cube lol
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___

#include "Engine/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class EnlightenedCube : public engine::actor::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit EnlightenedCube(engine::Shader& shader, size_t numberOfPositions = 1);
    ~EnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
