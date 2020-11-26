/*
** EPITECH PROJECT, 2020
** Scene
** File description:
** Scene
*/

#include "Scene.hpp"




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
    this->m_Window.processInput(this->m_Clock.getElapsedTime());
}

void Scene::update()
{}

void Scene::draw()
{
    this->m_Window.clear();

    for (auto& drawable : this->m_VectorSingleDrawables) {
        drawable->draw(this->m_Window.camera);
    }

    for (auto& drawable : this->m_VectorMultipleDrawables) {
        drawable->draw(this->m_Window.camera);
    }

    this->m_Window.pollEvents();
    this->m_Window.swapBuffers();
}


} // namespace engine
