/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/AActor
** An actor is a drawable and a transformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___

#include "ADrawable.hpp"
#include "ATransformable.hpp"



namespace engine::graphic::actor {



class AActor
    : public engine::graphic::actor::ADrawable
    , public engine::graphic::actor::ATransformable {
public:
    // ---------------------------------- *structors
    AActor(::engine::graphic::opengl::Shader& shader, size_t numberOfPositions);
    virtual ~AActor() = 0;


    // ---------------------------------- Drawable
    glm::mat4    getModel(const glm::vec3& position) const; // just apply transform model
    virtual void drawModels(const engine::graphic::Camera& camera) const = 0;


    // ---------------------------------- Transformable
    virtual void update(float deltaTime); // just an empty definition


private:
};



} // namespace engine::graphic::actor



namespace engine::graphic { using AActor = engine::graphic::actor::AActor; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___
