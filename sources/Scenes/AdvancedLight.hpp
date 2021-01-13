/*
** EPITECH PROJECT, 2020
** sources/Scenes/AdvancedLight
** File description:
** Scene to test lightning
*/

#ifndef ___INCLUDE_GUARD_SOURCES_SCENES_ADVANCEDLIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_SCENES_ADVANCEDLIGHT_HPP___

#include "Engine/AScene.hpp"
#include "Engine/Actors/Model.hpp"



namespace scene {



class AdvancedLight : public engine::AScene {
public:
    // ---------------------------------------------------------------------------- *structors
    AdvancedLight();
    ~AdvancedLight();


    // ---------------------------------------------------------------------------- hardcoded
    void additionalDraws() const override;

private:
};



} // namespace scene

#endif // ___INCLUDE_GUARD_SOURCES_SCENES_ADVANCEDLIGHT_HPP___
