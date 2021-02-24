//
// Akanya
// sources/Engine/Physic/Hitbox
// Hitbox of everything
//

#include "pch.hpp"
#include "Hitbox.hpp"



// ---------------------------------- *structors

::engine::physic::Hitbox::Hitbox() = default;

::engine::physic::Hitbox::~Hitbox() = default;



// ---------------------------------- Copy sementic

::engine::physic::Hitbox::Hitbox(
    const Hitbox&
) noexcept = default;

auto ::engine::physic::Hitbox::operator=(
    const Hitbox&
) noexcept -> Hitbox& = default;



// ---------------------------------- Move sementic

::engine::physic::Hitbox::Hitbox(
    Hitbox&&
) noexcept = default;

auto ::engine::physic::Hitbox::operator=(
    Hitbox&&
) noexcept -> Hitbox& = default;



// ---------------------------------- Vec

void ::engine::physic::Hitbox::add(
    const ::glm::vec3& box
)
{
    m_boxes.push_back(box);
}

void ::engine::physic::Hitbox::add(
    ::glm::vec3&& box
)
{
    m_boxes.push_back(std::move(box));
}



auto ::engine::physic::Hitbox::get() const
    -> const ::std::vector<::glm::vec3>&
{
    return m_boxes;
}



// ---------------------------------- Collision

auto ::engine::physic::Hitbox::isColliding(
    const ::engine::graphic::AActor& other
) const -> bool
{
    return false;
}

auto ::engine::physic::Hitbox::isColliding(
    const ::engine::physic::Hitbox& other
) const -> bool
{
    return false;
}

auto ::engine::physic::Hitbox::isColliding(
    const ::glm::vec3& other
) const -> bool
{
    return false;
}
