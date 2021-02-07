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
    , m_lightInformationsUbo(
#if MAX_NB_DIRECTIONAL_LIGHT > 0
        sizeofDirectionalLightTab + sizeof(float) +
#endif
#if MAX_NB_POINT_LIGHT > 0
        sizeofPointLightTab + sizeof(float) +
#endif
#if MAX_NB_SPOT_LIGHT > 0
        sizeofSpotLightTab + sizeof(float) +
#endif
        sizeofLightType,
        2)
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

void ::engine::graphic::AScene::manageEvents()
{
    m_window.processInput(m_camera, m_eventClock.getElapsedTime());
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

    size_t offset { 0 };

    m_lightInformationsUbo.setSubData(offset, m_camera.getConfig().gamma);
    offset += 4;
    m_lightInformationsUbo.setSubData(offset, m_camera.getConfig().blinn);
    offset += 4;

#if MAX_NB_DIRECTIONAL_LIGHT > 0
    m_lightInformationsUbo.setSubData(offset, m_lightInformations.nbDirectionalLight);
    offset += 4 + MAX_NB_DIRECTIONAL_LIGHT * sizeofDirectionalLightTab;
#endif

#if MAX_NB_POINT_LIGHT > 0
    m_lightInformationsUbo.setSubData(offset, m_lightInformations.nbPointLight);
    offset += 4 + MAX_NB_POINT_LIGHT * sizeofDirectionalLightTab;
#endif

#if MAX_NB_SPOT_LIGHT > 0
    m_lightInformationsUbo.setSubData(offset, m_lightInformations.nbSpotLight);
    offset += 4 + MAX_NB_SPOT_LIGHT * sizeofSpotLightTab;
#endif

    auto iDirectionalLight { 0 };
    auto iPointLight { 0 };
    auto iSpotLight { 0 };
    for (const auto& light : m_lights) {
        light.get().setIntoUbo(m_lightInformationsUbo, iDirectionalLight, iPointLight, iSpotLight);
    }

    m_lightInformationsUbo.unbind();

    for (const auto& actor : m_vectorActors) {
        actor->draw(m_camera);
    }
    for (const auto& cubeMap : m_vectorCubeMap) {
        cubeMap.draw(m_camera);
    }

    std::cout << "end of drawing\n" << std::endl;
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



// ---------------------------------- iterator


auto ::engine::graphic::AScene::ShaderMap::begin()
    -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::iterator
{
    return m_shaderMap.begin();
}

auto ::engine::graphic::AScene::ShaderMap::begin()
    const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator
{
    return m_shaderMap.begin();
}

auto ::engine::graphic::AScene::ShaderMap::cbegin()
    const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator
{
    return m_shaderMap.cbegin();
}



auto ::engine::graphic::AScene::ShaderMap::end()
    -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::iterator
{
    return m_shaderMap.end();
}

auto ::engine::graphic::AScene::ShaderMap::end()
    const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator
{
    return m_shaderMap.cend();
}

auto ::engine::graphic::AScene::ShaderMap::cend()
    const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator
{
    return m_shaderMap.cend();
}
