/*
** EPITECH PROJECT, 2020
** sources/ExampleScene
** File description:
** Scene
*/

#ifndef ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___

#include "Engine/Actors/Model.hpp"
#include "Engine/AScene.hpp"



class ExampleScene : public engine::AScene {
public:
    ExampleScene();
    ~ExampleScene();

    void additionalDraws() override;

private:
    engine::Shader backpackShader { "model3d" };
    engine::actor::Model  backpack { backpackShader, "data/3dModels/backpack/backpack.obj", 2 };
    // engine::Model  backpack { backpackShader,
    // "data/3dModels/backpack/original/textures/Survival_BackPack_2.obj", 2 }; engine::Model  backpack {
    // backpackShader, "data/3dModels/woodenTable/source/Desk.fbx", 2 }; engine::Model  backpack {
    // backpackShader, "data/3dModels/woodenTable/source/Wooden_Table.obj" };
};



#endif // ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
