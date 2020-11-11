/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Window.hpp" // need to be included before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>
#include "debugMacros.hpp"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void initGLWF();
static void initGLAD();
static void GLAPIENTRY messageCallback( GLenum source, GLenum type, GLuint id, GLenum severity,
        GLsizei length, const GLchar* message, const void* userParam);

namespace engine {

void WindowDeleter::operator()(GLFWwindow* window)
{
    DEBUG_MSG("glfw terminated");
    glfwTerminate();
    glfwDestroyWindow(window);
    DEBUG_MSG("Window destroyed");
}

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
    glfwSetFramebufferSizeCallback(this->m_Window.get(), framebuffer_size_callback);

    // GLAD
    initGLAD();

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // specifies the color values used by glClear to clear the color buffers
    // glClearColor(0.f, 0.f, 0.f, 1.0f); // clear black
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // clear weird blue

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);

    DEBUG_MSG("window created");
}

// OpenGL stuff
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

void Window::processInput(engine::Camera& camera, const float deltaTime)
{
    if (glfwGetKey(this->m_Window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->m_Window.get(), true);
    } else if (glfwGetKey(this->m_Window.get(), GLFW_KEY_W) == GLFW_PRESS) {
        camera.moveForward(deltaTime);
    } else if (glfwGetKey(this->m_Window.get(), GLFW_KEY_S) == GLFW_PRESS) {
        camera.moveBackward(deltaTime);
    } else if (glfwGetKey(this->m_Window.get(), GLFW_KEY_A) == GLFW_PRESS) {
        camera.moveLeft(deltaTime);
    } else if (glfwGetKey(this->m_Window.get(), GLFW_KEY_D) == GLFW_PRESS) {
        camera.moveRight(deltaTime);
    }
}

} // namespace engine

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

    DEBUG_MSG("glfw inited");
}

static void initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        std::runtime_error("glad initialization failed");
    }
    DEBUG_MSG("glad inited");
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
static void framebuffer_size_callback(GLFWwindow* window [[ gnu::unused ]],
int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void GLAPIENTRY messageCallback(GLenum source,
                                GLenum type,
                                GLuint id [[ gnu::unused ]],
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
