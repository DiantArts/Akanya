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

void Scene::additionalDraws()
{}

void Scene::draw()
{
    this->m_Window.clear();

    for (auto& drawable : this->m_VectorObjects) {
        drawable->update(this->m_UpdateClock.getElapsedTime());
        drawable->draw(this->m_Window.camera);
    }

    this->additionalDraws();

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

void Scene::pushObject(std::unique_ptr<engine::actor::shape3d::Basic>&& drawableObject)
{
    this->m_VectorObjects.push_back(std::move(drawableObject));
}

void Scene::pushObject(std::unique_ptr<engine::actor::shape3d::Basic>& drawableObject)
{
    this->m_VectorObjects.push_back(std::move(drawableObject));
}


// ---------------------------------------------------------------------------- ShaderMap

engine::Shader& Scene::ShaderMap::operator[](const std::string& filename)
{
    try {
        // return it if already cached
        return this->m_ShaderMap.at(filename);

    } catch (const std::exception&) {
        // cache it
        return this->m_ShaderMap.emplace(filename, filename).first->second;
    }



} // namespace engine
