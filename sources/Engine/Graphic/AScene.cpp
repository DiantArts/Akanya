//
// Akanya, Engine
// sources/Engine/AScene
// Basic scene template
//

#include "pch.hpp"
#include "AScene.hpp"



// ---------------------------------- *structors

::engine::graphic::AScene::AScene(
    ::engine::graphic::Window& window
)
    : m_window(window)
    , m_projection(glm::perspective(45.0f, m_window.getSize().width / m_window.getSize().height, 0.1f, 100.f))
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
    m_camera.updateView();
    for (const auto& actor : m_vectorActors) {
        actor->draw(m_camera);
    }
    for (const auto& cubeMap : m_vectorCubeMap) {
        cubeMap.draw(m_camera);
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
