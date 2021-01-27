/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Positions
** File description:
** A vector of position that allow multiple draw from the same object
*/

#include "pch.hpp"

#include "Positions.hpp"


namespace engine::actor {


// ---------------------------------------------------------------------------- *structors

Positions::Positions(const size_t sizeToAlloc)
{
    if (sizeToAlloc > 1) {
        auto& multiplePos { m_Variant.emplace<MultiplePositions>() };
        multiplePos.resize(sizeToAlloc);
    } else {
        m_Variant = SinglePosition { 0.0F, 0.0F, 0.0F };
    }
}

Positions::~Positions()
{}



// ---------------------------------------------------------------------------- Access

glm::vec3& Positions::operator[](size_t index)
{
    if (auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        if (index > 0) {
            throw std::out_of_range("trying to access a greater index than 0 of a single pos");
        }
        return *position;
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        if (positions.size() <= index) {
            throw std::out_of_range("trying to access a greater index the vector size");
        }
        return positions[index];
    }
}

const glm::vec3& Positions::operator[](size_t index) const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        if (index > 0) {
            throw std::out_of_range("trying to access a greater index than 0 of a single pos");
        }
        return *position;
    } else {
        const auto& positions { std::get<MultiplePositions>(m_Variant) };
        if (positions.size() <= index) {
            throw std::out_of_range("trying to access a greater index the vector size");
        }
        return positions[index];
    }
}

//

glm::vec3* Positions::operator->()
{
    if (auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return position;
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        if (positions.empty()) {
            throw std::out_of_range("trying to access elements of an empty vector");
        }
        return &positions[0];
    }
}

const glm::vec3* Positions::operator->() const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return position;
    } else {
        const auto& positions { std::get<MultiplePositions>(m_Variant) };
        if (positions.empty()) {
            throw std::out_of_range("trying to access elements of an empty vector");
        }
        return &positions[0];
    }
}



// ---------------------------------------------------------------------------- Iterator

engine::actor::Positions::iterator Positions::begin()
{
    if (auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::iterator(position);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::iterator(&positions[0]);
    }
}

engine::actor::Positions::const_iterator Positions::begin() const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::const_iterator(position);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::const_iterator(&positions[0]);
    }
}

engine::actor::Positions::const_iterator Positions::cbegin() const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::const_iterator(position);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::const_iterator(&positions[0]);
    }
}

//

engine::actor::Positions::iterator Positions::end()
{
    if (auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::iterator(position + 1);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::iterator(&positions[positions.size()]);
    }
}

engine::actor::Positions::const_iterator Positions::end() const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::const_iterator(position + 1);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::const_iterator(&positions[positions.size()]);
    }
}

engine::actor::Positions::const_iterator Positions::cend() const
{
    if (const auto* position { std::get_if<SinglePosition>(&m_Variant) }) {
        return engine::actor::Positions::const_iterator(position + 1);
    } else {
        auto& positions { std::get<MultiplePositions>(m_Variant) };
        return engine::actor::Positions::const_iterator(&positions[positions.size()]);
    }
}



// ---------------------------------------------------------------------------- AddPosition

void Positions::addPosition(float x, float y, float z)
{
    try {
        auto& multiplePos { std::get<MultiplePositions>(m_Variant) };
        multiplePos.emplace_back(std::move(x), std::move(y), std::move(z));
    } catch (const std::bad_variant_access&) {
        auto  singlePos { std::get<SinglePosition>(m_Variant) };
        auto& multiplePos { m_Variant.emplace<MultiplePositions>() };
        multiplePos.reserve(2);
        multiplePos.push_back(std::move(singlePos));
        multiplePos.emplace_back(std::move(x), std::move(y), std::move(z));
    }
}

void Positions::addPosition(const glm::vec3& position)
{
    try {
        auto& multiplePos { std::get<MultiplePositions>(m_Variant) };
        multiplePos.push_back(position);
    } catch (const std::bad_variant_access&) {
        auto  singlePos { std::get<SinglePosition>(m_Variant) };
        auto& multiplePos { m_Variant.emplace<MultiplePositions>() };
        multiplePos.reserve(2);
        multiplePos.push_back(std::move(singlePos));
        multiplePos.push_back(position);
    }
}

void Positions::addPosition(glm::vec3&& position)
{
    try {
        auto& multiplePos { std::get<MultiplePositions>(m_Variant) };
        multiplePos.push_back(std::move(position));
    } catch (const std::bad_variant_access&) {
        auto  singlePos { std::get<SinglePosition>(m_Variant) };
        auto& multiplePos { m_Variant.emplace<MultiplePositions>() };
        multiplePos.reserve(2);
        multiplePos.push_back(std::move(singlePos));
        multiplePos.push_back(std::move(position));
    }
}



// ---------------------------------------------------------------------------- SetPosition

void Positions::setPosition(const glm::vec3& position)
{
    (*this)[0] = position;
}

void Positions::setPosition(glm::vec3&& position)
{
    (*this)[0] = std::move(position);
}

void Positions::setPosition(const float positionX, const float positionY, const float positionZ)
{
    auto& pos { (*this)[0] };
    pos.x = std::move(positionX);
    pos.y = std::move(positionY);
    pos.z = std::move(positionZ);
}

//

void Positions::setPositionX(const float positionX)
{
    (*this)[0].x = std::move(positionX);
}

void Positions::setPositionY(const float positionY)
{
    (*this)[0].y = std::move(positionY);
}

void Positions::setPositionZ(const float positionZ)
{
    (*this)[0].z = std::move(positionZ);
}



// ---------------------------------------------------------------------------- Move

void Positions::move(const glm::vec3& offset)
{
    (*this)[0] += offset;
}

void Positions::move(const float offsetX, const float offsetY, const float offsetZ)
{
    auto& pos { (*this)[0] };
    pos.x += std::move(offsetX);
    pos.y += std::move(offsetY);
    pos.z += std::move(offsetZ);
}

//

void Positions::moveX(const float offsetX)
{
    (*this)[0].x += offsetX;
}

void Positions::moveY(const float offsetY)
{
    (*this)[0].x += offsetY;
}

void Positions::moveZ(const float offsetZ)
{
    (*this)[0].x += offsetZ;
}



// ---------------------------------------------------------------------------- Size

size_t Positions::size() const
{
    if (const auto* positions { std::get_if<MultiplePositions>(&m_Variant) }) {
        return positions->size();
    } else {
        return 1;
    }
}



} // namespace engine::actor
