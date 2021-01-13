/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Objects/AdvancedEnlightenedCube
** File description:
** Advanced enlightened
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_ADVANCEDENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_ADVANCEDENLIGHTENEDCUBE_HPP___

#include "../BasicShapes/Cube.hpp"



namespace engine::actor::object {



class AdvancedEnlightenedCube : public engine::actor::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit AdvancedEnlightenedCube(engine::Shader& shader, size_t numberOfPositions = 1);
    ~AdvancedEnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::actor::object



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_ADVANCEDENLIGHTENEDCUBE_HPP___
