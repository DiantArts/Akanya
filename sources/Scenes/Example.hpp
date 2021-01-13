/*
** EPITECH PROJECT, 2020
** sources/Scenes/Example
** File description:
** Simple example of a scene, mainly to test things
*/

#ifndef ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___

#include "Engine/AScene.hpp"
#include "Engine/Actors/Model.hpp"




namespace scene {



class Example : public engine::AScene {
public:
    // ---------------------------------------------------------------------------- *structors
    Example();
    ~Example();


    // ---------------------------------------------------------------------------- hardcoded
    void additionalDraws() const override;

private:
    engine::Shader backpackShader { "model3d" };
    engine::actor::Model backpack { backpackShader, "backpack/backpack.obj", 2 };
};



} // namespace scene

#endif // ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___
