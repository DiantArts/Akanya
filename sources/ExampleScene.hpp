/*
** EPITECH PROJECT, 2020
** sources/ExampleScene
** File description:
** Scene
*/

#ifndef ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___

#include "Engine/Scene.hpp"



class ExampleScene : public engine::Scene {
public:
    ExampleScene();
    ~ExampleScene();

    void additionalDraws() override;

private:
    engine::Shader backpackShader { "model3d" };
    engine::Model  backpack { backpackShader, "data/3dModels/backpack/backpack.obj" };
};



#endif // ___INCLUDE_GUARD_SOURCES_EXAMPLESCENE_HPP___
