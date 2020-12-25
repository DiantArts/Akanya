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

#include "Positions.hpp"

#include "../Camera.hpp"



namespace engine::graphic {



class Transformable {
public:
    // ---------------------------------------------------------------------------- *structors
    Transformable(size_t numberOfPositions);
    virtual ~Transformable() = 0;


    // ---------------------------------------------------------------------------- transformModel
    virtual glm::mat4 transformModel(const glm::vec3& position) const;
    virtual void      update(float deltaTime) = 0;


    // ---------------------------------------------------------------------------- Scale
    void scale(float scale);
    void scale(float scaleX, float scaleY, float scaleZ);
    void scale(const glm::vec3& scale);
    void scaleX(float scale);
    void scaleY(float scale);
    void scaleZ(float scale);

    void setScale(float scale);
    void setScale(float scaleX, float scaleY, float scaleZ);
    void setScale(const glm::vec3& scale);
    void setScale(glm::vec3&& scale);
    void setScaleX(float scale);
    void setScaleY(float scale);
    void setScaleZ(float scale);

    const glm::vec3& getScale() const;


    // ---------------------------------------------------------------------------- Rotation
    void rotate(float rotation);
    void rotate(float rotationX, float rotationY, float rotationZ);
    void rotate(const glm::vec3& rotation);
    void rotateX(float rotation);
    void rotateY(float rotation);
    void rotateZ(float rotation);

    void setRotation(float rotation);
    void setRotation(float rotationX, float rotationY, float rotationZ);
    void setRotation(const glm::vec3& rotation);
    void setRotation(glm::vec3&& rotation);
    void setRotationX(float rotation);
    void setRotationY(float rotation);
    void setRotationZ(float rotation);

    const glm::vec3& getRotation() const;

public:
    engine::graphic::Positions instances;


private:
    glm::vec3 m_Scale { 1.0F, 1.0F, 1.0F };
    glm::vec3 m_Rotation { 0.0F, 0.0F, 0.0F };
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_TRANSFORMABLE_HPP___
