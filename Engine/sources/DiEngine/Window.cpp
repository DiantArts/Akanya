/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"
#include "debugMacros.hpp"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) noexcept;
static void initGLWF() noexcept;
static void initGLAD() noexcept;
static void GLAPIENTRY messageCallback( GLenum source, GLenum type, GLuint id, GLenum severity,
GLsizei length [[gnu::unused]], const GLchar* message, const void* userParam [[gnu::unused]]);

namespace DiEngine {

Window::Window() noexcept
{
    initGLWF();

    // glfwGetPrimaryMonitor function returns the primary monitor to allow a
    // fullscreen rendering
    this->m_window = glfwCreateWindow(this->width, this->height, "Main Window",
            glfwGetPrimaryMonitor(), nullptr);

    if (!this->m_window) {
        ERROR_MSG("failed to create a glfw window");
        glfwTerminate();
        std::exit(1);
    }

    // specifies the affine transformation of x and y from normalized devices
    // coordinates to window coordinates.
    glfwMakeContextCurrent(this->m_window);
    glfwSetFramebufferSizeCallback(this->m_window, framebuffer_size_callback);

    // GLAD
    initGLAD();

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // specifies the color values used by glClear to clear the color buffers
    glClearColor(0.f, 0.f, 0.f, 1.0f); // clear black
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear weird blue

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);

    DEBUG_MSG("window created");
}

Window::~Window() noexcept
{
    glfwTerminate();
    DEBUG_MSG("glfw terminated");

    DEBUG_MSG("window destroyed");
}

// OpenGL stuff
bool Window::shouldClose() const noexcept
{
    return glfwWindowShouldClose(this->m_window);
}

void Window::swapBuffers() noexcept
{
    glfwSwapBuffers(this->m_window);
}

void Window::processInput() noexcept
{
    if (glfwGetKey(this->m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_window, true);
    }
}

} // namespace DiEngine

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
static void framebuffer_size_callback(GLFWwindow* window [[ gnu::unused ]],
int width, int height) noexcept
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// provides a simple API for creating windows, contexts and surfaces,
// receiving input and events. (compatible window, X, wayland)
static void initGLWF() noexcept
{
    if (!glfwInit()) {
        ERROR_MSG("failed to initialize glfw");
        glfwTerminate();
        std::exit(1);
    }
    // Window configuration (version 4.6)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__
    DEBUG_MSG("glfw inited");
}

static void initGLAD() noexcept
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        ERROR_MSG("failed to initialize glad");
        glfwTerminate();
        std::exit(1);
    }
    DEBUG_MSG("glad inited");
}

void GLAPIENTRY messageCallback( GLenum source,
                                 GLenum type,
                                 GLuint id,
                                 GLenum severity,
                                 GLsizei length [[gnu::unused]],
                                 const GLchar* message,
                                 const void* userParam [[gnu::unused]])
{
    std::cerr << "ERROR (GL): " << message;
    std::cerr << " (src: " << source << ", type: " << type;
    std::cerr << ", severity: ";
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:         std::cerr << "high";         break;
    case GL_DEBUG_SEVERITY_MEDIUM:       std::cerr << "medium";       break;
    case GL_DEBUG_SEVERITY_LOW:          std::cerr << "low";          break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::cerr << "notification"; break;
    }
    std::cerr << ")" << std::endl;
}
