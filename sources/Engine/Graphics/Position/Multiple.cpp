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

Multiple::Multiple(const size_t sizeToAlloc)
{
    this->m_VectorPositions.reserve(sizeToAlloc);
}

Multiple::~Multiple()
{}



// ---------------------------------------------------------------------------- addPositions

void Multiple::add(const float posX, const float posY, const float posZ)
{
    this->m_VectorPositions.emplace_back(std::move(posX), std::move(posY), std::move(posZ));
}

void Multiple::add(const glm::vec3& position)
{
    this->m_VectorPositions.emplace_back(position);
}

void Multiple::add(glm::vec3&& position)
{
    this->m_VectorPositions.push_back(std::move(position));
}

void Multiple::add(const engine::graphic::position::Single& position)
{
    this->m_VectorPositions.push_back(position);
}

void Multiple::add(engine::graphic::position::Single&& position)
{
    this->m_VectorPositions.push_back(std::move(position));
}



// ---------------------------------------------------------------------------- std::vector

size_t Multiple::size() const
{
    return this->m_VectorPositions.size();
}



// ---------------------------------------------------------------------------- Iterator

engine::graphic::position::Single& Multiple::operator[](size_t index)
{
    return this->m_VectorPositions[index];
}

const engine::graphic::position::Single& Multiple::operator[](size_t index) const
{
    return this->m_VectorPositions[index];
}

engine::graphic::position::Single* Multiple::operator->()
{
    return &this->m_VectorPositions[0];
}

const engine::graphic::position::Single* Multiple::operator->() const
{
    return &this->m_VectorPositions[0];
}

//

engine::graphic::position::IPosition::iterator Multiple::begin()
{
    return engine::graphic::position::IPosition::iterator(&this->m_VectorPositions[0]);
}

engine::graphic::position::IPosition::const_iterator Multiple::begin() const
{
    return engine::graphic::position::IPosition::const_iterator(&this->m_VectorPositions[0]);
}

engine::graphic::position::IPosition::const_iterator Multiple::cbegin() const
{
    return engine::graphic::position::IPosition::const_iterator(&this->m_VectorPositions[0]);
}

//

engine::graphic::position::IPosition::iterator Multiple::end()
{
    return engine::graphic::position::IPosition::iterator(&this->m_VectorPositions[this->size()]);
}

engine::graphic::position::IPosition::const_iterator Multiple::end() const
{
    return engine::graphic::position::IPosition::const_iterator(&this->m_VectorPositions[this->size()]);
}

engine::graphic::position::IPosition::const_iterator Multiple::cend() const
{
    return engine::graphic::position::IPosition::const_iterator(&this->m_VectorPositions[this->size()]);
}



} // namespace engine::graphic::position
