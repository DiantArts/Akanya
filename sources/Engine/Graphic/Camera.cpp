//
// Akanya, Engine
// sources/Engine/Camera
// Allow user to visualise the world through a point of view
//

#include "pch.hpp"



// ---------------------------------- *structors

::engine::graphic::Camera::Camera(
    const ::engine::graphic::Window::Size& windowSize
)
    : m_informationsUbo(2 * sizeof(glm::mat4), 0)
    , m_positionUbo(1 * sizeof(glm::vec4), 2)
{
    m_informationsUbo.setOneSubData(0, glm::perspective(45.0f, windowSize.width / windowSize.height, 0.1f, 100.f));
}

::engine::graphic::Camera::Camera::~Camera() = default;



// ---------------------------------- update

void ::engine::graphic::Camera::update(const float deltaTime)
{
    if (m_attachedActor.expired()) {
        auto velocity = this->getSpeed() * deltaTime;

        if (this->isMovingForward()) {
            if (!this->isMovingBackward()) {
                m_position += velocity * m_front;
            }
        } else {
            if (this->isMovingBackward()) {
                m_position -= velocity * m_front;
            }
        }

        if (this->isMovingRight()) {
            if (!this->isMovingLeft()) {
                m_position += glm::normalize(glm::cross(m_front, m_up)) * velocity;
            }
        } else {
            if (this->isMovingLeft()) {
                m_position -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
            }
        }

        if (this->isMovingUp()) {
            if (!this->isMovingDown()) {
                m_position.y += velocity;
            }
        } else {
            if (this->isMovingDown()) {
                m_position.y -= velocity;
            }
        }
    } else {
        // auto attachedActor { m_attachedActor.lock() };
        // auto velocity = attachedActor->getSpeed() * deltaTime;

        // if (m_movementState[Camera::MovementState::Forward]) {
            // if (!m_movementState[Camera::MovementState::Backward]) {
                // attachedActor->instances[0] += velocity * m_front;
            // }
        // } else {
            // if (m_movementState[Camera::MovementState::Backward]) {
                // attachedActor->instances[0] -= velocity * m_front;
            // }
        // }

        // if (m_movementState[Camera::MovementState::Right]) {
            // if (!m_movementState[Camera::MovementState::Left]) {
                // attachedActor->instances[0] += glm::normalize(glm::cross(m_front, m_up)) * velocity;
            // }
        // } else {
            // if (m_movementState[Camera::MovementState::Left]) {
                // attachedActor->instances[0] -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
            // }
        // }

        // if (m_movementState[Camera::MovementState::Up]) {
            // if (!m_movementState[Camera::MovementState::Down]) {
                // attachedActor->instances[0].y += velocity;
            // }
        // } else {
            // if (m_movementState[Camera::MovementState::Down]) {
                // attachedActor->instances[0].y -= velocity;
            // }
        // }
    }
}



// ---------------------------------- move

void ::engine::graphic::Camera::move(const float xOffset, const float yOffset, const float zOffset)
{
    m_position.x += xOffset;
    m_position.y += yOffset;
    m_position.z += zOffset;
}

void ::engine::graphic::Camera::move(const glm::vec3& offset)
{
    m_position += offset;
}




// ---------------------------------- Position

void ::engine::graphic::Camera::setPosition(const float xOffset, const float yOffset, const float zOffset)
{
    m_position.x = xOffset;
    m_position.y = yOffset;
    m_position.z = zOffset;
}

void ::engine::graphic::Camera::setPosition(const glm::vec3& offset)
{
    m_position = offset;
}

const glm::vec3& ::engine::graphic::Camera::getPosition() const
{
    return m_position;
}



// ---------------------------------- Attach

void ::engine::graphic::Camera::attach(
    std::shared_ptr<::engine::graphic::AActor>& actor
)
{
    m_attachedActor = actor;
}

auto ::engine::graphic::Camera::isAttached() const
    -> bool
{
    return m_attachedActor.expired();
}



// ---------------------------------- Orientation

void ::engine::graphic::Camera::oriente(const float xOffset, const float yOffset)
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

void ::engine::graphic::Camera::oriente(const glm::vec2& offset)
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


void ::engine::graphic::Camera::setOrientation(const float xOffset, const float yOffset)
{
    if (unlikely(xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = xOffset;
    m_pitch = yOffset;
    this->adjustOrientation();
}

void ::engine::graphic::Camera::setOrientation(const glm::vec2& offset)
{
    if (unlikely(offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = offset.x;
    m_pitch = offset.y;
    this->adjustOrientation();
}


void ::engine::graphic::Camera::adjustOrientation()
{
    m_orientation.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_orientation.y = sin(glm::radians(m_pitch));
    m_orientation.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front         = glm::normalize(m_orientation);
}



const glm::vec3& ::engine::graphic::Camera::getOrientation() const
{
    return m_orientation;
}

const glm::vec3& ::engine::graphic::Camera::getFront() const
{
    return m_front;
}



// ---------------------------------- Cursor

void ::engine::graphic::Camera::setCursorPosition(
    const glm::vec2& newCursorPosition
)
{
    m_cursorPosition = std::move(newCursorPosition);
}

void ::engine::graphic::Camera::setCursorPosition(
    glm::vec2&& newCursorPosition
)
{
    m_cursorPosition = std::move(newCursorPosition);
}



void ::engine::graphic::Camera::orienteFromCursorPosition(
    const glm::vec2& newCursorPosition
)
{
    float xOffset = newCursorPosition.x - m_cursorPosition.x;
    float yOffset = m_cursorPosition.y - newCursorPosition.y;
    m_cursorPosition = newCursorPosition;

    this->oriente(xOffset, yOffset);
}

void ::engine::graphic::Camera::orienteFromCursorPosition(
    glm::vec2&& newCursorPosition
)
{
    float xOffset = newCursorPosition.x - m_cursorPosition.x;
    float yOffset = m_cursorPosition.y - newCursorPosition.y;
    m_cursorPosition = std::move(newCursorPosition);

    this->oriente(xOffset, yOffset);
}



// ---------------------------------- Zoom

void ::engine::graphic::Camera::zoom(const float value)
{
    m_zoom -= value;
    if (m_zoom > this->maxZoom) {
        m_zoom = this->maxZoom;
    } else if (m_zoom > this->maxZoom) {
        m_zoom = this->minZoom;
    }
}

void ::engine::graphic::Camera::setZoom(const float value)
{
    if (unlikely(value > this->maxZoom || value > this->maxZoom)) {
        throw std::logic_error("invalid zoom");
    }
    m_zoom = value;
}

float ::engine::graphic::Camera::getZoom() const
{
    return m_zoom;
}



// ---------------------------------- Config

auto ::engine::graphic::Camera::getConfig() const
    -> const Camera::Config&
{
    return m_config;
}



// ---------------------------------- configureUbo

void ::engine::graphic::Camera::configureUbo() const
{
    m_informationsUbo.setOneSubData(sizeof(glm::mat4), glm::lookAt(m_position, m_position + m_front, m_up));
    m_positionUbo.setOneSubData(0, m_position);
}

auto ::engine::graphic::Camera::getView() const
    -> ::glm::mat4
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}
