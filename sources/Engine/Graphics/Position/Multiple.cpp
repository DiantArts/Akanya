/*
** EPITECH PROJECT, 2020
** Multiple
** File description:
** multiple
*/

#include "Multiple.hpp"

#include <utility>



namespace engine::graphic::position {



// ---------------------------------------------------------------------------- *structors

Multiple::Multiple()
{}

Multiple::~Multiple()
{}



// ---------------------------------------------------------------------------- set == add

void Multiple::addPosition(const glm::vec3& position)
{
    this->m_VectorPositions.emplace_back(position);
}

void Multiple::addPosition(glm::vec3&& position)
{
    this->m_VectorPositions.push_back(std::move(position));
}

void Multiple::addPosition(const float posX, const float posY, const float posZ)
{
    this->m_VectorPositions.emplace_back(posX, posY, posZ);
}



// ---------------------------------------------------------------------------- std::vector

size_t Multiple::size() const
{
    return this->m_VectorPositions.size();
}



std::vector<engine::graphic::position::Single>::iterator Multiple::begin()
{
    return this->m_VectorPositions.begin();
}

std::vector<engine::graphic::position::Single>::iterator Multiple::end()
{
    return this->m_VectorPositions.end();
}

std::vector<engine::graphic::position::Single>::const_iterator Multiple::begin() const
{
    return this->m_VectorPositions.begin();
}

std::vector<engine::graphic::position::Single>::const_iterator Multiple::end() const
{
    return this->m_VectorPositions.end();
}

std::vector<engine::graphic::position::Single>::const_iterator Multiple::cbegin() const
{
    return this->m_VectorPositions.cbegin();
}

std::vector<engine::graphic::position::Single>::const_iterator Multiple::cend() const
{
    return this->m_VectorPositions.cend();
}



engine::graphic::position::Single& Multiple::operator[](size_t i)
{
    return this->m_VectorPositions[i];
}

const engine::graphic::position::Single& Multiple::operator[](size_t i) const
{
    return this->m_VectorPositions[i];
}



} // namespace engine::graphic::position
