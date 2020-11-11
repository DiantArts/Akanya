/*
** EPITECH PROJECT, 2020
** Camera
** File description:
** Camera
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera.hpp"

namespace engine {

Camera::Camera(const float speed)
    : speed(speed)
{}

Camera::~Camera()
{}

// ---------------------------------------------------------------------------- movement

void Camera::adjustLocalSpeed(const float deltaTime)
{
    this->m_LocalSpeed = speed * deltaTime;
}

void Camera::moveForward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position += this->m_LocalSpeed * this->m_Front;
}

void Camera::moveBackward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position -= this->m_LocalSpeed * this->m_Front;
}

void Camera::moveLeft(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position -= glm::normalize(glm::cross(this->m_Front, this->m_Up)) * this->m_LocalSpeed;
}

void Camera::moveRight(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    this->m_Position += glm::normalize(glm::cross(this->m_Front, this->m_Up)) * this->m_LocalSpeed;
}

// ---------------------------------------------------------------------------- view

glm::mat4 Camera::getView() const
{
    return glm::lookAt(this->m_Position, this->m_Position + this->m_Front, this->m_Up);
}

    // , m_Target(0.0f, 0.0f, 0.0f)
    // , m_ReversedDirection(glm::normalize(this->m_Position - this->m_CameraTarget))

// glm::mat4 Camera::getView() const
// {
    // const float radius = 10.0f;
    // auto view = glm::lookAt(glm::vec3(sin(glfwGetTime()) * radius, 0.0, cos(glfwGetTime()) * radius),
            // glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
    // return view;
// }


} // namespace engine
