/*
** Akanya, Engine
** sources/Engine/Graphic/Window
** Abstraction of GLFW
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___

#include "Camera.hpp"


struct GLFWwindow;



namespace engine::graphic {



struct WindowDeleter {
    void operator()(
        GLFWwindow* window
    );
};



class Window {
public:
    Window(const Window&) = delete;
    Window(Window&&) = delete;

    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

public:
    // ---------------------------------- OpenGL stuff
    bool shouldClose() const;

    void clear() const;

    void swapBuffers();

    void pollEvents();

    void setClearColor(
        float rgb,
        float alpha = 1.0F
    );

    void setClearColor(
        float red,
        float green,
        float blue,
        float alpha = 1.0F
    );

    void configure();


    // ---------------------------------- input
    void processInput(
        float deltaTime
    );


    // ---------------------------------- singleton
public:
    static Window& get();


public:
    static constexpr GLuint width  = 1920;
    static constexpr GLuint height = 1080;

    static ::engine::graphic::Camera camera;


private:
    std::unique_ptr<GLFWwindow, WindowDeleter> m_window;
    bool gammaKeyPressed { false };
    bool blinnKeyPressed { false };

private:
    Window();
    static Window m_singleInstance;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
