/*
** EPITECH PROJECT, 2020
** sources/Engine/Scene
** File description:
** Scene
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_SCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_SCENE_HPP___

#include <vector>

#include "Engine/Camera.hpp"
#include "Engine/Clock.hpp"
#include "Engine/Container/Map/Shader.hpp"
#include "Engine/Graphics/Shapes/3d/Basic.hpp"
#include "Engine/New/Model.hpp"
#include "Engine/Window.hpp"


namespace engine {



class Scene {
public:
    Scene();
    virtual ~Scene() = 0;


    // ---------------------------------------------------------------------------- Loop
    bool isOver() const;
    void manageEvents();
    void draw();
    void drawFps() const;


    // ---------------------------------------------------------------------------- Vector Drawables
    void pushObject(std::unique_ptr<engine::graphic::shape3d::Basic>&& drawableObject);
    void pushObject(std::unique_ptr<engine::graphic::shape3d::Basic>& drawableObject);

    template <typename DrawableType, typename... Args>
    void emplaceDrawable(Args&&... args)
    {
        this->m_VectorObjects.push_back(std::make_unique<DrawableType>(std::forward<Args>(args)...));
    }


    // ---------------------------------------------------------------------------- Virtuals
    virtual void update();
    virtual void additionalDraws();


private:
    bool m_isOver = false;

    engine::Clock         m_EventClock;
    engine::Clock         m_UpdateClock;
    mutable engine::Clock m_FpsClock;
    mutable size_t        m_Fps { 0 };
    mutable float         m_Elapsed { 0 };

protected:
    engine::Window&                                               m_Window { engine::Window::get() };
    std::vector<std::unique_ptr<engine::graphic::shape3d::Basic>> m_VectorObjects;
    engine::container::map::Shader                                m_ShaderMap;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_SCENE_HPP___
