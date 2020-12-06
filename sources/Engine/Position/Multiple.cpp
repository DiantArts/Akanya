/*
** EPITECH PROJECT, 2020
** Multiple
** File description:
** multiple
*/

#include "Multiple.hpp"

#include <utility>



namespace engine::position {



// ---------------------------------------------------------------------------- *structors

Multiple::Multiple()
{}

Multiple::~Multiple()
{}



// ---------------------------------------------------------------------------- set == add

void Multiple::setPosition(const std::vector<glm::vec3>& vectorPositions)
{
    this->m_VectorPositions.reserve(vectorPositions.size());
    for (const auto& position : vectorPositions) {
        this->m_VectorPositions.emplace_back(position);
    }
}

void Multiple::setPosition(const std::vector<engine::position::Single>& vectorPositions)
{
    this->m_VectorPositions.reserve(vectorPositions.size());
    for (const auto& position : vectorPositions) {
        this->m_VectorPositions.emplace_back(position);
    }
}

void Multiple::setPosition(const engine::position::Multiple& vectorPositions)
{
    this->m_VectorPositions.reserve(vectorPositions.size());
    for (const auto& position : vectorPositions) {
        this->m_VectorPositions.emplace_back(position);
    }
}



void Multiple::setPosition(const glm::vec3& position)
{
    this->m_VectorPositions.emplace_back(position);
}

void Multiple::setPosition(glm::vec3&& position)
{
    this->m_VectorPositions.push_back(std::move(position));
}

void Multiple::setPosition(const float posX, const float posY, const float posZ)
{
    this->m_VectorPositions.emplace_back(posX, posY, posZ);
}



// ---------------------------------------------------------------------------- get

const std::vector<engine::position::Single>& Multiple::getPosition() const
{
    return this->m_VectorPositions;
}



// ---------------------------------------------------------------------------- std::vector

size_t Multiple::size() const
{
    return this->m_VectorPositions.size();
}



std::vector<engine::position::Single>::iterator Multiple::begin()
{
    return this->m_VectorPositions.begin();
}

std::vector<engine::position::Single>::iterator Multiple::end()
{
    return this->m_VectorPositions.end();
}

std::vector<engine::position::Single>::const_iterator Multiple::begin() const
{
    return this->m_VectorPositions.begin();
}

std::vector<engine::position::Single>::const_iterator Multiple::end() const
{
    return this->m_VectorPositions.end();
}

std::vector<engine::position::Single>::const_iterator Multiple::cbegin() const
{
    return this->m_VectorPositions.cbegin();
}

std::vector<engine::position::Single>::const_iterator Multiple::cend() const
{
    return this->m_VectorPositions.cend();
}



} // namespace engine::position
