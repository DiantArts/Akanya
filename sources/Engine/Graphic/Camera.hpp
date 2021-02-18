//
// Akanya, Engine
// sources/Engine/Camera
// Allow user to visualise the world through a point of view
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___

namespace engine::graphic {



class Camera {

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



    // ---------------------------------- Speed

    auto getSpeed() const
        -> float;



    void setSpeed(
        float value
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

    enum MovementState {
        Forward = 0,
        Backward = 1,
        Left = 2,
        Right = 3,
        Up = 4,
        Down = 5,
    };

    void addMovementState(
        MovementState state
    );

    void removeMovementState(
        MovementState state
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
        std::shared_ptr<::engine::graphic::AActor>& actor
    );



    // ---------------------------------- Orientation

    auto getOrientation() const
        -> const ::glm::vec3&;

    auto getFront() const
        -> const ::glm::vec3&;



    void oriente(
        float xOffset,
        float yOffset
    );

    void oriente(
        const ::glm::vec2& offset
    );



    void setOrientation(
        float xOffset,
        float yOffset
    );

    void setOrientation(
        const ::glm::vec2& offset
    );



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

    glm::mat4 getView() const;



public:

    static constexpr float minPitch { -89.999F };
    static constexpr float maxPitch { 89.999F };
    static constexpr float minZoom { 1.000F };
    static constexpr float maxZoom { 45.000F };



protected:
protected:
private:

    void adjustOrientation();



private:

    float m_speed { 2.5F };
    ::std::bitset<6> m_movementState;

    std::weak_ptr<::engine::graphic::AActor> m_attachedActor;

    ::glm::vec3 m_orientation { 0.5F, 0.5F, 0.5F };
    ::glm::vec3 m_position { 0.0F, 0.0F, 3.0F };

    ::glm::vec3 m_front { 0.0F, 0.0F, -1.0F };
    ::glm::vec3 m_up { 0.0F, 1.0F, 0.0F };

    ::glm::vec3 m_sensitivity { 0.1F, 0.1F, 1.0F };

    ::glm::vec2 m_cursorPosition;

    float m_zoom { 45.05F };
    float m_yaw { -90.00F };
    float m_pitch { 0.00F };

    Camera::Config m_config;

    ::engine::graphic::opengl::Ubo m_informationsUbo;
    ::engine::graphic::opengl::Ubo m_positionUbo;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___
