/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Position/Single
** File description:
** Position Single
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___

#include <glm/vec3.hpp>



namespace engine::graphic::position {



class Single {
public:
    // ---------------------------------------------------------------------------- *structors
    Single(const glm::vec3& position = { 0, 0, 0 });
    Single(glm::vec3&& position);
    Single(const float positionX, const float positionY, const float positionZ);
    ~Single();


    // ---------------------------------------------------------------------------- set
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    void setPosition(const float positionX, const float positionY, const float positionZ);


    // ---------------------------------------------------------------------------- get
    const glm::vec3& get() const;


    // ---------------------------------------------------------------------------- move
    void move(const glm::vec3& position);
    void move(const float offsetX, const float offsetY, const float offsetZ);

    void moveX(const float offset);
    void moveY(const float offset);
    void moveZ(const float offset);


private:
    glm::vec3 m_Position;
};



} // namespace engine::graphic::position



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___
