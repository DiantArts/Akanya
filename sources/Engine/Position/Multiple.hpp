/*
** EPITECH PROJECT, 2020
** Multiple
** File description:
** multiple
*/

#pragma once

#include <vector>

#include "../Position/Single.hpp"



namespace engine::position {



class Multiple {
public:
    // ---------------------------------------------------------------------------- *structors
    Multiple();
    ~Multiple();


    // ---------------------------------------------------------------------------- set == add
    void setPosition(const std::vector<glm::vec3>& vectorPositions);
    void setPosition(const std::vector<engine::position::Single>& vectorPositions);
    void setPosition(const engine::position::Multiple& vectorPositions);

    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    void setPosition(const float positionX, const float positionY, const float positionZ);


    // ---------------------------------------------------------------------------- get
    const std::vector<engine::position::Single>& getPosition() const;


    // ---------------------------------------------------------------------------- std::vector
    size_t size() const;

    std::vector<engine::position::Single>::iterator       begin();
    std::vector<engine::position::Single>::iterator       end();
    std::vector<engine::position::Single>::const_iterator begin() const;
    std::vector<engine::position::Single>::const_iterator end() const;
    std::vector<engine::position::Single>::const_iterator cbegin() const;
    std::vector<engine::position::Single>::const_iterator cend() const;


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



private:
    std::vector<engine::position::Single> m_VectorPositions;
};



} // namespace engine::position
