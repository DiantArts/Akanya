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

    using type = int;


    // ---------------------------------- *structors

    explicit Camera();

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



    // ---------------------------------- Speed

    auto getSpeed() const
        -> float;



    void setSpeed(
        float value
    );

    void adjustLocalSpeed(
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

    void moveForward(
        float deltaTime
    );

    void moveBackward(
        float deltaTime
    );

    void moveLeft(
        float deltaTime
    );

    void moveRight(
        float deltaTime
    );

    void moveTop(
        float deltaTime
    );

    void moveBot(
        float deltaTime
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



    // ---------------------------------- Zoom

    auto getZoom() const
        -> float;



    void zoom(
        float value
    );

    void setZoom(
        float value
    );



    // ---------------------------------- View

    auto getView() const
        -> ::glm::mat4;



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
    float m_velocity; // speed taking in count deltaTime

    ::glm::vec3 m_orientation { 0.5F, 0.5F, 0.5F };
    ::glm::vec3 m_position { 0.0F, 0.0F, 3.0F };

    ::glm::vec3 m_front { 0.0F, 0.0F, -1.0F };
    ::glm::vec3 m_up { 0.0F, 1.0F, 0.0F };

    ::glm::vec3 m_sensitivity { 0.1F, 0.1F, 1.0F };

    float m_zoom { 45.05F };
    float m_yaw { -90.00F };
    float m_pitch { 0.00F };

};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_CAMERA_HPP___
