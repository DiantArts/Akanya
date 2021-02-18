//
// Akanya
// sources/Game/Entities/Player
// Desribes a palyer
//

#ifndef ___INCLUDE_GUARD_SOURCES_GAME_ENTITIES_PLAYER_HPP___
#define ___INCLUDE_GUARD_SOURCES_GAME_ENTITIES_PLAYER_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::entity {



class Player
    : public engine::graphic::actor::basicShape::Cube
    , public engine::graphic::actor::AControlable
{

public:

    // ---------------------------------- *structors

    explicit Player(
        const std::string& shaderFilepath
    );

    ~Player();



    // ---------------------------------- Copy sementic

    Player(
        const Player&
    ) noexcept = delete;

    auto operator=(
        const Player&
    ) noexcept -> Player& = delete;



    // ---------------------------------- Copy sementic

    Player(
        Player&&
    ) noexcept = delete;

    auto operator=(
        Player&&
    ) noexcept -> Player& = delete;



    // ---------------------------------- override

    void configureShader() const override;



public:
protected:
protected:
private:
private:

};



} // namespace game::entity

#endif // ___INCLUDE_GUARD_SOURCES_GAME_ENTITIES_PLAYER_HPP___
