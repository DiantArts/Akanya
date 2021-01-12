/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Iterator
** File description:
** help to iterate over an ALight
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ITERATOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ITERATOR_HPP___

#include <cstddef>

#include "Parameters.hpp"



namespace engine::actor::light {

class ALight;



class Iterator {
public:
    struct LightIteratingWrapper {
        engine::actor::light::Parameters& parameters;
        const glm::vec3& position;
    };

    class iterator {
    public:
        explicit iterator(engine::actor::light::ALight* ptr);

        Iterator::LightIteratingWrapper operator*();
        Iterator::LightIteratingWrapper operator->();

        Iterator::iterator& operator++();
        Iterator::iterator operator++(int);

        bool operator==(const Iterator::iterator& that);
        bool operator!=(const Iterator::iterator& that);

    private:
        engine::actor::light::ALight* m_Ptr;
        size_t m_Index{ 0 };
    };


    class const_iterator {
    public:
        explicit const_iterator(const engine::actor::light::ALight* ptr);

        Iterator::LightIteratingWrapper operator*();
        Iterator::LightIteratingWrapper operator->();

        const Iterator::const_iterator& operator++();
        Iterator::const_iterator operator++(int);

        bool operator==(const Iterator::const_iterator& that);
        bool operator!=(const Iterator::const_iterator& that);

    private:
        const engine::actor::light::ALight* m_Ptr;
        size_t m_Index{ 0 };
    };


    virtual Iterator::iterator       begin()        = 0;
    virtual Iterator::const_iterator begin() const  = 0;
    virtual Iterator::const_iterator cbegin() const = 0;

    virtual Iterator::iterator       end()        = 0;
    virtual Iterator::const_iterator end() const  = 0;
    virtual Iterator::const_iterator cend() const = 0;
};



} // namespace engine::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_LIGHTS_ITERATOR_HPP___
