/*
** EPITECH PROJECT, 2020
** Scene
** File description:
** Scene
*/

#pragma once

#include <vector>

#include "Engine/Camera.hpp"
#include "Engine/Clock.hpp"
#include "Engine/Container/Map/Shader.hpp"
#include "Engine/Shapes/3d/Multiple/Drawable.hpp"
#include "Engine/Shapes/3d/Single/Drawable.hpp"
#include "Engine/Window.hpp"



namespace engine {



class Scene {
public:
    Scene();
    virtual ~Scene() = 0;


    // ---------------------------------------------------------------------------- Loop
    bool         isOver() const;
    void         manageEvents();
    void         draw();
    virtual void update();


    // ---------------------------------------------------------------------------- Vector Drawables
    void pushDrawable(std::unique_ptr<engine::shape3d::Drawable>&& drawableObject);

    template <typename DrawableType, typename... Args>
    void emplaceDrawable(Args&&... args)
    {
        this->m_VectorDrawables.push_back(std::make_unique<DrawableType>(std::forward<Args>(args)...));
    }


private:
    bool m_isOver = false;

    engine::Window& m_Window { engine::Window::get() };
    engine::Clock   m_Clock;

protected:
    std::vector<std::unique_ptr<engine::shape3d::Drawable>> m_VectorDrawables;
    engine::container::map::Shader                          m_ShaderMap;
};



} // namespace engine
