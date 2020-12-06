/*
** EPITECH PROJECT, 2020
** Window
** File description:
** window
*/

#pragma once

#include <memory> // std::unique_ptr

#include "Engine/Camera.hpp"



struct GLFWwindow;



namespace engine {



struct WindowDeleter {
    void operator()(GLFWwindow* window);
};



class Window {
public:
    // ---------------------------------------------------------------------------- OpenGL stuff
    bool shouldClose() const;
    void clear() const;
    void swapBuffers();
    void pollEvents();


    // ---------------------------------------------------------------------------- input
    void processInput(const float deltaTime);


public:
    static constexpr GLuint width  = 1920;
    static constexpr GLuint height = 1080;

    static engine::Camera camera;


private:
    std::unique_ptr<GLFWwindow, WindowDeleter> m_Window;



    // ---------------------------------------------------------------------------- singleton
public:
    static Window& get();

private:
    Window();
    static Window m_SingleInstance;
};



} // namespace engine