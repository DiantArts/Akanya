//
// Akanya
// sources/Engine/Graphic/Actors/AControlable
// Allow to controle the Scene
//

#include "pch.hpp"
#include "AControlable.hpp"

constexpr ::glm::vec3 g_sensitivity { 0.1F, 0.1F, 1.0F };


// ---------------------------------- *structors

::engine::graphic::actor::AControlable::AControlable() = default;

::engine::graphic::actor::AControlable::~AControlable() = default;



// ---------------------------------- Copy sementic

::engine::graphic::actor::AControlable::AControlable(
    const AControlable&
) noexcept = default;

auto ::engine::graphic::actor::AControlable::operator=(
    const AControlable&
) noexcept -> AControlable& = default;



// ---------------------------------- Move sementic

::engine::graphic::actor::AControlable::AControlable(
    AControlable&&
) noexcept = default;

auto ::engine::graphic::actor::AControlable::operator=(
    AControlable&&
) noexcept -> AControlable& = default;




// ---------------------------------- Speed

auto ::engine::graphic::actor::AControlable::getSpeed() const
    -> float
{
    return m_speed;
}

void ::engine::graphic::actor::AControlable::setSpeed(
    float speed
)
{
    m_speed = speed;
}



// ---------------------------------- Movement State

void ::engine::graphic::actor::AControlable::updatePosition(
    float deltaTime,
    ::glm::vec3& position
)
{
    auto velocity = this->getSpeed() * deltaTime;

    if (this->isMovingForward()) {
        if (!this->isMovingBackward()) {
            position += velocity * m_front;
        }
    } else {
        if (this->isMovingBackward()) {
            position -= velocity * m_front;
        }
    }

    if (this->isMovingRight()) {
        if (!this->isMovingLeft()) {
            position += glm::normalize(glm::cross(m_front, m_up)) * velocity;
        }
    } else {
        if (this->isMovingLeft()) {
            position -= glm::normalize(glm::cross(m_front, m_up)) * velocity;
        }
    }

    if (this->isMovingUp()) {
        if (!this->isMovingDown()) {
            position.y += velocity;
        }
    } else {
        if (this->isMovingDown()) {
            position.y -= velocity;
        }
    }
}



void ::engine::graphic::actor::AControlable::startMovingForward()
{
    m_movementState[AControlable::MovementState::Forward] = true;
}

void ::engine::graphic::actor::AControlable::startMovingBackward()
{
    m_movementState[AControlable::MovementState::Backward] = true;
}

void ::engine::graphic::actor::AControlable::startMovingRight()
{
    m_movementState[AControlable::MovementState::Right] = true;
}

void ::engine::graphic::actor::AControlable::startMovingLeft()
{
    m_movementState[AControlable::MovementState::Left] = true;
}

void ::engine::graphic::actor::AControlable::startMovingUp()
{
    m_movementState[AControlable::MovementState::Up] = true;
}

void ::engine::graphic::actor::AControlable::startMovingDown()
{
    m_movementState[AControlable::MovementState::Down] = true;
}



void ::engine::graphic::actor::AControlable::stopMovingForward()
{
    m_movementState[AControlable::MovementState::Forward] = false;
}

void ::engine::graphic::actor::AControlable::stopMovingBackward()
{
    m_movementState[AControlable::MovementState::Backward] = false;
}

void ::engine::graphic::actor::AControlable::stopMovingRight()
{
    m_movementState[AControlable::MovementState::Right] = false;
}

void ::engine::graphic::actor::AControlable::stopMovingLeft()
{
    m_movementState[AControlable::MovementState::Left] = false;
}

void ::engine::graphic::actor::AControlable::stopMovingUp()
{
    m_movementState[AControlable::MovementState::Up] = false;
}

void ::engine::graphic::actor::AControlable::stopMovingDown()
{
    m_movementState[AControlable::MovementState::Down] = false;
}



void ::engine::graphic::actor::AControlable::stopMoving()
{
    m_movementState.reset();
}

void ::engine::graphic::actor::AControlable::immobilize()
{
    m_movementState.reset();
}



auto ::engine::graphic::actor::AControlable::isMovingForward()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Forward);
}

auto ::engine::graphic::actor::AControlable::isMovingBackward()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Backward);
}

auto ::engine::graphic::actor::AControlable::isMovingRight()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Right);
}

auto ::engine::graphic::actor::AControlable::isMovingLeft()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Left);
}

auto ::engine::graphic::actor::AControlable::isMovingUp()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Up);
}

auto ::engine::graphic::actor::AControlable::isMovingDown()
    -> bool
{
    return m_movementState.test(AControlable::MovementState::Down);
}



// ---------------------------------- Orientation

auto ::engine::graphic::actor::AControlable::getOrientation() const
    -> const glm::vec3&
{
    return m_orientation;
}

auto ::engine::graphic::actor::AControlable::getFront() const
    -> const glm::vec3&
{
    return m_front;
}



void ::engine::graphic::actor::AControlable::oriente(
    const float xOffset,
    const float yOffset
)
{
    m_yaw += xOffset * g_sensitivity.x;
    m_pitch += yOffset * g_sensitivity.y;

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

void ::engine::graphic::actor::AControlable::oriente(
    const glm::vec2& offset
)
{
    m_yaw += offset.x * g_sensitivity.x;
    m_pitch += offset.y * g_sensitivity.y;

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



void ::engine::graphic::actor::AControlable::setOrientation(
    const float xOffset,
    const float yOffset)
{
    if (unlikely(xOffset >= 360 || yOffset > this->maxPitch || yOffset < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = xOffset;
    m_pitch = yOffset;
    this->adjustOrientation();
}

void ::engine::graphic::actor::AControlable::setOrientation(
    const glm::vec2& offset
)
{
    if (unlikely(offset.x >= 360 || offset.y > this->maxPitch || offset.y < this->minPitch)) {
        throw std::logic_error("invalid orientation");
    }
    m_yaw   = offset.x;
    m_pitch = offset.y;
    this->adjustOrientation();
}



void ::engine::graphic::actor::AControlable::adjustOrientation()
{
    m_orientation.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_orientation.y = sin(glm::radians(m_pitch));
    m_orientation.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front         = glm::normalize(m_orientation);
}



// ---------------------------------- View

auto ::engine::graphic::actor::AControlable::getView(
    const ::glm::vec3& position
) const -> glm::mat4
{
    return glm::lookAt(position, position + m_front, m_up);
}
