/*
** EPITECH PROJECT, 2020
** sources/Engine/Camera
** File description:
** Allow user to visualise the world through a point of view
*/

#include "Camera.hpp"
#include "Camera.hpp"

#include <stdexcept>

#include <glm/gtc/matrix_transform.hpp>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "optimizationBuiltins.hpp"



namespace engine {



// ---------------------------------------------------------------------------- speed

void Camera::adjustLocalSpeed(const float deltaTime)
{
    this->m_Velocity = this->m_Speed * deltaTime;
}

void Camera::setSpeed(const float value)
{
    this->m_Speed = value;
}

float Camera::getSpeed() const
{
    return this->m_Speed;
}



// ---------------------------------------------------------------------------- move

void Camera::move(const float xOffset, const float yOffset, const float zOffset)
{
    this->m_Position.x += xOffset;
    this->m_Position.y += yOffset;
    this->m_Position.z += zOffset;
}

void Camera::move(const glm::vec3& offset)
{
    this->m_Position += offset;
}



void Camera::moveForward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position += this->m_Velocity * this->m_Front;
}

void Camera::moveBackward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position -= this->m_Velocity * this->m_Front;
}


void Camera::moveLeft(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position -= glm::normalize(glm::cross(this->m_Front, this->m_Up)) * this->m_Velocity;
}

void Camera::moveRight(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position += glm::normalize(glm::cross(this->m_Front, this->m_Up)) * this->m_Velocity;
}


void Camera::moveTop(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position.y += this->m_Velocity;
}

void Camera::moveBot(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position.y -= this->m_Velocity;
}



// ---------------------------------------------------------------------------- Position

void Camera::setPosition(const float xOffset, const float yOffset, const float zOffset)
{
    this->m_Position.x = xOffset;
    this->m_Position.y = yOffset;
    this->m_Position.z = zOffset;
}

void Camera::setPosition(const glm::vec3& offset)
{
    this->m_Position = offset;
}

const glm::vec3& Camera::getPosition() const
{
    return this->m_Position;
}



// ---------------------------------------------------------------------------- Orientation

void Camera::oriente(const float xOffset, const float yOffset)
{
    this->m_Yaw += xOffset * this->m_Sensitivity.x;
    this->m_Pitch += yOffset * this->m_Sensitivity.y;

    if (this->m_Yaw >= 360) {
        this->m_Yaw -= 360;
    }
    if (this->m_Pitch > this->maxPitch) {
        this->m_Pitch = this->maxPitch;
    } else if (this->m_Pitch < this->minPitch) {
        this->m_Pitch = this->minPitch;
    }
    this->adjustOrientation();
}

void Camera::oriente(const glm::vec2& offset)
{
    this->m_Yaw += offset.x * this->m_Sensitivity.x;
    this->m_Pitch += offset.y * this->m_Sensitivity.y;

    if (this->m_Yaw >= 360) {
        this->m_Yaw -= 360;
    }
    if (this->m_Pitch > this->maxPitch) {
        this->m_Pitch = this->maxPitch;
    } else if (this->m_Pitch < this->minPitch) {
        this->m_Pitch = this->minPitch;
    }
    this->adjustOrientation();
}


void Camera::setOrientation(const float xOffset, const float yOffset)
{
    if (unlikely(xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    this->m_Yaw   = xOffset;
    this->m_Pitch = yOffset;
    this->adjustOrientation();
}

void Camera::setOrientation(const glm::vec2& offset)
{
    if (unlikely(offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    this->m_Yaw   = offset.x;
    this->m_Pitch = offset.y;
    this->adjustOrientation();
}


void Camera::adjustOrientation()
{
    this->m_ReversedDirection.x = cos(glm::radians(this->m_Yaw)) * cos(glm::radians(this->m_Pitch));
    this->m_ReversedDirection.y = sin(glm::radians(this->m_Pitch));
    this->m_ReversedDirection.z = sin(glm::radians(this->m_Yaw)) * cos(glm::radians(this->m_Pitch));
    this->m_Front               = glm::normalize(this->m_ReversedDirection);
}



const glm::vec3& Camera::getOrientation() const
{
    return this->m_ReversedDirection;
}

const glm::vec3& Camera::getFront() const
{
    return this->m_Front;
}



// ---------------------------------------------------------------------------- Zoom
void Camera::zoom(const float value)
{
    this->m_Zoom -= value;
    if (this->m_Zoom > this->maxZoom) {
        this->m_Zoom = this->maxZoom;
    } else if (this->m_Zoom > this->maxZoom) {
        this->m_Zoom = this->minZoom;
    }
}

void Camera::setZoom(const float value)
{
    if (unlikely(value > this->maxZoom || value > this->maxZoom)) {
        throw std::logic_error("invalid zoom");
    }
    this->m_Zoom = value;
}

float Camera::getZoom() const
{
    return this->m_Zoom;
}



// ---------------------------------------------------------------------------- view

glm::mat4 Camera::getView() const
{
    return std::move(glm::lookAt(this->m_Position, this->m_Position + this->m_Front, this->m_Up));
}

} // namespace engine
