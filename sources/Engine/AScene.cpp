/*
** EPITECH PROJECT, 2020
** sources/Engine/AScene
** File description:
** Describes how the world is composed and how it interact with players
*/

#include "AScene.hpp"

#include <iostream>

#include "debugMacros.hpp"



namespace engine {



AScene::AScene()
{
    this->m_Window.camera.setSpeed(5);
    this->m_Window.camera.setPosition(1.5, 3.0F, 7.5F);
    this->m_Window.camera.setOrientation(-98, -15);
}

AScene::~AScene()
{}



// ---------------------------------------------------------------------------- Loop

bool AScene::isOver() const
{
    return this->m_Window.shouldClose() || this->m_isOver;
}

void AScene::manageEvents()
{
    this->m_Window.processInput(this->m_EventClock.getElapsedTime());
}

void AScene::update()
{
    for (auto& actor : this->m_VectorActors) {
        actor->update(this->m_UpdateClock.getElapsedTime());
    }
}

void AScene::additionalDraws() const
{}

void AScene::draw()
{
    this->m_Window.clear();

    for (auto& actor : this->m_VectorActors) {
        actor->draw(this->m_Window.camera);
    }

    this->additionalDraws();

    this->cubeMap.draw(this->m_Window.camera);

    this->drawFps();

    this->m_Window.swapBuffers();
}

void AScene::drawFps() const
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

void AScene::pushActor(std::unique_ptr<engine::actor::AActor>&& actor)
{
    this->m_VectorActors.push_back(std::move(actor));
}

void AScene::pushActor(std::unique_ptr<engine::actor::AActor>& actor)
{
    this->m_VectorActors.push_back(std::move(actor));
}


// ---------------------------------------------------------------------------- ShaderMap

engine::Shader& AScene::ShaderMap::operator[](const std::string& filename)
{
    try {
        // return it if already cached
        return this->m_ShaderMap.at(filename);

    } catch (const std::exception&) {
        // cache it
        return this->m_ShaderMap.emplace(filename, filename).first->second;
    }
}



} // namespace engine
