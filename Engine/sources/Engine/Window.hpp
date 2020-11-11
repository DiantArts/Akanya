/*
** EPITECH PROJECT, 2020
** Window
** File description:
** window
*/

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <glad/glad.h>
#include "Engine/Camera.hpp"

struct GLFWwindow;

namespace engine {

struct WindowDeleter {
    void operator()(GLFWwindow* window);
};

class Window {
public:
    // Create the window and init OpenGL stuff
    Window();
    // Destroy the window and terminate OpenGL stuff
    ~Window() = default;

    bool shouldClose() const;
    // OpenGL stuff: have to be call inside the main loop
    void swapBuffers();
    void pollEvents();

    void processInput(engine::Camera& camera, const float deltaTime);

    static constexpr GLuint width = 1920;
    static constexpr GLuint height = 1080;

private:
    std::unique_ptr<GLFWwindow, WindowDeleter> m_Window;
};

} // namespace engine

#endif // WINDOW_HPP
