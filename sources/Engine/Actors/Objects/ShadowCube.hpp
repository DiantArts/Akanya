/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Objects/ShadowCube
** File description:
** ShadowCube testing
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_SHADOWCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_SHADOWCUBE_HPP___

#include "../BasicShapes/Cube.hpp"



namespace engine::actor::object {



class ShadowCube : public engine::actor::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit ShadowCube(engine::Shader& shader, size_t numberOfPositions = 1);
    ~ShadowCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::actor::object



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_SHADOWCUBE_HPP___
