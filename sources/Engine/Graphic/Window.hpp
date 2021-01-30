//
// Akanya, Engine
// sources/Engine/Graphic/Window
// Abstraction of GLFW
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___



struct GLFWwindow;



namespace engine::graphic {



class Camera;



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

    void pollEvents();



    // ---------------------------------- Input

    void processInput(
        ::engine::graphic::Camera& camera,
        float deltaTime
    );



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


    struct KeyPressed {
        bool gamma { false };
        bool blinn { false };
    };
    Window::KeyPressed m_keyPressed;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_WINDOW_HPP___
