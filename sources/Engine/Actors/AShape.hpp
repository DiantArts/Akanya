/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/AShape
** File description:
** A shape is drawable and transformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ASHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ASHAPE_HPP___

#include "ADrawable.hpp"
#include "ATransformable.hpp"



namespace engine::actor {



class AShape
    : public engine::actor::ADrawable
    , public engine::actor::ATransformable {
public:
    // ---------------------------------------------------------------------------- *structors
    AShape(engine::Shader& shader, size_t numberOfPositions);
    virtual ~AShape() = 0;


    // ---------------------------------------------------------------------------- Drawable
    glm::mat4    getModel(const glm::vec3& position) const; // just apply transform model
    virtual void drawModels(const engine::Camera& camera) const = 0;


    // ---------------------------------------------------------------------------- Transformable
    virtual void update(float deltaTime);


private:
};



} // namespace engine::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ASHAPE_HPP___
