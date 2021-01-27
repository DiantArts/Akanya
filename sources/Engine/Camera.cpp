/*
** EPITECH PROJECT, 2020
** sources/Engine/Camera
** File description:
** Allow user to visualise the world through a point of view
*/

#include "Camera.hpp"

#include <stdexcept>

#include <glm/gtc/matrix_transform.hpp>

#include "optimizationBuiltins.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors

Camera::Camera()
{}

Camera::~Camera()
{}



// ---------------------------------------------------------------------------- speed

void Camera::adjustLocalSpeed(const float deltaTime)
{
    m_Velocity = m_Speed * deltaTime;
}

void Camera::setSpeed(const float value)
{
    m_Speed = value;
}

float Camera::getSpeed() const
{
    return m_Speed;
}



// ---------------------------------------------------------------------------- move

void Camera::move(const float xOffset, const float yOffset, const float zOffset)
{
    m_Position.x += xOffset;
    m_Position.y += yOffset;
    m_Position.z += zOffset;
}

void Camera::move(const glm::vec3& offset)
{
    m_Position += offset;
}



void Camera::moveForward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position += m_Velocity * m_Front;
}

void Camera::moveBackward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position -= m_Velocity * m_Front;
}


void Camera::moveLeft(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position -= glm::normalize(glm::cross(m_Front, m_Up)) * m_Velocity;
}

void Camera::moveRight(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position += glm::normalize(glm::cross(m_Front, m_Up)) * m_Velocity;
}


void Camera::moveTop(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position.y += m_Velocity;
}

void Camera::moveBot(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_Position.y -= m_Velocity;
}



// ---------------------------------------------------------------------------- Position

void Camera::setPosition(const float xOffset, const float yOffset, const float zOffset)
{
    m_Position.x = xOffset;
    m_Position.y = yOffset;
    m_Position.z = zOffset;
}

void Camera::setPosition(const glm::vec3& offset)
{
    m_Position = offset;
}

const glm::vec3& Camera::getPosition() const
{
    return m_Position;
}



// ---------------------------------------------------------------------------- Orientation

void Camera::oriente(const float xOffset, const float yOffset)
{
    m_Yaw += xOffset * m_Sensitivity.x;
    m_Pitch += yOffset * m_Sensitivity.y;

    if (m_Yaw >= 360) {
        m_Yaw -= 360;
    }
    if (m_Pitch > this->maxPitch) {
        m_Pitch = this->maxPitch;
    } else if (m_Pitch < this->minPitch) {
        m_Pitch = this->minPitch;
    }
    this->adjustOrientation();
}

void Camera::oriente(const glm::vec2& offset)
{
    m_Yaw += offset.x * m_Sensitivity.x;
    m_Pitch += offset.y * m_Sensitivity.y;

    if (m_Yaw >= 360) {
        m_Yaw -= 360;
    }
    if (m_Pitch > this->maxPitch) {
        m_Pitch = this->maxPitch;
    } else if (m_Pitch < this->minPitch) {
        m_Pitch = this->minPitch;
    }
    this->adjustOrientation();
}


void Camera::setOrientation(const float xOffset, const float yOffset)
{
    if (unlikely(xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_Yaw   = xOffset;
    m_Pitch = yOffset;
    this->adjustOrientation();
}

void Camera::setOrientation(const glm::vec2& offset)
{
    if (unlikely(offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_Yaw   = offset.x;
    m_Pitch = offset.y;
    this->adjustOrientation();
}


void Camera::adjustOrientation()
{
    m_Orientation.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Orientation.y = sin(glm::radians(m_Pitch));
    m_Orientation.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
    m_Front         = glm::normalize(m_Orientation);
}



const glm::vec3& Camera::getOrientation() const
{
    return m_Orientation;
}

const glm::vec3& Camera::getFront() const
{
    return m_Front;
}



// ---------------------------------------------------------------------------- Zoom

void Camera::zoom(const float value)
{
    m_Zoom -= value;
    if (m_Zoom > this->maxZoom) {
        m_Zoom = this->maxZoom;
    } else if (m_Zoom > this->maxZoom) {
        m_Zoom = this->minZoom;
    }
}

void Camera::setZoom(const float value)
{
    if (unlikely(value > this->maxZoom || value > this->maxZoom)) {
        throw std::logic_error("invalid zoom");
    }
    m_Zoom = value;
}

float Camera::getZoom() const
{
    return m_Zoom;
}



// ---------------------------------------------------------------------------- view

glm::mat4 Camera::getView() const
{
    return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

} // namespace engine
