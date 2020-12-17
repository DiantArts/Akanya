/*
** EPITECH PROJECT, 2020
** Scene
** File description:
** Scene
*/

#include "Scene.hpp"

#include <iostream>

#include "debugMacros.hpp"



namespace engine {



Scene::Scene()
{
    this->m_Window.camera.setSpeed(5);
    this->m_Window.camera.setPosition(1.5, 3.0F, 7.5F);
    this->m_Window.camera.setOrientation(-98, -15);
}

Scene::~Scene()
{}



// ---------------------------------------------------------------------------- Loop

bool Scene::isOver() const
{
    return this->m_Window.shouldClose() || this->m_isOver;
}

void Scene::manageEvents()
{
    this->m_Window.processInput(this->m_EventClock.getElapsedTime());
}

void Scene::update()
{}

void Scene::draw()
{
    this->m_Window.clear();

    for (auto& drawable : this->m_VectorObjects) {
        drawable->update(this->m_UpdateClock.getElapsedTime());
        drawable->draw(this->m_Window.camera);
    }

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

    this->drawFps();

    this->m_Window.pollEvents();
    this->m_Window.swapBuffers();
}

void Scene::drawFps() const
{
    this->m_Elapsed += this->m_FpsClock.getElapsedTime();
    this->m_Fps++;

    if (this->m_Elapsed >= 1) {
        std::cout << "FPS: " << this->m_Fps << '\n';
        this->m_Elapsed -= 1;
        this->m_Fps = 0;
    }
}



// ---------------------------------------------------------------------------- Vector Drawables
void Scene::pushObject(std::unique_ptr<engine::graphic::shape3d::Basic>&& drawableObject)
{
    this->m_VectorObjects.push_back(std::move(drawableObject));
}

void Scene::pushObject(std::unique_ptr<engine::graphic::shape3d::Basic>& drawableObject)
{
    this->m_VectorObjects.push_back(std::move(drawableObject));
}



} // namespace engine
