/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Transformable
** File description:
** Transformable
*/

#include "Transformable.hpp"

#include <glm/gtc/matrix_transform.hpp>



namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Transformable::Transformable(const size_t numberOfPositions)
    : instances(numberOfPositions)
{}

Transformable::~Transformable()
{}



// ---------------------------------------------------------------------------- transform

glm::mat4 Transformable::transformModel(const glm::vec3& position) const
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

void Transformable::scale(const float scale)
{
    this->m_Scale.x += scale;
    this->m_Scale.y += scale;
    this->m_Scale.z += scale;
}

void Transformable::scale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x += scaleX;
    this->m_Scale.y += scaleY;
    this->m_Scale.z += scaleZ;
}

void Transformable::scale(const glm::vec3& scale)
{
    this->m_Scale += scale;
}

void Transformable::scaleX(const float scale)
{
    this->m_Scale.x += scale;
}

void Transformable::scaleY(const float scale)
{
    this->m_Scale += scale;
}

void Transformable::scaleZ(const float scale)
{
    this->m_Scale.z += scale;
}

//

void Transformable::setScale(const float scale)
{
    this->m_Scale.x = scale;
    this->m_Scale.y = scale;
    this->m_Scale.z = std::move(scale);
}

void Transformable::setScale(const float scaleX, const float scaleY, const float scaleZ)
{
    this->m_Scale.x = std::move(scaleX);
    this->m_Scale.y = std::move(scaleY);
    this->m_Scale.z = std::move(scaleZ);
}

void Transformable::setScale(const glm::vec3& scale)
{
    this->m_Scale = scale;
}

void Transformable::setScale(glm::vec3&& scale)
{
    this->m_Scale = std::move(scale);
}

void Transformable::setScaleX(const float scale)
{
    this->m_Scale.x = std::move(scale);
}

void Transformable::setScaleY(const float scale)
{
    this->m_Scale.y = std::move(scale);
}

void Transformable::setScaleZ(const float scale)
{
    this->m_Scale.z = std::move(scale);
}

//

const glm::vec3& Transformable::getScale() const
{
    return this->m_Scale;
}



// ---------------------------------------------------------------------------- Rotation

void Transformable::rotate(const float rotation)
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

void Transformable::rotate(const float rotationX, const float rotationY, const float rotationZ)
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

void Transformable::rotate(const glm::vec3& rotation)
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

void Transformable::rotateX(const float rotation)
{
    this->m_Rotation.x += rotation;

    while (this->m_Rotation.x >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.x < 0) {
        this->m_Rotation += 360;
    }
}

void Transformable::rotateY(const float rotation)
{
    this->m_Rotation.y += rotation;

    while (this->m_Rotation.y >= 360) {
        this->m_Rotation -= 360;
    }
    while (this->m_Rotation.y < 0) {
        this->m_Rotation += 360;
    }
}

void Transformable::rotateZ(const float rotation)
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

void Transformable::setRotation(const float rotation)
{
    this->m_Rotation.x = rotation;
    this->m_Rotation.y = rotation;
    this->m_Rotation.z = std::move(rotation);
}

void Transformable::setRotation(const float rotationX, const float rotationY, const float rotationZ)
{
    this->m_Rotation.x = std::move(rotationX);
    this->m_Rotation.y = std::move(rotationY);
    this->m_Rotation.z = std::move(rotationZ);
}

void Transformable::setRotation(const glm::vec3& rotation)
{
    this->m_Rotation = rotation;
}

void Transformable::setRotation(glm::vec3&& rotation)
{
    this->m_Rotation = std::move(rotation);
}

void Transformable::setRotationX(const float rotation)
{
    this->m_Rotation.x = std::move(rotation);
}

void Transformable::setRotationY(const float rotation)
{
    this->m_Rotation.y = std::move(rotation);
}

void Transformable::setRotationZ(const float rotation)
{
    this->m_Rotation.z = std::move(rotation);
}

//

const glm::vec3& Transformable::getRotation() const
{
    return this->m_Rotation;
}


// void Transformable::setPosition(const float x, const float y, const float z)
// {
    // this->instances->setPosition(std::move(x), std::move(y), std::move(z));
// }

// void Transformable::setPosition(const glm::vec3& position)
// {
    // this->instances->setPosition(position);
// }

// void Transformable::setPosition(glm::vec3&& position)
// {
    // this->instances->setPosition(std::move(position));
// }



// void Transformable::setPositionX(const float offset)
// {
    // this->instances->setPositionX(std::move(offset));
// }

// void Transformable::setPositionY(const float offset)
// {
    // this->instances->setPositionY(std::move(offset));
// }

// void Transformable::setPositionZ(const float offset)
// {
    // this->instances->setPositionZ(std::move(offset));
// }



// void Transformable::move(const glm::vec3& position)
// {
    // this->instances->move(position);
// }

// void Transformable::move(const float offsetX, const float offsetY, const float offsetZ)
// {
    // this->instances->move(std::move(offsetX), std::move(offsetY), std::move(offsetZ));
// }



// void Transformable::moveX(const float offset)
// {
    // this->instances->moveX(std::move(offset));
// }

// void Transformable::moveY(const float offset)
// {
    // this->instances->moveY(std::move(offset));
// }

// void Transformable::moveZ(const float offset)
// {
    // this->instances->moveZ(std::move(offset));
// }


} // namespace engine::graphic
