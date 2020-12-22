/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Transformable
** File description:
** Transformable
*/

#include <glm/gtc/matrix_transform.hpp>

#include "Transformable.hpp"



namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Transformable::Transformable(const bool isMultiplePosition)
{
    if (isMultiplePosition) {
        this->m_MultiplePositions = std::make_unique<engine::graphic::position::Multiple>();
    } else {
        this->m_SinglePosition = std::make_unique<engine::graphic::position::Single>();
    }
}

Transformable::~Transformable()
{}



// ---------------------------------------------------------------------------- transform

glm::mat4 Transformable::transformModel(const engine::graphic::position::Single& position) const
{
    auto projection { glm::translate(glm::mat4 { 1.0F }, position.get()) };
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



const glm::vec3& Transformable::getRotation() const
{
    return this->m_Rotation;
}



// ---------------------------------------------------------------------------- position
bool Transformable::isMultiplePositions() const
{
    return this->m_MultiplePositions != nullptr;
}

engine::graphic::position::Single& Transformable::getPosition()
{
    if (this->isMultiplePositions()) {
        throw std::runtime_error("trying to get multiple positions from a simple position shape");
    }
    return *this->m_SinglePosition;
}

const engine::graphic::position::Single& Transformable::getPosition() const
{
    if (this->isMultiplePositions()) {
        throw std::runtime_error("trying to get multiple positions from a simple position shape");
    }
    return *this->m_SinglePosition;
}


engine::graphic::position::Multiple& Transformable::getPositions()
{
    if (!this->isMultiplePositions()) {
        throw std::runtime_error("trying to get a single positions from a multiple position shape");
    }
    return *this->m_MultiplePositions;
}

const engine::graphic::position::Multiple& Transformable::getPositions() const
{
    if (!this->isMultiplePositions()) {
        throw std::runtime_error("trying to get a single positions from a multiple position shape");
    }
    return *this->m_MultiplePositions;
}



} // namespace engine::graphic
