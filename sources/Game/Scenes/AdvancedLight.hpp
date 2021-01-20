/*
** EPITECH PROJECT, 2020
** sources/Game/Scenes/AdvancedLight
** File description:
** Scene to test lightnings
*/

#ifndef ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___

#include "Engine/AScene.hpp"
#include "Engine/Actors/Model.hpp"



namespace game::scene {



class AdvancedLight : public engine::AScene {
public:
    // ---------------------------------------------------------------------------- *structors
    AdvancedLight();
    ~AdvancedLight();


    // ---------------------------------------------------------------------------- hardcoded
    void additionalDraws() const override;

private:
};



} // namespace game::scene

#endif // ___INCLUDE_GUARD_SOURCES_GAME_SCENES_ADVANCEDLIGHT_HPP___
