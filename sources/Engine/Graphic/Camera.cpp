//
// Akanya, Engine
// sources/Engine/Camera
// Allow user to visualise the world through a point of view
//

#include "pch.hpp"



namespace engine::graphic {



// ---------------------------------- *structors

Camera::Camera(
    const ::engine::graphic::Window::Size& windowSize
)
    : m_ubo(2 * sizeof(glm::mat4), 0)
{
    m_ubo.setOneSubData(0, glm::perspective(45.0f, windowSize.width / windowSize.height, 0.1f, 100.f));
}

Camera::~Camera()
{}



// ---------------------------------- update

enum class MovementState {
    Forward = 0,
    Backward = 1,
    Left = 2,
    Right = 3,
    Up = 4,
    Down = 5,
};

void Camera::update(const float deltaTime)
{
    auto velocity = m_speed * deltaTime;

    if (m_movementState[Camera::MovementState::Forward]) {
        if (!m_movementState[Camera::MovementState::Backward]) {
            m_position += velocity * m_front;
        }
    } else {
        if (m_movementState[Camera::MovementState::Backward]) {
            m_position -= velocity * m_front;
        }
    }

    if (m_movementState[Camera::MovementState::Right]) {
        if (!m_movementState[Camera::MovementState::Left]) {
            m_position += glm::normalize(glm::cross(m_front, m_up)) * velocity;
        }
    } else {
        if (m_movementState[Camera::MovementState::Left]) {
            m_position -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
        }
    }

    if (m_movementState[Camera::MovementState::Up]) {
        if (!m_movementState[Camera::MovementState::Down]) {
            m_position.y += velocity;
        }
    } else {
        if (m_movementState[Camera::MovementState::Down]) {
            m_position.y -= velocity;
        }
    }
}



// ---------------------------------- speed

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

void Camera::addMovementState(
    Camera::MovementState state
)
{
    m_movementState[state] = true;
}

void Camera::removeMovementState(
    Camera::MovementState state
)
{
    m_movementState[state] = false;
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



// ---------------------------------- Cursor

void Camera::setCursorPosition(
    const glm::vec2& newCursorPosition
)
{
    m_cursorPosition = std::move(newCursorPosition);
}

void Camera::setCursorPosition(
    glm::vec2&& newCursorPosition
)
{
    m_cursorPosition = std::move(newCursorPosition);
}



void Camera::orienteFromCursorPosition(
    const glm::vec2& newCursorPosition
)
{
    float xOffset = newCursorPosition.x - m_cursorPosition.x;
    float yOffset = m_cursorPosition.y - newCursorPosition.y;
    m_cursorPosition = newCursorPosition;

    this->oriente(xOffset, yOffset);
}

void Camera::orienteFromCursorPosition(
    glm::vec2&& newCursorPosition
)
{
    float xOffset = newCursorPosition.x - m_cursorPosition.x;
    float yOffset = m_cursorPosition.y - newCursorPosition.y;
    m_cursorPosition = std::move(newCursorPosition);

    this->oriente(xOffset, yOffset);
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



// ---------------------------------- Config

auto Camera::getConfig() const
    -> const Camera::Config&
{
    return m_config;
}



// ---------------------------------- configureUbo

void Camera::configureUbo() const
{
    m_ubo.setOneSubData(sizeof(glm::mat4), glm::lookAt(m_position, m_position + m_front, m_up));
}

glm::mat4 Camera::getView() const
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}



} // namespace engine::graphic
