//
// Akanya, Engine
// sources/Engine/AScene
// Basic scene template
//

#include "pch.hpp"
#include "AScene.hpp"

#ifndef MAX_NB_DIRECTIONAL_LIGHT
    #error "any light type must have their max nb defined (directional light doesn't)"
#endif
#ifndef MAX_NB_POINT_LIGHT
    #error "any light type must have their max nb defined (point light doesn't)"
#endif
#ifndef MAX_NB_SPOT_LIGHT
    #error "any light type must have their max nb defined (spot light doesn't)"
#endif




// ---------------------------------- *structors

::engine::graphic::AScene::AScene(
    ::engine::graphic::Window& window
)
    : m_window(window)
    , m_camera(m_window.getSize())
    , m_lightInformationsUbo(1 * sizeof(glm::vec4) + sizeofPointLightTab, 1)
{
    m_camera.setCursorPosition(std::move(m_window.getCursorPosition()));
    m_camera.setSpeed(5);
    m_camera.setPosition(1.5, 3.0F, 7.5F);
    m_camera.setOrientation(-98, -15);
}

::engine::graphic::AScene::~AScene() = default;



// ---------------------------------- Loop

auto ::engine::graphic::AScene::isOver() const
    -> bool
{
    return m_window.shouldClose() || m_isOver;
}

void ::engine::graphic::AScene::setToOver()
{
    m_isOver = true;
}



void ::engine::graphic::AScene::manageEvents()
{
    m_window.processInput(*this);
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
    m_camera.configureUbo();

    m_lightInformationsUbo.bind();
    m_lightInformationsUbo.setSubData(0, (int)m_camera.getConfig().gamma);
    m_lightInformationsUbo.setSubData(4, (int)m_camera.getConfig().blinn);
    m_lightInformationsUbo.setSubData(8, m_lightInformations.nbPointLight);
    {
        auto iDirectionalLight { 0 }, iPointLight { 0 }, iSpotLight { 0 };
        for (auto& light : m_lights) {
            light.get().setIntoUbo(m_lightInformationsUbo, iDirectionalLight, iPointLight, iSpotLight);
        }
    }
    m_lightInformationsUbo.unbind();

    // m_player->draw();

    for (const auto& actor : m_vectorActors) {
        actor->draw();
    }

    for (const auto& cubeMap : m_vectorCubeMap) {
        cubeMap.draw();
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
    auto deltaTime { m_updateClock.getElapsedTime() };
    m_camera.update(deltaTime);
    for (auto& actor : m_vectorActors) {
        actor->update(deltaTime);
    }
}
