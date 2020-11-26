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
#include "Engine/Shapes/3d/Single/Drawable.hpp"
#include "Engine/Shapes/3d/Multiple/Drawable.hpp"
#include "Engine/Shader.hpp"
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

    virtual void update();


protected:
    bool m_isOver = false;

    engine::Window& m_Window { engine::Window::get() };
    engine::Clock           m_Clock;

    std::vector<std::unique_ptr<engine::shape3d::single::Drawable>> m_VectorSingleDrawables;
    std::vector<std::unique_ptr<engine::shape3d::multiple::Drawable>> m_VectorMultipleDrawables;
};



} // namespace engine
