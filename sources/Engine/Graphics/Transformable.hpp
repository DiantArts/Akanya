/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Transformable
** File description:
** Transformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_TRANSFORMABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_TRANSFORMABLE_HPP___

#include <functional>
#include <memory>

#include <glm/vec3.hpp>

#include "Position/Multiple.hpp"
#include "Position/Single.hpp"

#include "../Camera.hpp"



namespace engine::graphic {



class Transformable {
public:
    // ---------------------------------------------------------------------------- *structors
    Transformable(const bool isMultiplePosition);
    virtual ~Transformable() = 0;


    // ---------------------------------------------------------------------------- transform
    virtual glm::mat4 transformModel(const engine::graphic::position::Single& position) const;


    // ---------------------------------------------------------------------------- Scale
    void scale(const float scale);
    void scale(const float scaleX, const float scaleY, const float scaleZ);
    void scale(const glm::vec3& scale);
    void scaleX(const float scale);
    void scaleY(const float scale);
    void scaleZ(const float scale);

    void setScale(const float scale);
    void setScale(const float scaleX, const float scaleY, const float scaleZ);
    void setScale(const glm::vec3& scale);
    void setScale(glm::vec3&& scale);
    void setScaleX(const float scale);
    void setScaleY(const float scale);
    void setScaleZ(const float scale);

    const glm::vec3& getScale() const;


    // ---------------------------------------------------------------------------- Rotation
    void rotate(const float rotation);
    void rotate(const float rotationX, const float rotationY, const float rotationZ);
    void rotate(const glm::vec3& rotation);
    void rotateX(const float rotation);
    void rotateY(const float rotation);
    void rotateZ(const float rotation);

    void setRotation(const float rotation);
    void setRotation(const float rotationX, const float rotationY, const float rotationZ);
    void setRotation(const glm::vec3& rotation);
    void setRotation(glm::vec3&& rotation);
    void setRotationX(const float rotation);
    void setRotationY(const float rotation);
    void setRotationZ(const float rotation);

    const glm::vec3& getRotation() const;


    // ---------------------------------------------------------------------------- position
    virtual bool isMultiplePositions() const;

    engine::graphic::position::Single&       getPosition();
    const engine::graphic::position::Single& getPosition() const;

    engine::graphic::position::Multiple&       getPositions();
    const engine::graphic::position::Multiple& getPositions() const;

    template <typename Position>
    void setPosition(const Position& position)
    {
        if (m_SinglePosition) {
            m_SinglePosition->setPosition(position);
        } else {
            throw std::runtime_error("trying to set a position of a multiple position shape");
        }
    }

    template <typename Position>
    void setPosition(Position&& position)
    {
        if (m_SinglePosition) {
            m_SinglePosition->setPosition(std::move(position));
        } else {
            throw std::runtime_error("trying to set a position of a multiple position shape");
        }
    }

    template <typename... Args>
    void addPosition(const Args&... args)
    {
        if (m_MultiplePositions) {
            m_MultiplePositions->addPosition(args...);
        } else {
            throw std::runtime_error("trying to add a position to a single position shape");
        }
    }

    template <typename... Args>
    void addPosition(Args&&... args)
    {
        if (m_MultiplePositions) {
            m_MultiplePositions->addPosition(std::forward<Args>(args)...);
        } else {
            throw std::runtime_error("trying to add a position to a single position shape");
        }
    }


protected:
    glm::vec3                                            m_Scale { 1.0F, 1.0F, 1.0F };
    glm::vec3                                            m_Rotation { 0.0F, 0.0F, 0.0F };
    std::unique_ptr<engine::graphic::position::Single>   m_SinglePosition { nullptr };
    std::unique_ptr<engine::graphic::position::Multiple> m_MultiplePositions { nullptr };
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_TRANSFORMABLE_HPP___
