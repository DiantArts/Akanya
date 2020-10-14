/*
** EPITECH PROJECT, 2020
** Window
** File description:
** window
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace DiEngine {

class Window {
public:
    // Create the window and init OpenGL stuff
    Window() noexcept;
    // Destroy the window and terminate OpenGL stuff
    ~Window() noexcept;

    bool shouldClose() const noexcept;
    // OpenGL stuff: have to be call inside the main loop
    void swapBuffers() noexcept;

    void processInput() noexcept;

    static constexpr GLuint width = 1920;
    static constexpr GLuint height = 1080;

private:
    GLFWwindow *m_window;
};

} // namespace DiEngine

#endif // WINDOW_HPP
