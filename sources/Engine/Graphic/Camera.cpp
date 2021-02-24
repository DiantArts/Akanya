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
    if (this->isAttached()) {
        this->updatePosition(deltaTime, m_position);
        // auto velocity = this->getSpeed() * deltaTime;

        // if (this->isMovingForward()) {
            // if (!this->isMovingBackward()) {
                // m_position += velocity * m_front;
            // }
        // } else {
            // if (this->isMovingBackward()) {
                // m_position -= velocity * m_front;
            // }
        // }

        // if (this->isMovingRight()) {
            // if (!this->isMovingLeft()) {
                // m_position += glm::normalize(glm::cross(m_front, m_up)) * velocity;
            // }
        // } else {
            // if (this->isMovingLeft()) {
                // m_position -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
            // }
        // }

        // if (this->isMovingUp()) {
            // if (!this->isMovingDown()) {
                // m_position.y += velocity;
            // }
        // } else {
            // if (this->isMovingDown()) {
                // m_position.y -= velocity;
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
    ::engine::graphic::ControlableActor& actor
)
{
    m_attachedActor = actor;
}

auto ::engine::graphic::Camera::isAttached() const
    -> bool
{
    return m_attachedActor == ::std::nullopt;
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
    m_informationsUbo.setOneSubData(sizeof(glm::mat4), this->getView(m_position));
    m_positionUbo.setOneSubData(0, m_position);
}
