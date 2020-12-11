/*
** EPITECH PROJECT, 2020
** Single
** File description:
** Single
*/

#include "Single.hpp"

#include <utility>



namespace engine::graphic::position {



// ---------------------------------------------------------------------------- *structors

Single::Single(const glm::vec3& position) : m_Position(position)
{}

Single::Single(glm::vec3&& position) : m_Position(std::move(position))
{}

Single::Single(const float positionX, const float positionY, const float positionZ)
    : m_Position(positionX, positionY, positionZ)
{}

Single::~Single()
{}



// ---------------------------------------------------------------------------- set

void Single::setPosition(const glm::vec3& position)
{
    this->m_Position = position;
}

void Single::setPosition(glm::vec3&& position)
{
    this->m_Position = std::move(position);
}

void Single::setPosition(const float positionX, const float positionY, const float positionZ)
{
    this->m_Position.x = positionX;
    this->m_Position.y = positionY;
    this->m_Position.z = positionZ;
}



// ---------------------------------------------------------------------------- get

const glm::vec3& Single::get() const
{
    return this->m_Position;
}



// ---------------------------------------------------------------------------- move
void Single::move(const glm::vec3& offset)
{
    this->m_Position += offset;
}

void Single::move(const float offsetX, const float offsetY, const float offsetZ)
{
    this->m_Position.x += offsetX;
    this->m_Position.y += offsetY;
    this->m_Position.z += offsetZ;
}

void Single::moveX(const float offset)
{
    this->m_Position.x += offset;
}

void Single::moveY(const float offset)
{
    this->m_Position.y += offset;
}

void Single::moveZ(const float offset)
{
    this->m_Position.z += offset;
}



} // namespace engine::graphic::position
