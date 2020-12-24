/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Position/Single
** File description:
** Position Single
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___

#include <glm/vec3.hpp>

#include "IPosition.hpp"
#include "Tools/FuncAlias.hpp"



namespace engine::graphic::position {



class Single : public engine::graphic::position::IPosition {
public:
    // ---------------------------------------------------------------------------- *structors
    Single(const glm::vec3& position = { 0, 0, 0 });
    Single(glm::vec3&& position);
    Single(float positionX, float positionY, float positionZ);
    ~Single();


    // ---------------------------------------------------------------------------- set
    void setPosition(float x, float y, float z);
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    void setPosition(const engine::graphic::position::Single& position);
    void setPosition(engine::graphic::position::Single&& position);

    void setPositionX(float position);
    void setPositionY(float position);
    void setPositionZ(float position);

    FUNC_ALIAS(set, setPosition)
    FUNC_ALIAS(setX, setPositionX)
    FUNC_ALIAS(setY, setPositionY)
    FUNC_ALIAS(setZ, setPositionZ)


    // ---------------------------------------------------------------------------- move
    void move(const glm::vec3& position);
    void move(float offsetX, float offsetY, float offsetZ);

    void moveX(float offset);
    void moveY(float offset);
    void moveZ(float offset);


    // ---------------------------------------------------------------------------- get
    glm::vec3& getPosition();
    const glm::vec3& getPosition() const;

    FUNC_ALIAS(get, getPosition)
    CONST_FUNC_ALIAS(get, getPosition)


    // ---------------------------------------------------------------------------- Iterator
    engine::graphic::position::Single& operator[](size_t index) override;
    const engine::graphic::position::Single& operator[](size_t index) const override;
    engine::graphic::position::Single* operator->() override;
    const engine::graphic::position::Single* operator->() const override;

    iterator begin() override;
    const_iterator begin() const override;
    const_iterator cbegin() const override;

    iterator end() override;
    const_iterator end() const override;
    const_iterator cend() const override;


private:
    glm::vec3 m_Position;
};



} // namespace engine::graphic::position



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_SINGLE_HPP___
