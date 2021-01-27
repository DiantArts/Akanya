/*
** EPITECH PROJECT, 2020
** sources/Engine/Camera
** File description:
** Allow user to visualise the world through a point of view
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___


namespace engine {


class Camera {

public:

    using type = int;


    // ---------------------------------- *structors

    explicit Camera();
    ~Camera();

    Camera(
        const Camera&
    ) noexcept;

    Camera(
        Camera&&
    ) noexcept;

    auto operator=(
        const Camera&
    ) noexcept -> Camera&;

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

    void adjustOrientation();

    auto getOrientation() const
        -> const ::glm::vec3&;



    auto getFront() const
        -> const ::glm::vec3&;



    // ---------------------------------- Zoom

    void zoom(
        float value
    );

    void setZoom(
        float value
    );

    auto getZoom() const
        -> float;



    // ---------------------------------- View

    auto getView() const
        -> ::glm::mat4;



public:

    static constexpr float minPitch { -89.999F };
    static constexpr float maxPitch { 89.999F };
    static constexpr float minZoom { 1.000F };
    static constexpr float maxZoom { 45.000F };



private:

    float m_Speed { 2.5F };
    float m_Velocity; // speed taking in count deltaTime

    ::glm::vec3 m_Orientation { 0.5F, 0.5F, 0.5F };
    ::glm::vec3 m_Position { 0.0F, 0.0F, 3.0F };

    ::glm::vec3 m_Front { 0.0F, 0.0F, -1.0F };
    ::glm::vec3 m_Up { 0.0F, 1.0F, 0.0F };

    ::glm::vec3 m_Sensitivity { 0.1F, 0.1F, 1.0F };

    float m_Zoom { 45.05F };
    float m_Yaw { -90.00F };
    float m_Pitch { 0.00F };
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___
