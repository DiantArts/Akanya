/*
** EPITECH PROJECT, 2020
** sources/ExampleScene
** File description:
** Simple example of a scene, mainly to test things
*/

#ifndef ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___

#include "Engine/AScene.hpp"
#include "Engine/Actors/Model.hpp"



class ExampleScene : public engine::AScene {
public:
    ExampleScene();
    ~ExampleScene();

    void additionalDraws() const override;

private:
    engine::Shader backpackShader { "model3d" };
    engine::actor::Model backpack { backpackShader, "backpack/backpack.obj", 2 };
};



#endif // ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
