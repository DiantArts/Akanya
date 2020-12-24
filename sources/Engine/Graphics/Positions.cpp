/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Positions
** File description:
** Positions
*/

#include "Positions.hpp"

#include <iostream>


namespace engine::graphic {


// ---------------------------------------------------------------------------- *structors

Positions::Positions(const size_t sizeToAlloc)
{
    if (sizeToAlloc > 1) {
        this->m_Variant = engine::graphic::position::Multiple { sizeToAlloc };
    } else {
        this->m_Variant = engine::graphic::position::Single {};
    }
}

Positions::~Positions()
{}



// ---------------------------------------------------------------------------- override

void Positions::add(float x, float y, float z)
{
    try {
        auto& multiplePos { std::get<engine::graphic::position::Multiple>(this->m_Variant) };
        multiplePos.add(std::move(x), std::move(y), std::move(z));
    } catch (const std::bad_variant_access&) {
        auto singlePos { std::get<engine::graphic::position::Single>(this->m_Variant) };
        auto& multiplePos { this->m_Variant.emplace<engine::graphic::position::Multiple>(2) };
        multiplePos.add(std::move(singlePos));
        multiplePos.add(std::move(x), std::move(y), std::move(z));
    }
}

void Positions::add(const glm::vec3& position)
{
    try {
        auto& multiplePos { std::get<engine::graphic::position::Multiple>(this->m_Variant) };
        multiplePos.add(position);
    } catch (const std::bad_variant_access&) {
        auto singlePos { std::get<engine::graphic::position::Single>(this->m_Variant) };
        auto& multiplePos { this->m_Variant.emplace<engine::graphic::position::Multiple>(2) };
        multiplePos.add(std::move(singlePos));
        multiplePos.add(position);
    }
}

void Positions::add(glm::vec3&& position)
{
    try {
        auto& multiplePos { std::get<engine::graphic::position::Multiple>(this->m_Variant) };
        multiplePos.add(std::move(position));
    } catch (const std::bad_variant_access&) {
        auto singlePos { std::get<engine::graphic::position::Single>(this->m_Variant) };
        auto& multiplePos { this->m_Variant.emplace<engine::graphic::position::Multiple>(2) };
        multiplePos.add(std::move(singlePos));
        multiplePos.add(std::move(position));
    }
}

void Positions::add(const engine::graphic::position::Single& position)
{
    try {
        auto& multiplePos { std::get<engine::graphic::position::Multiple>(this->m_Variant) };
        multiplePos.add(position);
    } catch (const std::bad_variant_access&) {
        auto singlePos { std::get<engine::graphic::position::Single>(this->m_Variant) };
        auto& multiplePos { this->m_Variant.emplace<engine::graphic::position::Multiple>(2) };
        multiplePos.add(std::move(singlePos));
        multiplePos.add(position);
    }
}

void Positions::add(engine::graphic::position::Single&& position)
{
    try {
        auto& multiplePos { std::get<engine::graphic::position::Multiple>(this->m_Variant) };
        multiplePos.add(std::move(position));
    } catch (const std::bad_variant_access&) {
        auto singlePos { std::get<engine::graphic::position::Single>(this->m_Variant) };
        auto& multiplePos { this->m_Variant.emplace<engine::graphic::position::Multiple>(2) };
        multiplePos.add(std::move(singlePos));
        multiplePos.add(std::move(position));
    }
}

//

engine::graphic::position::Single& Positions::operator[](size_t index)
{
    return std::visit(
            [&index](auto& p) -> engine::graphic::position::Single& { return p[std::move(index)]; },
            this->m_Variant);
}

const engine::graphic::position::Single& Positions::operator[](size_t index) const
{
    return std::visit(
            [&index](auto& p) -> const engine::graphic::position::Single& { return p[std::move(index)]; },
            this->m_Variant);
}

engine::graphic::position::Single* Positions::operator->()
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::Single* { return p.operator->(); }, this->m_Variant);
}

const engine::graphic::position::Single* Positions::operator->() const
{
    return std::visit(
            [](auto& p) -> const engine::graphic::position::Single* { return p.operator->(); },
            this->m_Variant);
}

//

engine::graphic::position::IPosition::iterator Positions::begin()
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::iterator { return p.begin(); },
            this->m_Variant);
}

engine::graphic::position::IPosition::const_iterator Positions::begin() const
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::const_iterator { return p.begin(); },
            this->m_Variant);
}

engine::graphic::position::IPosition::const_iterator Positions::cbegin() const
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::const_iterator { return p.cbegin(); },
            this->m_Variant);
}

//

engine::graphic::position::IPosition::iterator Positions::end()
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::iterator { return p.end(); },
            this->m_Variant);
}

engine::graphic::position::IPosition::const_iterator Positions::end() const
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::const_iterator { return p.end(); },
            this->m_Variant);
}

engine::graphic::position::IPosition::const_iterator Positions::cend() const
{
    return std::visit(
            [](auto& p) -> engine::graphic::position::IPosition::const_iterator { return p.cend(); },
            this->m_Variant);
}



} // engine::graphic
