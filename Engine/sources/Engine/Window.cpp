/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>   // std::clog
#include "Window.hpp" // std::unique_ptr

static void initGLWF();
static void initGLAD();

static void mouseDirectionCallback(GLFWwindow* window, double xPos, double yPos);
static void mouseScrollcallback(GLFWwindow* window, double xPos, double yPos);
static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
static void GLAPIENTRY messageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
        GLsizei length, const GLchar* message, const void* userParam);

namespace engine {

void WindowDeleter::operator()(GLFWwindow* window)
{
    glfwTerminate();
    glfwDestroyWindow(window);
}

engine::Camera engine::Window::camera; // static member
Window::Window()
{
    initGLWF();

    // glfwGetPrimaryMonitor function returns the primary monitor to allow a fullscreen rendering
    this->m_Window.reset(glfwCreateWindow(this->width, this->height, "", glfwGetPrimaryMonitor(), nullptr));
    if (!this->m_Window) {
        glfwTerminate();
        std::runtime_error("Window creation failed");
    }

    // specifies the affine transformation of x and y from normalized devices
    // coordinates to window coordinates.
    glfwMakeContextCurrent(this->m_Window.get());
    glfwSetFramebufferSizeCallback(this->m_Window.get(), framebufferSizeCallback);

    // GLAD
    initGLAD();

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // specifies the color values used by glClear to clear the color buffers
    // glClearColor(0.f, 0.f, 0.f, 1.0f); // clear black
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear weird blue

    // mouse events
    glfwSetInputMode(this->m_Window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(this->m_Window.get(), mouseDirectionCallback);
    glfwSetScrollCallback(this->m_Window.get(), mouseScrollcallback);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);
}

// ---------------------------------------------------------------------------- OpenGL stuff

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(this->m_Window.get());
}

void Window::swapBuffers()
{
    glfwSwapBuffers(this->m_Window.get());
}

void Window::pollEvents()
{
    glfwPollEvents();
}

// ---------------------------------------------------------------------------- input

void Window::processInput(const float deltaTime)
{
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_Window.get(), true);
    }
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_W) == GLFW_PRESS) {
        this->camera.moveForward(deltaTime);
    }
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_S) == GLFW_PRESS) {
        this->camera.moveBackward(deltaTime);
    }
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_A) == GLFW_PRESS) {
        this->camera.moveLeft(deltaTime);
    }
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_D) == GLFW_PRESS) {
        this->camera.moveRight(deltaTime);
    }
}

} // namespace engine

// ---------------------------------------------------------------------------- init helpers

// provides a simple API for creating windows, contexts and surfaces,
// receiving input and events. (compatible window, X, wayland)
static void initGLWF()
{
    if (!glfwInit()) {
        std::runtime_error("glwfInit failed");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__
}

static void initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        std::runtime_error("glad initialization failed");
    }
}

// ---------------------------------------------------------------------------- callbacks

static void mouseDirectionCallback(GLFWwindow*, double xPos, double yPos)
{
    static float lastX;
    static float lastY;
    static bool firstMouse = true;

    if (firstMouse) {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
        engine::Window::camera.adjustDirection(0, 0);
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos; // reversed since y-coordinates go from bottom to top
    lastX = xPos;
    lastY = yPos;

    engine::Window::camera.adjustDirection(xOffset, yOffset);
}

static void mouseScrollcallback(GLFWwindow*, double, double yOffset)
{
    engine::Window::camera.adjustZoom(yOffset);
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
static void framebufferSizeCallback(GLFWwindow*, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// GLAPIENTRY: Windows compatibility tool
static void GLAPIENTRY messageCallback(GLenum source, GLenum type, GLuint, GLenum severity, GLsizei,
        const GLchar* message, const void*)
{
    std::clog << "ERROR (GL): " << message;
    std::clog << " (src: " << source << ", type: " << type;
    std::clog << ", severity: ";
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:         std::clog << "high";         break;
    case GL_DEBUG_SEVERITY_MEDIUM:       std::clog << "medium";       break;
    case GL_DEBUG_SEVERITY_LOW:          std::clog << "low";          break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::clog << "notification"; break;
    }
    std::clog << ")" << std::endl;
}
