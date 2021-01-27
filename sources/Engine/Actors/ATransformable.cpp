/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ATransformable
** File description:
** Every class inheriting from this one should be able to be transformed
*/

#include "ATransformable.hpp"

#include "pch.hpp"



namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

ATransformable::ATransformable(const size_t numberOfPositions)
    : instances(numberOfPositions)
{}

ATransformable::~ATransformable()
{}



// ---------------------------------------------------------------------------- transform

glm::mat4 ATransformable::transformModel(const glm::vec3& position) const
{
    auto projection { glm::translate(glm::mat4 { 1.0F }, position) };
    if (m_Rotation.x) {
        projection = glm::rotate(projection, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (m_Rotation.y) {
        projection = glm::rotate(projection, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (m_Rotation.z) {
        projection = glm::rotate(projection, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    }
    return glm::scale(projection, m_Scale);
}



// ---------------------------------------------------------------------------- Scale

void ATransformable::scale(const float scale)
{
    m_Scale.x += scale;
    m_Scale.y += scale;
    m_Scale.z += scale;
}

void ATransformable::scale(const float scaleX, const float scaleY, const float scaleZ)
{
    m_Scale.x += scaleX;
    m_Scale.y += scaleY;
    m_Scale.z += scaleZ;
}

void ATransformable::scale(const glm::vec3& scale)
{
    m_Scale += scale;
}

void ATransformable::scaleX(const float scale)
{
    m_Scale.x += scale;
}

void ATransformable::scaleY(const float scale)
{
    m_Scale += scale;
}

void ATransformable::scaleZ(const float scale)
{
    m_Scale.z += scale;
}

//

void ATransformable::setScale(const float scale)
{
    m_Scale.x = scale;
    m_Scale.y = scale;
    m_Scale.z = std::move(scale);
}

void ATransformable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    m_Scale.x = std::move(scaleX);
    m_Scale.y = std::move(scaleY);
    m_Scale.z = std::move(scaleZ);
}

void ATransformable::setScale(const glm::vec3& scale)
{
    m_Scale = scale;
}

void ATransformable::setScale(glm::vec3&& scale)
{
    m_Scale = std::move(scale);
}

void ATransformable::setScaleX(const float scale)
{
    m_Scale.x = std::move(scale);
}

void ATransformable::setScaleY(const float scale)
{
    m_Scale.y = std::move(scale);
}

void ATransformable::setScaleZ(const float scale)
{
    m_Scale.z = std::move(scale);
}

//

const glm::vec3& ATransformable::getScale() const
{
    return m_Scale;
}



// ---------------------------------------------------------------------------- Rotation

void ATransformable::rotate(const float rotation)
{
    m_Rotation += rotation;

    while (m_Rotation.x >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.x < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }
}

void ATransformable::rotate(const float rotationX, const float rotationY, const float rotationZ)
{
    m_Rotation.x += rotationX;
    m_Rotation.y += rotationY;
    m_Rotation.z += rotationZ;

    while (m_Rotation.x >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.x < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }
}

void ATransformable::rotate(const glm::vec3& rotation)
{
    m_Rotation += rotation;

    while (m_Rotation.x >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.x < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }
}

void ATransformable::rotateX(const float rotation)
{
    m_Rotation.x += rotation;

    while (m_Rotation.x >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.x < 0) {
        m_Rotation += 360;
    }
}

void ATransformable::rotateY(const float rotation)
{
    m_Rotation.y += rotation;

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }
}

void ATransformable::rotateZ(const float rotation)
{
    m_Rotation.z += rotation;

    while (m_Rotation.y >= 360) {
        m_Rotation -= 360;
    }
    while (m_Rotation.y < 0) {
        m_Rotation += 360;
    }
}

//

void ATransformable::setRotation(const float rotation)
{
    m_Rotation.x = rotation;
    m_Rotation.y = rotation;
    m_Rotation.z = std::move(rotation);
}

void ATransformable::setRotation(const float rotationX, const float rotationY, const float rotationZ)
{
    m_Rotation.x = std::move(rotationX);
    m_Rotation.y = std::move(rotationY);
    m_Rotation.z = std::move(rotationZ);
}

void ATransformable::setRotation(const glm::vec3& rotation)
{
    m_Rotation = rotation;
}

void ATransformable::setRotation(glm::vec3&& rotation)
{
    m_Rotation = std::move(rotation);
}

void ATransformable::setRotationX(const float rotation)
{
    m_Rotation.x = std::move(rotation);
}

void ATransformable::setRotationY(const float rotation)
{
    m_Rotation.y = std::move(rotation);
}

void ATransformable::setRotationZ(const float rotation)
{
    m_Rotation.z = std::move(rotation);
}

//

const glm::vec3& ATransformable::getRotation() const
{
    return m_Rotation;
}


} // namespace engine::actor
