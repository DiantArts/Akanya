/*
** EPITECH PROJECT, 2020
** sources/Engine/Window
** File description:
** Abstraction of GLFW
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___

#include <memory>

#include "Engine/Camera.hpp"
#include "Engine/NonCopyable.hpp"



struct GLFWwindow;



namespace engine {



struct WindowDeleter {
    void operator()(GLFWwindow* window);
};



class Window : public engine::NonCopyable {
public:
    // ---------------------------------------------------------------------------- OpenGL stuff
    bool shouldClose() const;
    void clear() const;
    void swapBuffers();
    void pollEvents();

    void setClearColor(float rgb, float alpha = 1.0F);
    void setClearColor(float red, float green, float blue, float alpha = 1.0F);


    // ---------------------------------------------------------------------------- input
    void processInput(float deltaTime);


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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___
