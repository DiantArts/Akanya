//
// Akanya, Engine
// sources/Engine/Camera
// Allow user to visualise the world through a point of view
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___

namespace engine::graphic {



class Camera
    : public engine::graphic::actor::AControlable
{

public:

    // ---------------------------------- *structors

    explicit Camera(
        const ::engine::graphic::Window::Size& windowSize
    );

    ~Camera();



    // ---------------------------------- Copy sementic

    Camera(
        const Camera&
    ) noexcept;

    auto operator=(
        const Camera&
    ) noexcept -> Camera&;



    // ---------------------------------- Move sementic

    Camera(
        Camera&&
    ) noexcept;

    auto operator=(
        Camera&&
    ) noexcept -> Camera&;



    // ---------------------------------- update

    void update(
        float deltaTime
    );



    // ---------------------------------- Move

    void move(
        float xOffset,
        float yOffset,
        float zOffset
    );

    void move(
        const ::glm::vec3& offset
    );



    // ---------------------------------- Position

    auto getPosition() const
        -> const ::glm::vec3&;



    void setPosition(
        float xOffset,
        float yOffset,
        float zOffset
    );

    void setPosition(
        const ::glm::vec3& offset
    );



    // ---------------------------------- Attach

    void attach(
        ::engine::graphic::ControlableActor& actor
    );

    auto isAttached() const
        -> bool;



    // ---------------------------------- Cursor

    void setCursorPosition(
        const glm::vec2& position
    );

    void setCursorPosition(
        glm::vec2&& position
    );



    void orienteFromCursorPosition(
        const glm::vec2& position
    );

    void orienteFromCursorPosition(
        glm::vec2&& position
    );



    // ---------------------------------- Zoom

    auto getZoom() const
        -> float;



    void zoom(
        float value
    );

    void setZoom(
        float value
    );



    // ---------------------------------- Config

    struct Config {
        bool gamma { false };
        bool blinn { true };
    };

    auto getConfig() const
        -> const Camera::Config&;



    // ---------------------------------- configureUbo

    void configureUbo() const;



public:
protected:
protected:
private:
private:

    OptionalReferenceWrapper<::engine::graphic::ControlableActor> m_attachedActor { ::std::nullopt };

    ::glm::vec3 m_position { 0.0F, 0.0F, 3.0F };

    ::glm::vec2 m_cursorPosition;

    Camera::Config m_config;

    ::engine::graphic::opengl::Ubo m_informationsUbo;
    ::engine::graphic::opengl::Ubo m_positionUbo;

    float m_zoom { 45.05F };

    static constexpr float minZoom { 1.000F };
    static constexpr float maxZoom { 45.000F };

};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___
