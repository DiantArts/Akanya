/*
** EPITECH PROJECT, 2020
** sources/Engine/Window
** File description:
** Window
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___

#include <memory>

#include "Engine/NonCopyable.hpp"
#include "Engine/Camera.hpp"



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

    void setClearColor(const float rgb, const float alpha = 1.0F);
    void setClearColor(const float red, const float green, const float blue, const float alpha = 1.0F);


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



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_WINDOW_HPP___
