//
// Akanya, Engine
// sources/Engine/Graphic/Window
// Abstraction of GLFW
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___

#include "../Core/Events/Container.hpp"


struct GLFWwindow;



namespace engine::graphic {



class AScene;



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
    ) noexcept;

    auto operator=(
        Window&&
    ) noexcept -> Window&;


    // ---------------------------------- Loop

    bool shouldClose() const;



    // ---------------------------------- OpenGL stuff

    void clear() const;

    void swapBuffers() const;



    // ---------------------------------- Input

    void processInput(
        ::engine::graphic::AScene& scene
    );

    void centerCursor() const;

    auto getCursorPosition() const
        -> ::glm::vec2;



    // ---------------------------------- Size

    struct Size {
        float width  { 1920 };
        float height { 1080 };
    };

    auto getSize() const
        -> const Window::Size&;


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

    Window::Size m_size;

    ::engine::core::event::Container m_eventContainer;

    struct KeyPressed {
        bool gamma { false };
        bool blinn { false };
    };
    Window::KeyPressed m_keyPressed;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
