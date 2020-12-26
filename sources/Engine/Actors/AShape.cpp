/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shape
** File description:
** Shape
*/

#include "AShape.hpp"



// ---------------------------------------------------------------------------- *structors

Shape::Shape(engine::Shader& shader, const size_t numberOfPositions)
    : engine::actor::Drawable(shader), engine::actor::Transformable(numberOfPositions)
{}

Shape::~Shape()
{}



// ---------------------------------------------------------------------------- Drawable

glm::mat4 Shape::getModel(const glm::vec3& position) const
{
    return this->transformModel(position);
}



// ---------------------------------------------------------------------------- Transformable

void Shape::update(float)
{}
