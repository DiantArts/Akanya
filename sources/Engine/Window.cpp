/*
** EPITECH PROJECT, 2020
** sources/Engine/Window
** File description:
** Abstraction of GLFW
*/

#include "Window.hpp"

#include <iostream>
#include <glad/glad.h>

#include <stb/stb_image.h>


static void initGLWF();
static void initGLAD();

static void            mouseDirectionCallback(GLFWwindow* window, double xPos, double yPos);
static void            mouseScrollcallback(GLFWwindow* window, double xPos, double yPos);
static void            framebufferSizeCallback(GLFWwindow* window, int width, int height);
static void GLAPIENTRY messageCallback(GLenum        source,
                                       GLenum        type,
                                       GLuint        id,
                                       GLenum        severity,
                                       GLsizei       length,
                                       const GLchar* message,
                                       const void*   userParam);

bool gammaEnabled { false };
bool blinnEnabled { true };



namespace engine {


// ---------------------------------------------------------------------------- OpenGL stuff

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(m_Window.get());
}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(m_Window.get());
}

void Window::pollEvents()
{
    glfwPollEvents();
}



void Window::setClearColor(const float rgb, const float alpha /* = 1.0F */)
{
    glClearColor(rgb, rgb, rgb, alpha);
}

void Window::setClearColor(const float red,
                           const float green,
                           const float blue,
                           const float alpha /* = 1.0F */)
{
    glClearColor(red, green, blue, alpha);
}



// ---------------------------------------------------------------------------- input

void Window::processInput(const float deltaTime)
{
    this->pollEvents();
    if (glfwGetKey(m_Window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_Window.get(), true);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_W) == GLFW_PRESS) {
        this->camera.moveForward(deltaTime);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_S) == GLFW_PRESS) {
        this->camera.moveBackward(deltaTime);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_A) == GLFW_PRESS) {
        this->camera.moveLeft(deltaTime);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_D) == GLFW_PRESS) {
        this->camera.moveRight(deltaTime);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_SPACE) == GLFW_PRESS) {
        this->camera.moveTop(deltaTime);
    }
    if (glfwGetKey(m_Window.get(), GLFW_KEY_X) == GLFW_PRESS) {
        this->camera.moveBot(deltaTime);
    }

    if (glfwGetKey(m_Window.get(), GLFW_KEY_G) == GLFW_PRESS && !this->gammaKeyPressed) {
        gammaEnabled = !gammaEnabled;
        this->gammaKeyPressed = true;
    } if (glfwGetKey(m_Window.get(), GLFW_KEY_G) == GLFW_RELEASE) {
        this->gammaKeyPressed = false;
    }

    if (glfwGetKey(m_Window.get(), GLFW_KEY_B) == GLFW_PRESS && !this->blinnKeyPressed) {
        blinnEnabled = !blinnEnabled;
        this->blinnKeyPressed = true;
    } if (glfwGetKey(m_Window.get(), GLFW_KEY_B) == GLFW_RELEASE) {
        this->blinnKeyPressed = false;
    }
}



// ---------------------------------------------------------------------------- singleton

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
    m_Window.reset(glfwCreateWindow(this->width, this->height, "", glfwGetPrimaryMonitor(), nullptr));
    if (!m_Window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }

    // specifies the affine transformation of x and y from normalized devices
    // coordinates to window coordinates.
    glfwMakeContextCurrent(m_Window.get());
    glfwSetFramebufferSizeCallback(m_Window.get(), framebufferSizeCallback);

    // GLAD
    initGLAD();

    this->configure();
}

void Window::configure()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

#ifdef __APPLE__ // even if apple will soon not support OpenGL anymore
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // specifies the color values used by glClear to clear the color buffers
    // glClearColor(0.3F); // clear grey

    // mouse events
    glfwSetInputMode(m_Window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(m_Window.get(), mouseDirectionCallback);
    glfwSetScrollCallback(m_Window.get(), mouseScrollcallback);

    stbi_set_flip_vertically_on_load(true);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_FRAMEBUFFER_SRGB);

    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_CCW);

    // glEnable(GL_STENCIL_TEST);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(messageCallback, 0);

#ifdef DEBUG
    glfwSwapInterval(0); // disable vsync (testing purpuses)
#endif
}

Window& Window::get()
{
    return m_SingleInstance;
}

Window Window::m_SingleInstance;



} // namespace engine



// ---------------------------------------------------------------------------- init helpers

// provides a simple API for creating windows, contexts and surfaces,
// receiving input and events. (compatible window, X, wayland)
static void initGLWF()
{
    if (!glfwInit()) {
        throw std::runtime_error("glwfInit failed");
    }
}

static void initGLAD()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw std::runtime_error("glad initialization failed");
    }
}



// ---------------------------------------------------------------------------- callbacks

static void mouseDirectionCallback(GLFWwindow*, double xPos, double yPos)
{
    static float lastX;
    static float lastY;
    static short numberOfEmptyCAll = 2;

    if (numberOfEmptyCAll) {
        lastX = xPos;
        lastY = yPos;
        numberOfEmptyCAll--;
        engine::Window::camera.oriente(0, 0);
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos; // reversed since y-coordinates go from bottom to top
    lastX         = xPos;
    lastY         = yPos;


    engine::Window::camera.oriente(xOffset, yOffset);
}

static void mouseScrollcallback(GLFWwindow*, double, double yOffset)
{
    engine::Window::camera.zoom(yOffset);
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
static void GLAPIENTRY messageCallback(GLenum source,
                                       GLenum type,
                                       GLuint,
                                       GLenum severity,
                                       GLsizei,
                                       const GLchar* message,
                                       const void*)
{
    std::clog << "ERROR (GL): " << message;
    std::clog << " (src: " << source << ", type: " << type;
    std::clog << ", severity: ";
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH: std::clog << "high"; break;
    case GL_DEBUG_SEVERITY_MEDIUM: std::clog << "medium"; break;
    case GL_DEBUG_SEVERITY_LOW: std::clog << "low"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::clog << "notification"; break;
    }
    std::clog << ")" << std::endl;
}
