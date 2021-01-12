/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Iterator
** File description:
** help to iterate over an ALight
*/

#include "Iterator.hpp"

#include "ALight.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- iterator

Iterator::iterator::iterator(engine::actor::ALight* ptr) : m_Ptr(std::move(ptr))
{}

Iterator::LightIteratingWrapper Iterator::iterator::operator*()
{
    return Iterator::LightIteratingWrapper { this->m_Ptr->parameters,
                                             this->m_Ptr->instancesRef[this->m_Index] };
}

Iterator::LightIteratingWrapper Iterator::iterator::operator->()
{
    return Iterator::LightIteratingWrapper { this->m_Ptr->parameters,
                                             this->m_Ptr->instancesRef[this->m_Index] };
}

Iterator::iterator& Iterator::iterator::operator++()
{
    if (++this->m_Index >= this->m_Ptr->instancesRef.size()) {
        this->m_Index = 0;
        m_Ptr++;
    }
    return *this;
}

Iterator::iterator Iterator::iterator::operator++(int)
{
    auto tmp = *this;
    ++(*this);
    return tmp;
}

bool Iterator::iterator::operator==(const Iterator::iterator& that)
{
    return this->m_Ptr == that.m_Ptr;
}

bool Iterator::iterator::operator!=(const Iterator::iterator& that)
{
    return this->m_Ptr != that.m_Ptr;
}



// ---------------------------------------------------------------------------- const_iterator

Iterator::const_iterator::const_iterator(const engine::actor::ALight* ptr) : m_Ptr(std::move(ptr))
{}

Iterator::LightIteratingWrapper Iterator::const_iterator::operator*()
{
    return Iterator::LightIteratingWrapper { this->m_Ptr->parameters,
                                             this->m_Ptr->instancesRef[this->m_Index] };
}

Iterator::LightIteratingWrapper Iterator::const_iterator::operator->()
{
    return Iterator::LightIteratingWrapper { this->m_Ptr->parameters,
                                             this->m_Ptr->instancesRef[this->m_Index] };
}

const Iterator::const_iterator& Iterator::const_iterator::operator++()
{
    if (++this->m_Index >= this->m_Ptr->instancesRef.size()) {
        this->m_Index = 0;
        m_Ptr++;
    }
    return *this;
}

Iterator::const_iterator Iterator::const_iterator::operator++(int)
{
    auto tmp = *this;
    ++(*this);
    return tmp;
}

bool Iterator::const_iterator::operator==(const Iterator::const_iterator& that)
{
    return this->m_Ptr == that.m_Ptr;
}

bool Iterator::const_iterator::operator!=(const Iterator::const_iterator& that)
{
    return this->m_Ptr != that.m_Ptr;
}



} // namespace engine::actor::light
