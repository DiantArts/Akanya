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



public:
protected:
protected:
private:
private:

    float m_speed { 2.5F };

    enum MovementState {
        Forward = 0,
        Backward = 1,
        Left = 2,
        Right = 3,
        Up = 4,
        Down = 5,
    };
    ::std::bitset<6> m_movementState;

};



} // namespace engine::graphic::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___
