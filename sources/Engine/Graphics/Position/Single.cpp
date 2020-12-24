/*
** EPITECH PROJECT, 2020
** Single
** File description:
** Single
*/

#include "Single.hpp"

#include <utility>

#include "debugMacros.hpp"



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

void Single::setPosition(const float positionX, const float positionY, const float positionZ)
{
    this->m_Position.x = std::move(positionX);
    this->m_Position.y = std::move(positionY);
    this->m_Position.z = std::move(positionZ);
}

void Single::setPosition(const glm::vec3& position)
{
    this->m_Position = position;
}

void Single::setPosition(glm::vec3&& position)
{
    this->m_Position = std::move(position);
}

void Single::setPosition(const engine::graphic::position::Single& position)
{
    this->m_Position = position.get();
}

void Single::setPosition(engine::graphic::position::Single&& position)
{
    this->m_Position = std::move(position.get());
}

//

void Single::setPositionX(const float position)
{
    this->m_Position.x = position;
}

void Single::setPositionY(const float position)
{
    this->m_Position.y = position;
}

void Single::setPositionZ(const float position)
{
    this->m_Position.z = position;
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



// ---------------------------------------------------------------------------- get

glm::vec3& Single::getPosition()
{
    return this->m_Position;
}

const glm::vec3& Single::getPosition() const
{
    return this->m_Position;
}



// ---------------------------------------------------------------------------- Iterator

engine::graphic::position::Single& Single::operator[](size_t index)
{
    if (index != 0) {
        throw std::out_of_range("trying to access a greater index than 0 of a single pos");
    }
    return *this;
}

const engine::graphic::position::Single& Single::operator[](size_t index) const
{
    if (index != 0) {
        throw std::out_of_range("trying to access a greater index than 0 of a single pos");
    }
    return *this;
}

engine::graphic::position::Single* Single::operator->()
{
    return this;
}

const engine::graphic::position::Single* Single::operator->() const
{
    return this;
}

//

engine::graphic::position::IPosition::iterator Single::begin()
{
    return engine::graphic::position::IPosition::iterator(this);
}

engine::graphic::position::IPosition::const_iterator Single::begin() const
{
    return engine::graphic::position::IPosition::const_iterator(this);
}

engine::graphic::position::IPosition::const_iterator Single::cbegin() const
{
    return engine::graphic::position::IPosition::const_iterator(this);
}

//

engine::graphic::position::IPosition::iterator Single::end()
{
    return engine::graphic::position::IPosition::iterator(this + 1);
}

engine::graphic::position::IPosition::const_iterator Single::end() const
{
    return engine::graphic::position::IPosition::const_iterator(this + 1);
}

engine::graphic::position::IPosition::const_iterator Single::cend() const
{
    return engine::graphic::position::IPosition::const_iterator(this + 1);
}




} // namespace engine::graphic::position
