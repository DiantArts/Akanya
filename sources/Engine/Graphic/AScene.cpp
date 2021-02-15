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

    for (const auto& actor : m_vectorActors) {
        actor->draw(m_camera);
    }
    for (const auto& cubeMap : m_vectorCubeMap) {
        cubeMap.draw(m_camera);
    }

    // std::cout << "end of draw" << std::endl;
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



// ---------------------------------- Camera

void ::engine::graphic::AScene::addCameraMovementState(
    Camera::MovementState state
)
{
    m_camera.addMovementState(state);
}

void ::engine::graphic::AScene::removeCameraMovementState(
    Camera::MovementState state
)
{
    m_camera.removeMovementState(state);
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
