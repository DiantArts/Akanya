//
// Akanya
// sources/Engine/Core/Events/MousePosition
// Event of a mouse position
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEPOSITION_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEPOSITION_HPP___

namespace engine::core::event {



class MousePosition
    : public ::engine::core::AEvent
{

public:

    // ---------------------------------- *structors

    explicit MousePosition(
        float xPos,
        float yPos
    );

    ~MousePosition();



    // ---------------------------------- Copy sementic

    MousePosition(
        const MousePosition&
    ) noexcept;

    auto operator=(
        const MousePosition&
    ) noexcept -> MousePosition&;



    // ---------------------------------- Copy sementic

    MousePosition(
        MousePosition&&
    ) noexcept;

    auto operator=(
        MousePosition&&
    ) noexcept -> MousePosition&;



    // ---------------------------------- Resolver

    virtual void resolve(
        engine::graphic::AScene& scene
    ) override final;



public:
protected:
protected:
private:
private:

    glm::vec2 m_position;

};



} // namespace engine::core::event

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_MOUSEPOSITION_HPP___
