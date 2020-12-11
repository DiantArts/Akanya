/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Transformable
** File description:
** Transformable
*/

#include "Transformable.hpp"



namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Transformable::Transformable(const bool isMultiplePosition)
{
    if (isMultiplePosition) {
        this->m_MultiplePositions = std::make_unique<engine::graphic::position::Multiple>();
    } else {
        this->m_SinglePosition = std::make_unique<engine::graphic::position::Single>();
    }
}

Transformable::~Transformable()
{}



// ---------------------------------------------------------------------------- Scale

void Transformable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x = scaleX;
    this->m_Scale.y = scaleY;
    this->m_Scale.z = scaleZ;
}

void Transformable::setScale(const glm::vec3& scale)
{
    this->m_Scale = scale;
}

void Transformable::setScale(glm::vec3&& scale)
{
    this->m_Scale = std::move(scale);
}

const glm::vec3& Transformable::getScale() const
{
    return this->m_Scale;
}


// ---------------------------------------------------------------------------- position
bool Transformable::isMultiplePositions() const
{
    return this->m_MultiplePositions != nullptr;
}

const engine::graphic::position::Single& Transformable::getPosition() const
{
    if (this->isMultiplePositions()) {
        throw std::runtime_error("trying to get multiple positions from a simple position shape");
    }
    return *this->m_SinglePosition;
}

const engine::graphic::position::Multiple& Transformable::getPositions() const
{
    if (!this->isMultiplePositions()) {
        throw std::runtime_error("trying to get a single positions from a multiple position shape");
    }
    return *this->m_MultiplePositions;
}



} // namespace engine::graphic
