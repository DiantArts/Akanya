/*
** EPITECH PROJECT, 2020
** Scene
** File description:
** Scene
*/

#include <iostream>
#include "debugMacros.hpp"
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

    for (auto& drawable : this->m_VectorDrawables) {
        drawable->draw(this->m_Window.camera);
    }
    this->displayFps();

    this->m_Window.pollEvents();
    this->m_Window.swapBuffers();
}

void Scene::displayFps() const
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
void Scene::pushDrawable(std::unique_ptr<engine::shape3d::Drawable>&& drawableObject)
{
    this->m_VectorDrawables.push_back(std::move(drawableObject));
}

void Scene::pushDrawable(std::unique_ptr<engine::shape3d::Drawable>& drawableObject)
{
    this->m_VectorDrawables.push_back(std::move(drawableObject));
}



} // namespace engine
