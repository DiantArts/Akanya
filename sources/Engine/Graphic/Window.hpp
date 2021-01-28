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



class Window {

public:

    // ---------------------------------- *structors

    Window();
    ~Window();



    // ---------------------------------- Copy sementic

    Window(
        const Window&
    ) noexcept = delete;

    auto operator=(
        const Window&
    ) noexcept -> Window& = delete;



    // ---------------------------------- Move sementic

    Window(
        Window&&
    ) noexcept = delete;

    auto operator=(
        Window&&
    ) noexcept -> Window& = delete;


    // ---------------------------------- Loop

    bool shouldClose() const;



    // ---------------------------------- OpenGL stuff

    void clear() const;

    void swapBuffers() const;

    void pollEvents();



    // ---------------------------------- Input

    void processInput(
        float deltaTime
    );



    // ---------------------------------- Camera

    auto getCamera() const
        -> const ::engine::graphic::Camera&;



    void setCameraSpeed(
        float value
    );



    void setCameraPosition(
        float xOffset,
        float yOffset,
        float zOffset
    );

    void setCameraPosition(
        const ::glm::vec3& offset
    );



    void orienteCamera(
        float xOffset,
        float yOffset
    );

    void orienteCamera(
        const ::glm::vec2& offset
    );

    void setCameraOrientation(
        float xOffset,
        float yOffset
    );

    void setCameraOrientation(
        const ::glm::vec2& offset
    );



    void zoomCamera(
        float value
    );

    void setCameraZoom(
        float value
    );



    // ---------------------------------- Size

    struct Size {
        float width  { 1920 };
        float height { 1080 };
    };

    auto getSize() const
        -> const Window::Size&;



    // ---------------------------------- Size

    struct Config {
        bool gamma { false };
        bool blinn { true };
    };

    auto getConfig() const
        -> const Window::Config&;


public:
protected:
protected:
private:

    // ---------------------------------- Config

    void configureDefault();

    void configureClearColor(
        float rgb,
        float alpha = 1.0F
    );

    void configureClearColor(
        float red,
        float green,
        float blue,
        float alpha = 1.0F
    );



private:

    struct Deleter {
        void operator()(
            GLFWwindow* window
        );
    };
    std::unique_ptr<GLFWwindow, Window::Deleter> m_window;

    ::engine::graphic::Camera m_camera;

    Window::Size m_size;
    Window::Config m_config;


    struct KeyPressed {
        bool gamma { false };
        bool blinn { false };
    };
    Window::KeyPressed m_keyPressed;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
