//
// Akanya, Engine
// sources/Engine/Camera
// Allow user to visualise the world through a point of view
//

#include "pch.hpp"



namespace engine::graphic {



// ---------------------------------- *structors

Camera::Camera()
{}

Camera::~Camera()
{}



// ---------------------------------- speed

void Camera::adjustLocalSpeed(const float deltaTime)
{
    m_velocity = m_speed * deltaTime;
}

void Camera::setSpeed(const float value)
{
    m_speed = value;
}

float Camera::getSpeed() const
{
    return m_speed;
}



// ---------------------------------- move

void Camera::move(const float xOffset, const float yOffset, const float zOffset)
{
    m_position.x += xOffset;
    m_position.y += yOffset;
    m_position.z += zOffset;
}

void Camera::move(const glm::vec3& offset)
{
    m_position += offset;
}



void Camera::moveForward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position += m_velocity * m_front;
}

void Camera::moveBackward(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position -= m_velocity * m_front;
}


void Camera::moveLeft(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position -= glm::normalize(glm::cross(m_front, m_up)) * m_velocity;
}

void Camera::moveRight(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position += glm::normalize(glm::cross(m_front, m_up)) * m_velocity;
}


void Camera::moveTop(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position.y += m_velocity;
}

void Camera::moveBot(const float deltaTime)
{
    this->adjustLocalSpeed(deltaTime);
    m_position.y -= m_velocity;
}



// ---------------------------------- Position

void Camera::setPosition(const float xOffset, const float yOffset, const float zOffset)
{
    m_position.x = xOffset;
    m_position.y = yOffset;
    m_position.z = zOffset;
}

void Camera::setPosition(const glm::vec3& offset)
{
    m_position = offset;
}

const glm::vec3& Camera::getPosition() const
{
    return m_position;
}



// ---------------------------------- Orientation

void Camera::oriente(const float xOffset, const float yOffset)
{
    m_yaw += xOffset * m_sensitivity.x;
    m_pitch += yOffset * m_sensitivity.y;

    if (m_yaw >= 360) {
        m_yaw -= 360;
    }
    if (m_pitch > this->maxPitch) {
        m_pitch = this->maxPitch;
    } else if (m_pitch < this->minPitch) {
        m_pitch = this->minPitch;
    }
    this->adjustOrientation();
}

void Camera::oriente(const glm::vec2& offset)
{
    m_yaw += offset.x * m_sensitivity.x;
    m_pitch += offset.y * m_sensitivity.y;

    if (m_yaw >= 360) {
        m_yaw -= 360;
    }
    if (m_pitch > this->maxPitch) {
        m_pitch = this->maxPitch;
    } else if (m_pitch < this->minPitch) {
        m_pitch = this->minPitch;
    }
    this->adjustOrientation();
}


void Camera::setOrientation(const float xOffset, const float yOffset)
{
    if (unlikely(xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = xOffset;
    m_pitch = yOffset;
    this->adjustOrientation();
}

void Camera::setOrientation(const glm::vec2& offset)
{
    if (unlikely(offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = offset.x;
    m_pitch = offset.y;
    this->adjustOrientation();
}


void Camera::adjustOrientation()
{
    m_orientation.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_orientation.y = sin(glm::radians(m_pitch));
    m_orientation.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front         = glm::normalize(m_orientation);
}



const glm::vec3& Camera::getOrientation() const
{
    return m_orientation;
}

const glm::vec3& Camera::getFront() const
{
    return m_front;
}



// ---------------------------------- Zoom

void Camera::zoom(const float value)
{
    m_zoom -= value;
    if (m_zoom > this->maxZoom) {
        m_zoom = this->maxZoom;
    } else if (m_zoom > this->maxZoom) {
        m_zoom = this->minZoom;
    }
}

void Camera::setZoom(const float value)
{
    if (unlikely(value > this->maxZoom || value > this->maxZoom)) {
        throw std::logic_error("invalid zoom");
    }
    m_zoom = value;
}

float Camera::getZoom() const
{
    return m_zoom;
}



// ---------------------------------- view

void Camera::updateView() const
{
    m_view = glm::lookAt(m_position, m_position + m_front, m_up);
}

const glm::mat4& Camera::getView() const
{
    return m_view;
}



// ---------------------------------- Config

auto Camera::getConfig() const
    -> const Camera::Config&
{
    return m_config;
}



} // namespace engine::graphic
