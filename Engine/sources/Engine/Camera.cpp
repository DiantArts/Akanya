/*
** EPITECH PROJECT, 2020
** Camera
** File description:
** Camera
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "debugMacros.hpp"
#include "Camera.hpp"

namespace engine {

float Camera::speed = 2.5f;
float Camera::zoom = 45.0f;
glm::vec3 Camera::sensitivity = glm::vec3{0.1f, 0.1f, 1.0f};

Camera::Camera()
{}

Camera::~Camera()
{}

// ---------------------------------------------------------------------------- movement

void Camera::adjustLocalSpeed(const float deltaTime)
{
    this->m_Velocity = speed * deltaTime;
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

// ---------------------------------------------------------------------------- mouse events
void Camera::adjustDirection(float xOffset, float yOffset)
{
    this->m_Yaw += xOffset * this->sensitivity.x;
    this->m_Pitch += yOffset * this->sensitivity.y;

    if (m_Yaw >= 360) {
        this->m_Yaw -= 360;
    }
    if (this->m_Pitch > this->maxPitch) {
        this->m_Pitch = this->maxPitch;
    } else if (this->m_Pitch < this->minPitch) {
        this->m_Pitch = this->minPitch;
    }

    this->m_ReversedDirection.x = cos(glm::radians(this->m_Yaw)) * cos(glm::radians(this->m_Pitch));
    this->m_ReversedDirection.y = sin(glm::radians(this->m_Pitch));
    this->m_ReversedDirection.z = sin(glm::radians(this->m_Yaw)) * cos(glm::radians(this->m_Pitch));
    this->m_Front = glm::normalize(this->m_ReversedDirection);
}

void Camera::adjustZoom(float offset)
{
    this->zoom -= offset;
    if (this->zoom > this->maxZoom) {
        this->zoom = this->maxZoom;
    } else if (this->zoom > this->maxZoom) {
        this->zoom = this->minZoom;
    }
}

// ---------------------------------------------------------------------------- view

glm::mat4 Camera::getView() const
{
    return glm::lookAt(this->m_Position, this->m_Position + this->m_Front, this->m_Up);
}

} // namespace engine
