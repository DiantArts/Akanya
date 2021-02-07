//
// Akanya, Engine
// sources/Game/Scenes/AdvancedLight
// Scene to test lightnings
//

#ifndef ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___

#include "Engine/Graphic/AScene.hpp"
#include "Engine/Graphic/Actors/Model.hpp"



namespace game::scene {



class AdvancedLight
    : public ::engine::graphic::AScene
{

public:

    // ---------------------------------- *structors

    AdvancedLight(
        ::engine::graphic::Window& window
    );

    ~AdvancedLight();



    // ---------------------------------- Copy sementic

    AdvancedLight(
        const AdvancedLight&
    ) noexcept;

    auto operator=(
        const AdvancedLight&
    ) noexcept -> AdvancedLight&;



    // ---------------------------------- Move sementic

    AdvancedLight(
        AdvancedLight&&
    ) noexcept;

    auto operator=(
        AdvancedLight&&
    ) noexcept -> AdvancedLight&;



public:
protected:
protected:
private:
private:

};



} // namespace game::scene

#endif // ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___
