/*
** Akanya, Engine
** sources/Engine/AScene
** Basic scene template
*/

#include "pch.hpp"
#include "AScene.hpp"
#include "../Graphic/Actors/Lights/ALight.hpp"



// ---------------------------------- *structors

::engine::graphic::AScene::AScene()
{
    m_window.setCameraSpeed(5);
    m_window.setCameraPosition(1.5, 3.0F, 7.5F);
    m_window.setCameraOrientation(-98, -15);
}

::engine::graphic::AScene::~AScene() = default;



// ---------------------------------- Loop

auto ::engine::graphic::AScene::isOver() const
    -> bool
{
    return m_window.shouldClose() || m_isOver;
}

void ::engine::graphic::AScene::manageEvents()
{
    m_window.processInput(m_eventClock.getElapsedTime());
}



// ---------------------------------- Draw

void ::engine::graphic::AScene::draw() const
{
    m_window.clear();

    this->drawActors();
    this->drawFps();

    m_window.swapBuffers();
}

void ::engine::graphic::AScene::drawActors() const
{
    for (const auto& actor : m_vectorActors) {
        actor->draw(m_window);
    }
    for (const auto& cubeMap : m_vectorCubeMap) {
        cubeMap.draw(m_window);
    }
}

void ::engine::graphic::AScene::drawFps() const
{
    m_elapsed += m_fpsClock.getElapsedTime();
    ++m_fps;

    if (m_elapsed >= 1) {
        std::cout << "FPS: " << m_fps << '\n';
        m_elapsed -= 1;
        m_fps = 0;
    }
}



// ---------------------------------- Update

void ::engine::graphic::AScene::update()
{
    for (auto& actor : m_vectorActors) {
        actor->update(m_updateClock.getElapsedTime());
    }
}



// ---------------------------------- Vector Drawables

void ::engine::graphic::AScene::pushActor(std::unique_ptr<engine::graphic::actor::AActor>&& actor)
{
    m_vectorActors.push_back(std::move(actor));
}

void ::engine::graphic::AScene::pushActor(std::unique_ptr<engine::graphic::actor::AActor>& actor)
{
    m_vectorActors.push_back(std::move(actor));
}



// ---------------------------------- ShaderMap *structors

::engine::graphic::AScene::ShaderMap::ShaderMap() = default;

::engine::graphic::AScene::ShaderMap::~ShaderMap() = default;



// ---------------------------------- ShaderMap Move sementic

::engine::graphic::AScene::ShaderMap::ShaderMap(
    ShaderMap&&
) noexcept = default;

auto ::engine::graphic::AScene::ShaderMap::operator=(
    ShaderMap&&
) noexcept -> ShaderMap& = default;



// ---------------------------------- ShaderMap Operators


auto ::engine::graphic::AScene::ShaderMap::operator[](
    const std::string& filename
) -> ::engine::graphic::opengl::Shader&
{
    try {
        // return it if already cached
        return m_shaderMap.at(filename);

    } catch (const std::exception&) {
        // cache it
        return m_shaderMap.emplace(filename, filename).first->second;
    }
}
