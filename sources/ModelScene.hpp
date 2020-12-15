/*
** EPITECH PROJECT, 2020
** sources/ModelScene
** File description:
** Scene
*/

#ifndef ___INCLUDE_GUARD_SOURCES_MODELSCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_MODELSCENE_HPP___

#include "Engine/Scene.hpp"



class ModelScene : public engine::Scene {
public:
    ModelScene();
    ~ModelScene();

    void update() override;
};



#endif // ___INCLUDE_GUARD_SOURCES_MODELSCENE_HPP___
