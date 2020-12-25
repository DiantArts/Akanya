/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shape
** File description:
** Shape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPE_HPP___



#include "Drawable.hpp"
#include "Transformable.hpp"



namespace engine::graphic {



class Shape
    : public engine::graphic::Drawable
    , public engine::graphic::Transformable {
public:
    // ---------------------------------------------------------------------------- *structors
    Shape(engine::Shader& shader, size_t numberOfPositions) virtual ~Shape() = 0;


    // ---------------------------------------------------------------------------- Drawable
    virtual void      drawModels(const engine::Camera& camera) const = 0;
    virtual glm::mat4 getModel(const glm::vec3& position) const override; // just apply transform model


    // ---------------------------------------------------------------------------- Transformable
    virtual void update(float deltaTime);


private:
};



} // namespace engine::graphic

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPE_HPP___
