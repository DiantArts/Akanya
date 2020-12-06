/*
** EPITECH PROJECT, 2020
** Single
** File description:
** Single
*/

#pragma once

#include <glm/vec3.hpp>



namespace engine::position {



class Single {
public:
    // ---------------------------------------------------------------------------- *structors
    Single(const glm::vec3& position);
    Single(glm::vec3&& position);
    Single(const float positionX, const float positionY, const float positionZ);
    ~Single();


    // ---------------------------------------------------------------------------- set
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    void setPosition(const float positionX, const float positionY, const float positionZ);


    // ---------------------------------------------------------------------------- get
    const glm::vec3& getPosition() const;


    // ---------------------------------------------------------------------------- move
    void move(const glm::vec3& position);
    void move(const float offsetX, const float offsetY, const float offsetZ);

    void moveX(const float offset);
    void moveY(const float offset);
    void moveZ(const float offset);

private:
    glm::vec3 m_Position;
};



} // namespace engine::position
