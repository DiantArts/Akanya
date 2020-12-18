/*
** EPITECH PROJECT, 2020
** ExampleScene
** File description:
** scene
*/

#include "ExampleScene.hpp"

#include "Engine/Graphics/Objects/3d/Multiple/EnlightenedCube.hpp"
#include "Engine/Graphics/Objects/3d/Multiple/LightSourceCube.hpp"



engine::object3d::multiple::LightSourceCube* lamp;



ExampleScene::ExampleScene()
{
    // this->emplaceDrawable<engine::object3d::single::LightSourceCube>(this->m_ShaderMap["lightSource"],
    // glm::vec3 { 2.0F, 0.8F, 0.0F });


    auto lightSource { std::make_unique<engine::object3d::multiple::LightSourceCube>(
        this->m_ShaderMap["lightSource"]) };

    lightSource->addPosition(-5.0F, 2.0F, -5.0F);
    lightSource->addPosition(2.3F, -3.3F, -54.0F);
    lightSource->addPosition(-3.0F, 1.5F, -7.5F);
    lightSource->addPosition(0.0F, 0.0F, -56.0F);

    this->pushObject(std::move(lightSource));
    lamp = dynamic_cast<engine::object3d::multiple::LightSourceCube*>(&(*this->m_VectorObjects.back()));



    auto cube { std::make_unique<engine::object3d::multiple::EnlightenedCube>(
        this->m_ShaderMap["multiEnlightened"]) };

    cube->addTexture("container.png", "material.diffuse", 0);
    cube->addTexture("containerBorders.png", "material.specular", 1);

    cube->addPosition(0.0F, 0.0F, 0.0F);
    cube->addPosition(2.0F, 10.0F, -15.0F);
    cube->addPosition(-1.5F, -2.2F, -2.5F);
    cube->addPosition(-3.8F, -2.0F, -12.3F);
    cube->addPosition(2.4F, -0.4F, -3.5F);
    cube->addPosition(-1.7F, 3.0F, -7.5F);
    cube->addPosition(1.3F, -2.0F, -2.5F);
    cube->addPosition(1.5F, 2.0F, -2.5F);
    cube->addPosition(1.5F, 0.2F, -1.5F);
    cube->addPosition(-1.3F, 1.0F, -1.5F);

    cube->addPosition(0.6, 0, -1.0F);
    cube->addPosition(-0.6, 0, -1.5F);

    this->pushObject(std::move(cube));
}

ExampleScene::~ExampleScene()
{}
