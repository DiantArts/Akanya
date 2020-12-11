/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Position/Multiple
** File description:
** multiple
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___

#include <vector>

#include "../Position/Single.hpp"



namespace engine::graphic::position {



class Multiple {
public:
    // ---------------------------------------------------------------------------- *structors
    Multiple();
    ~Multiple();


    // ---------------------------------------------------------------------------- set == add
    void addPosition(const glm::vec3& position);
    void addPosition(glm::vec3&& position);
    void addPosition(const float positionX, const float positionY, const float positionZ);



    // ---------------------------------------------------------------------------- std::vector
    size_t size() const;

    std::vector<engine::graphic::position::Single>::iterator       begin();
    std::vector<engine::graphic::position::Single>::iterator       end();
    std::vector<engine::graphic::position::Single>::const_iterator begin() const;
    std::vector<engine::graphic::position::Single>::const_iterator end() const;
    std::vector<engine::graphic::position::Single>::const_iterator cbegin() const;
    std::vector<engine::graphic::position::Single>::const_iterator cend() const;


    template <typename... Args>
    void push_back(const Args&... args)
    {
        this->m_VectorPositions.push_back(args...);
    }

    template <typename... Args>
    void push_back(Args&&... args)
    {
        this->m_VectorPositions.push_back(std::forward<Args>(args)...);
    }

    template <typename... Args>
    void emplace_back(const Args&... args)
    {
        this->m_VectorPositions.emplace_back(args...);
    }

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        this->m_VectorPositions.emplace_back(std::forward<Args>(args)...);
    }

    engine::graphic::position::Single& operator[](size_t i);
    const engine::graphic::position::Single& operator[](size_t i) const;



private:
    std::vector<engine::graphic::position::Single> m_VectorPositions;
};



} // namespace engine::graphic::position



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___
