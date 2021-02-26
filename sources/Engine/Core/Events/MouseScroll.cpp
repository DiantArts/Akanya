//
// Akanya
// sources/Engine/Core/Events/MouseScroll
// Event of a mouse scroll
//

#include "pch.hpp"
#include "MouseScroll.hpp"
#include "../../Graphic/Camera.hpp"
#include "../../Graphic/AScene.hpp"



// ---------------------------------- *structors

::engine::core::event::MouseScroll::MouseScroll(
    int xoffset,
    int yoffset
)
    : m_xoffset(xoffset)
    , m_yoffset(yoffset)
{
    std::cout << "SCROLL" << m_xoffset << " " << m_yoffset << std::endl;
}

::engine::core::event::MouseScroll::~MouseScroll() = default;



// ---------------------------------- Copy sementic

::engine::core::event::MouseScroll::MouseScroll(
    const MouseScroll&
) noexcept = default;

auto ::engine::core::event::MouseScroll::operator=(
    const MouseScroll&
) noexcept -> MouseScroll& = default;



// ---------------------------------- Move sementic

::engine::core::event::MouseScroll::MouseScroll(
    MouseScroll&&
) noexcept = default;

auto ::engine::core::event::MouseScroll::operator=(
    MouseScroll&&
) noexcept -> MouseScroll& = default;



// ---------------------------------- Resolver

void ::engine::core::event::MouseScroll::resolve(
    engine::graphic::AScene& scene
)
{
    static double offset = 1;
    offset /= 2;  
    std::cout << "ZOOM" << offset << std::endl;
    std::cout << "ZOOM" << m_yoffset << std::endl;
    scene.zoomCamera(offset);
}
