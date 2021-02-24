//
// Akanya
// sources/Engine/Graphic/Actors/AControlable
// Allow to controle the Scene
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___

namespace engine::graphic::actor {



class AControlable {

public:

    // ---------------------------------- *structors

    explicit AControlable();

    ~AControlable();



    // ---------------------------------- Copy sementic

    AControlable(
        const AControlable&
    ) noexcept;

    auto operator=(
        const AControlable&
    ) noexcept -> AControlable&;



    // ---------------------------------- Copy sementic

    AControlable(
        AControlable&&
    ) noexcept;

    auto operator=(
        AControlable&&
    ) noexcept -> AControlable&;



    // ---------------------------------- Speed

    auto getSpeed() const
        -> float;

    void setSpeed(
        float speed
    );



    // ---------------------------------- Movement State

    virtual void updatePosition(
        float deltaTime,
        ::glm::vec3& position
    );



    void startMovingForward();

    void startMovingBackward();

    void startMovingRight();

    void startMovingLeft();

    void startMovingUp();

    void startMovingDown();



    void stopMovingForward();

    void stopMovingBackward();

    void stopMovingRight();

    void stopMovingLeft();

    void stopMovingUp();

    void stopMovingDown();



    void stopMoving();

    void immobilize();



    auto isMovingForward()
        -> bool;

    auto isMovingBackward()
        -> bool;

    auto isMovingRight()
        -> bool;

    auto isMovingLeft()
        -> bool;

    auto isMovingUp()
        -> bool;

    auto isMovingDown()
        -> bool;



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



    // ---------------------------------- View

    auto getView(
        const ::glm::vec3& position
    ) const -> glm::mat4;



public:
protected:
protected:
private:

    void adjustOrientation();



private:

    enum MovementState {
        Forward = 0,
        Backward = 1,
        Left = 2,
        Right = 3,
        Up = 4,
        Down = 5,
    };
    ::std::bitset<6> m_movementState;

    float m_speed { 2.5F };

    float m_yaw { -90.00F };
    float m_pitch { 0.00F };

    float minPitch { -89.999F };
    float maxPitch { 89.999F };

    ::glm::vec3 m_orientation { 0.5F, 0.5F, 0.5F };

    ::glm::vec3 m_front { 0.0F, 0.0F, -1.0F };
    ::glm::vec3 m_up { 0.0F, 1.0F, 0.0F };

};



} // namespace engine::graphic::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___
