/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ATransformable
** File description:
** Every class inheriting from this one should be able to be transformed
*/

#include "ATransformable.hpp"

#include <glm/gtc/matrix_transform.hpp>



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
    if (this->m_Rotation.x) {
        projection = glm::rotate(projection, glm::radians(this->m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (this->m_Rotation.y) {
        projection = glm::rotate(projection, glm::radians(this->m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (this->m_Rotation.z) {
        projection = glm::rotate(projection, glm::radians(this->m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    }
    projection = glm::scale(projection, this->m_Scale);
    return projection;
}



// ---------------------------------------------------------------------------- Scale

void ATransformable::scale(const float scale)
{
    this->m_Scale.x += scale;
    this->m_Scale.y += scale;
    this->m_Scale.z += scale;
}

void ATransformable::scale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x += scaleX;
    this->m_Scale.y += scaleY;
    this->m_Scale.z += scaleZ;
}

void ATransformable::scale(const glm::vec3& scale)
{
    this->m_Scale += scale;
}

void ATransformable::scaleX(const float scale)
{
    this->m_Scale.x += scale;
}

void ATransformable::scaleY(const float scale)
{
    this->m_Scale += scale;
}

void ATransformable::scaleZ(const float scale)
{
    this->m_Scale.z += scale;
}

//

void ATransformable::setScale(const float scale)
{
    this->m_Scale.x = scale;
    this->m_Scale.y = scale;
    this->m_Scale.z = std::move(scale);
}

void ATransformable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x = std::move(scaleX);
    this->m_Scale.y = std::move(scaleY);
    this->m_Scale.z = std::move(scaleZ);
}

void ATransformable::setScale(const glm::vec3& scale)
{
    this->m_Scale = scale;
}

void ATransformable::setScale(glm::vec3&& scale)
{
    this->m_Scale = std::move(scale);
}

void ATransformable::setScaleX(const float scale)
{
    this->m_Scale.x = std::move(scale);
}

void ATransformable::setScaleY(const float scale)
{
    this->m_Scale.y = std::move(scale);
}

void ATransformable::setScaleZ(const float scale)
{
    this->m_Scale.z = std::move(scale);
}

//

const glm::vec3& ATransformable::getScale() const
{
    return this->m_Scale;
}



// ---------------------------------------------------------------------------- Rotation

void ATransformable::rotate(const float rotation)
{
    this->m_Rotation += rotation;

    while (this->m_Rotation.x >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.x < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

void ATransformable::rotate(const float rotationX, const float rotationY, const float rotationZ)
{
    this->m_Rotation.x += rotationX;
    this->m_Rotation.y += rotationY;
    this->m_Rotation.z += rotationZ;

    while (this->m_Rotation.x >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.x < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

void ATransformable::rotate(const glm::vec3& rotation)
{
    this->m_Rotation += rotation;

    while (this->m_Rotation.x >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.x < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

void ATransformable::rotateX(const float rotation)
{
    this->m_Rotation.x += rotation;

    while (this->m_Rotation.x >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.x < 0) {
        this->m_Rotation += 360;
    }
}

void ATransformable::rotateY(const float rotation)
{
    this->m_Rotation.y += rotation;

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

void ATransformable::rotateZ(const float rotation)
{
    this->m_Rotation.z += rotation;

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

//

void ATransformable::setRotation(const float rotation)
{
    this->m_Rotation.x = rotation;
    this->m_Rotation.y = rotation;
    this->m_Rotation.z = std::move(rotation);
}

void ATransformable::setRotation(const float rotationX, const float rotationY, const float rotationZ)
{
    this->m_Rotation.x = std::move(rotationX);
    this->m_Rotation.y = std::move(rotationY);
    this->m_Rotation.z = std::move(rotationZ);
}

void ATransformable::setRotation(const glm::vec3& rotation)
{
    this->m_Rotation = rotation;
}

void ATransformable::setRotation(glm::vec3&& rotation)
{
    this->m_Rotation = std::move(rotation);
}

void ATransformable::setRotationX(const float rotation)
{
    this->m_Rotation.x = std::move(rotation);
}

void ATransformable::setRotationY(const float rotation)
{
    this->m_Rotation.y = std::move(rotation);
}

void ATransformable::setRotationZ(const float rotation)
{
    this->m_Rotation.z = std::move(rotation);
}

//

const glm::vec3& ATransformable::getRotation() const
{
    return this->m_Rotation;
}


} // namespace engine::actor
