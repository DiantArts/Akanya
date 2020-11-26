/*
** EPITECH PROJECT, 2020
** ExampleScene
** File description:
** scene
*/

#include "ExampleScene.hpp"

#include "Engine/Objects/3d/Single/LightSourceCube.hpp"
#include "Engine/Objects/3d/Multiple/EnlightenedCube.hpp"



// engine::Shader enlightenedShader("flashlight");
engine::Shader lightSourceshader("lightSource");
engine::Shader enlightenedShader("enlightened");

extern engine::object3d::single::LightSourceCube& getLamp(); // tmp



ExampleScene::ExampleScene()
{

    this->m_VectorSingleDrawables.push_back(std::move(
                std::make_unique<engine::object3d::single::LightSourceCube>(
                    lightSourceshader, glm::vec3{ 2.0F, 0.8F, 0.0F }
                )
    ));



    this->m_VectorMultipleDrawables.push_back(std::move(
        std::make_unique<engine::object3d::multiple::EnlightenedCube>(enlightenedShader)));

    this->m_VectorMultipleDrawables.back()->addTexture("container.png", "material.diffuse", 0);
    this->m_VectorMultipleDrawables.back()->addTexture("containerBorders.png", "material.specular", 1);

    // this->m_VectorMultipleDrawables.back()->addPosition(0.6, 0, -1.0F);
    // this->m_VectorMultipleDrawables.back()->addPosition(-0.6, 0, -1.5F);

    this->m_VectorMultipleDrawables.back()->addPosition(0.0F, 0.0F, 0.0F);
    this->m_VectorMultipleDrawables.back()->addPosition(2.0F, 5.0F, -15.0F);
    this->m_VectorMultipleDrawables.back()->addPosition(-1.5F, -2.2F, -2.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(-3.8F, -2.0F, -12.3F);
    this->m_VectorMultipleDrawables.back()->addPosition(2.4F, -0.4F, -3.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(-1.7F, 3.0F, -7.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(1.3F, -2.0F, -2.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(1.5F, 2.0F, -2.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(1.5F, 0.2F, -1.5F);
    this->m_VectorMultipleDrawables.back()->addPosition(-1.3F, 1.0F, -1.5F);
}

ExampleScene::~ExampleScene()
{}



void ExampleScene::update()
{
}
