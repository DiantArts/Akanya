//
// Akanya
// sources/Engine/Graphic/Actors/AControlable
// Allow to controle the Scene
//

#include "pch.hpp"
#include "AControlable.hpp"



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
