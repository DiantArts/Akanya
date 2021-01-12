/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/AActor
** File description:
** An actor is a drawable and a transformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_AACTOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_AACTOR_HPP___

#include "ADrawable.hpp"
#include "ATransformable.hpp"



namespace engine::actor {



class AActor
    : public engine::actor::ADrawable
    , public engine::actor::ATransformable {
public:
    // ---------------------------------------------------------------------------- *structors
    AActor(engine::Shader& shader, size_t numberOfPositions);
    virtual ~AActor() = 0;


    // ---------------------------------------------------------------------------- Drawable
    glm::mat4    getModel(const glm::vec3& position) const; // just apply transform model
    virtual void drawModels(const engine::Camera& camera) const = 0;


    // ---------------------------------------------------------------------------- Transformable
    virtual void update(float deltaTime); // just an empty definition


private:
};



} // namespace engine::actor



namespace engine { using AActor = engine::actor::AActor; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_AACTOR_HPP___
