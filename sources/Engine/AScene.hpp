/*
** EPITECH PROJECT, 2020
** sources/Engine/AScene
** File description:
** Describes how the world is composed and how it interact with players
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ASCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ASCENE_HPP___

#include <string>
#include <unordered_map>
#include <vector>

#include <glad/glad.h>

#include "Actors/ABasicShape.hpp"
#include "Camera.hpp"
#include "Clock.hpp"
#include "Shader.hpp"
#include "Window.hpp"
#include "CubeMap.hpp"



namespace engine {



class AScene {
public:
    AScene();
    virtual ~AScene() = 0;


    // ---------------------------------------------------------------------------- Loop
    bool isOver() const;
    void manageEvents();
    void draw();
    void drawFps() const;


    // ---------------------------------------------------------------------------- Vector Actors
    void pushActor(std::unique_ptr<engine::actor::AActor>&& actor);
    void pushActor(std::unique_ptr<engine::actor::AActor>& actor);

    template <typename ActorType, typename... Args>
    void emplaceActor(Args&&... args)
    {
        this->m_VectorActors.push_back(std::make_unique<ActorType>(std::forward<Args>(args)...));
    }


    // ---------------------------------------------------------------------------- Virtuals
    virtual void update();
    virtual void additionalDraws() const;


private:
    bool m_isOver = false;

    engine::Clock         m_EventClock;
    engine::Clock         m_UpdateClock;
    mutable engine::Clock m_FpsClock;
    mutable size_t        m_Fps { 0 };
    mutable float         m_Elapsed { 0 };

protected:
    engine::Window&                                     m_Window { engine::Window::get() };
    std::vector<std::unique_ptr<engine::actor::AActor>> m_VectorActors;

protected:
    // ---------------------------------------------------------------------------- ShaderMap
    class ShaderMap {
    public:
        engine::Shader& operator[](const std::string& filename);

    private:
        std::unordered_map<std::string, engine::Shader> m_ShaderMap;
    };
    engine::AScene::ShaderMap m_ShaderMap;

private:
    engine::actor::CubeMap cubeMap { this->m_ShaderMap["cubeMap"] };
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ASCENE_HPP___
