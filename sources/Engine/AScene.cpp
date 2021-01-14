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
    m_Window.camera.setSpeed(5);
    m_Window.camera.setPosition(1.5, 3.0F, 7.5F);
    m_Window.camera.setOrientation(-98, -15);
}

AScene::~AScene()
{}



// ---------------------------------------------------------------------------- Loop

bool AScene::isOver() const
{
    return m_Window.shouldClose() || m_isOver;
}

void AScene::manageEvents()
{
    m_Window.processInput(m_EventClock.getElapsedTime());
}

void AScene::update()
{
    for (auto& actor : m_VectorActors) {
        actor->update(m_UpdateClock.getElapsedTime());
    }
}

void AScene::additionalDraws() const
{}

void AScene::draw() const
{
    m_Window.clear();

    auto light { *engine::actor::ALight::getAll().begin() };
    m_Shadows.generateSpaceMatrix(light.position);
    // m_Shadows.bindSpaceMatrix();
    // m_Shadows.bind();

    // for (auto& actor : m_VectorActors) {
        // actor->draw(m_Window.camera);
    // }

    // m_Shadows.unbind();

    for (auto& actor : m_VectorActors) {
        actor->draw(m_Window.camera);
    }
    this->additionalDraws();
    // this->cubeMap.draw(m_Window.camera);


    this->drawFps();
    m_Window.swapBuffers();
}

void AScene::drawActors() const
{
}

void AScene::drawFps() const
{
    m_Elapsed += m_FpsClock.getElapsedTime();
    ++m_Fps;

    if (m_Elapsed >= 1) {
        std::cout << "FPS: " << m_Fps << '\n';
        m_Elapsed -= 1;
        m_Fps = 0;
    }
}



// ---------------------------------------------------------------------------- Vector Drawables

void AScene::pushActor(std::unique_ptr<engine::actor::AActor>&& actor)
{
    m_VectorActors.push_back(std::move(actor));
}

void AScene::pushActor(std::unique_ptr<engine::actor::AActor>& actor)
{
    m_VectorActors.push_back(std::move(actor));
}


// ---------------------------------------------------------------------------- ShaderMap

engine::Shader& AScene::ShaderMap::operator[](const std::string& filename)
{
    try {
        // return it if already cached
        return m_ShaderMap.at(filename);

    } catch (const std::exception&) {
        // cache it
        return m_ShaderMap.emplace(filename, filename).first->second;
    }
}



} // namespace engine
