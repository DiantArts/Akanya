//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ATransformable
// Every class inheriting from this one should be able to be transformed. Must be inheriting with ADrawable
//

#include "pch.hpp"



namespace engine::graphic::actor {



// ---------------------------------- *structors

ATransformable::ATransformable(const size_t numberOfPositions)
    : instances(numberOfPositions)
{}

ATransformable::~ATransformable()
{}



// ---------------------------------- transform

glm::mat4 ATransformable::transformModel(const glm::vec3& position) const
{
    auto projection { glm::translate(glm::mat4 { 1.0F }, position) };
    if (m_rotation.x) {
        projection = glm::rotate(projection, glm::radians(m_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    }
    if (m_rotation.y) {
        projection = glm::rotate(projection, glm::radians(m_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    }
    if (m_rotation.z) {
        projection = glm::rotate(projection, glm::radians(m_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    }
    return glm::scale(projection, m_scale);
}



// ---------------------------------- Scale

void ATransformable::scale(const float scale)
{
    m_scale.x += scale;
    m_scale.y += scale;
    m_scale.z += scale;
}

void ATransformable::scale(const float scaleX, const float scaleY, const float scaleZ)
{
    m_scale.x += scaleX;
    m_scale.y += scaleY;
    m_scale.z += scaleZ;
}

void ATransformable::scale(const glm::vec3& scale)
{
    m_scale += scale;
}

void ATransformable::scaleX(const float scale)
{
    m_scale.x += scale;
}

void ATransformable::scaleY(const float scale)
{
    m_scale += scale;
}

void ATransformable::scaleZ(const float scale)
{
    m_scale.z += scale;
}



void ATransformable::setScale(const float scale)
{
    m_scale.x = scale;
    m_scale.y = scale;
    m_scale.z = std::move(scale);
}

void ATransformable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    m_scale.x = std::move(scaleX);
    m_scale.y = std::move(scaleY);
    m_scale.z = std::move(scaleZ);
}

void ATransformable::setScale(const glm::vec3& scale)
{
    m_scale = scale;
}

void ATransformable::setScale(glm::vec3&& scale)
{
    m_scale = std::move(scale);
}

void ATransformable::setScaleX(const float scale)
{
    m_scale.x = std::move(scale);
}

void ATransformable::setScaleY(const float scale)
{
    m_scale.y = std::move(scale);
}

void ATransformable::setScaleZ(const float scale)
{
    m_scale.z = std::move(scale);
}



const glm::vec3& ATransformable::getScale() const
{
    return m_scale;
}



// ---------------------------------- Rotation

void ATransformable::rotate(const float rotation)
{
    m_rotation += rotation;

    while (m_rotation.x >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.x < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }
}

void ATransformable::rotate(const float rotationX, const float rotationY, const float rotationZ)
{
    m_rotation.x += rotationX;
    m_rotation.y += rotationY;
    m_rotation.z += rotationZ;

    while (m_rotation.x >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.x < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }
}

void ATransformable::rotate(const glm::vec3& rotation)
{
    m_rotation += rotation;

    while (m_rotation.x >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.x < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }
}

void ATransformable::rotateX(const float rotation)
{
    m_rotation.x += rotation;

    while (m_rotation.x >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.x < 0) {
        m_rotation += 360;
    }
}

void ATransformable::rotateY(const float rotation)
{
    m_rotation.y += rotation;

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }
}

void ATransformable::rotateZ(const float rotation)
{
    m_rotation.z += rotation;

    while (m_rotation.y >= 360) {
        m_rotation -= 360;
    }
    while (m_rotation.y < 0) {
        m_rotation += 360;
    }
}



void ATransformable::setRotation(const float rotation)
{
    m_rotation.x = rotation;
    m_rotation.y = rotation;
    m_rotation.z = std::move(rotation);
}

void ATransformable::setRotation(const float rotationX, const float rotationY, const float rotationZ)
{
    m_rotation.x = std::move(rotationX);
    m_rotation.y = std::move(rotationY);
    m_rotation.z = std::move(rotationZ);
}

void ATransformable::setRotation(const glm::vec3& rotation)
{
    m_rotation = rotation;
}

void ATransformable::setRotation(glm::vec3&& rotation)
{
    m_rotation = std::move(rotation);
}

void ATransformable::setRotationX(const float rotation)
{
    m_rotation.x = std::move(rotation);
}

void ATransformable::setRotationY(const float rotation)
{
    m_rotation.y = std::move(rotation);
}

void ATransformable::setRotationZ(const float rotation)
{
    m_rotation.z = std::move(rotation);
}



const glm::vec3& ATransformable::getRotation() const
{
    return m_rotation;
}



// ---------------------------------- Rotation

float ATransformable::getSpeed() const
{
    return m_speed;
}


} // namespace engine::graphic::actor
