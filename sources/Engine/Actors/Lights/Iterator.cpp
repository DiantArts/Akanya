/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Iterator
** File description:
** help to iterate over an ALight
*/

#include "Iterator.hpp"

#include "Container.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- iterator

Iterator::iterator::iterator(engine::actor::light::ContainerWrapper* ptr) : m_Ptr(std::move(ptr))
{}

engine::actor::light::Iterator::LightReferenceWrapper Iterator::iterator::operator*()
{
    std::string name;
    if (m_Ptr->instances.size() <= 1) {
        name += m_Ptr->name;
    } else if (m_Index < 10) {
        name.reserve(m_Ptr->name.size() + 3);
        name += m_Ptr->name;
        name += '[';
        name += m_Index + '0';
        name += ']';
    } else {
        name.reserve(m_Ptr->name.size() + 4);
        name += m_Ptr->name;
        name += '[';
        name += std::to_string(m_Index);
        name += ']';
    }
    return engine::actor::light::Iterator::LightReferenceWrapper { m_Ptr->parameters,
                                                                   m_Ptr->instances[m_Index],
                                                                   std::move(name) };
}

engine::actor::light::Iterator::LightReferenceWrapper Iterator::iterator::operator->()
{
    std::string name;
    if (m_Ptr->instances.size() <= 1) {
        name += m_Ptr->name;
    } else if (m_Index < 10) {
        name.reserve(m_Ptr->name.size() + 3);
        name += m_Ptr->name;
        name += '[';
        name += m_Index + '0';
        name += ']';
    } else {
        name.reserve(m_Ptr->name.size() + 4);
        name += m_Ptr->name;
        name += '[';
        name += std::to_string(m_Index);
        name += ']';
    }
    return engine::actor::light::Iterator::LightReferenceWrapper { m_Ptr->parameters,
                                                                   m_Ptr->instances[m_Index],
                                                                   std::move(name) };
}

engine::actor::light::Iterator::iterator& Iterator::iterator::operator++()
{
    if (++m_Index >= m_Ptr->instances.size()) {
        m_Index = 0;
        m_Ptr++;
    }
    return *this;
}

engine::actor::light::Iterator::iterator Iterator::iterator::operator++(int)
{
    auto tmp = *this;
    ++(*this);
    return tmp;
}

bool Iterator::iterator::operator==(const engine::actor::light::Iterator::iterator& that)
{
    return m_Ptr == that.m_Ptr;
}

bool Iterator::iterator::operator!=(const engine::actor::light::Iterator::iterator& that)
{
    return m_Ptr != that.m_Ptr;
}



// ---------------------------------------------------------------------------- const_iterator

Iterator::const_iterator::const_iterator(const engine::actor::light::ContainerWrapper* ptr)
    : m_Ptr(std::move(ptr))
{}

engine::actor::light::Iterator::LightReferenceWrapper Iterator::const_iterator::operator*()
{
    std::string name;
    if (m_Ptr->instances.size() <= 1) {
        name += m_Ptr->name;
    } else if (m_Index < 10) {
        name.reserve(m_Ptr->name.size() + 3);
        name += m_Ptr->name;
        name += '[';
        name += m_Index + '0';
        name += ']';
    } else {
        name.reserve(m_Ptr->name.size() + 4);
        name += m_Ptr->name;
        name += '[';
        name += std::to_string(m_Index);
        name += ']';
    }
    return engine::actor::light::Iterator::LightReferenceWrapper { m_Ptr->parameters,
                                                                   m_Ptr->instances[m_Index],
                                                                   std::move(name) };
}

engine::actor::light::Iterator::LightReferenceWrapper Iterator::const_iterator::operator->()
{
    std::string name;
    if (m_Ptr->instances.size() <= 1) {
        name += m_Ptr->name;
    } else if (m_Index < 10) {
        name.reserve(m_Ptr->name.size() + 3);
        name += m_Ptr->name;
        name += '[';
        name += m_Index + '0';
        name += ']';
    } else {
        name.reserve(m_Ptr->name.size() + 4);
        name += m_Ptr->name;
        name += '[';
        name += std::to_string(m_Index);
        name += ']';
    }
    return engine::actor::light::Iterator::LightReferenceWrapper { m_Ptr->parameters,
                                                                   m_Ptr->instances[m_Index],
                                                                   std::move(name) };
}

const engine::actor::light::Iterator::const_iterator& Iterator::const_iterator::operator++()
{
    if (++m_Index >= m_Ptr->instances.size()) {
        m_Index = 0;
        m_Ptr++;
    }
    return *this;
}

engine::actor::light::Iterator::const_iterator Iterator::const_iterator::operator++(int)
{
    auto tmp = *this;
    ++(*this);
    return tmp;
}

bool Iterator::const_iterator::operator==(const engine::actor::light::Iterator::const_iterator& that)
{
    return m_Ptr == that.m_Ptr;
}

bool Iterator::const_iterator::operator!=(const engine::actor::light::Iterator::const_iterator& that)
{
    return m_Ptr != that.m_Ptr;
}



} // namespace engine::actor::light
