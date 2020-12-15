/*
** EPITECH PROJECT, 2020
** ModelScene
** File description:
** scene
*/

#include "ModelScene.hpp"

#include "Engine/Graphics/Objects/3d/Multiple/EnlightenedCube.hpp"
#include "Engine/Graphics/Objects/3d/Multiple/LightSourceCube.hpp"



ModelScene::ModelScene()
{}

ModelScene::~ModelScene()
{}



void ModelScene::update()
{
    static engine::Shader backpackShader { "model3d" };
    static engine::Model  backpack { backpackShader, "data/3dModels/backpack/backpack.obj" };

    backpackShader.use();
    backpackShader.set("projection", glm::perspective(glm::radians(this->m_Window.camera.getZoom()),
                                         (float)this->m_Window.width / (float)this->m_Window.height, 0.1F, 100.0F));
    backpackShader.set("view", this->m_Window.camera.getView());

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
    backpackShader.set("model", model);
    backpack.draw();
}