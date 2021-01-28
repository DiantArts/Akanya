/*
** Akanya, Engine
** sources/Engine/Window
** Abstraction of GLFW
*/

#include "pch.hpp"
#include "Window.hpp"


namespace {


void mouseDirectionCallback(
    GLFWwindow*,
    double xPos,
    double yPos
);

void mouseScrollcallback(
    GLFWwindow*,
    double,
    double yOffset
);

void framebufferSizeCallback(
    GLFWwindow*,
    int width,
    int height
);

void GLAPIENTRY messageCallback(
    GLenum source,
    GLenum type,
    GLuint,
    GLenum severity,
    GLsizei,
    const GLchar* message,
    const void*
);



} // namespace



namespace engine::graphic {



// ---------------------------------- *structors

Window::Window()
{
    // provides a simple API for creating windows, contexts and surfaces,
    // receiving input and events. (compatible window, X, wayland)

    m_window.reset(glfwCreateWindow(
            this->getSize().width,
            this->getSize().height,
            "MainWindow",
            glfwGetPrimaryMonitor(), // allows a fullscreen rendering
            nullptr
        ));
    if (!m_window) {
        glfwTerminate();
        throw std::runtime_error("Window creation failed");
    }

    // specifies the affine transformation of x and y from normalized devices
    // coordinates to window coordinates.
    glfwMakeContextCurrent(m_window.get());
    glfwSetFramebufferSizeCallback(m_window.get(), framebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        throw std::runtime_error("glad initialization failed");
    }

    this->configureDefault();
}

Window::~Window()
{}



// ---------------------------------- Loop

auto Window::shouldClose() const
    -> bool
{
    return glfwWindowShouldClose(m_window.get());
}



// ---------------------------------- OpenGL stuff

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::swapBuffers() const
{
    glfwSwapBuffers(m_window.get());
}

void Window::pollEvents()
{
    glfwPollEvents();
}



// ---------------------------------- input

void Window::processInput(
    const float deltaTime
)
{
    this->pollEvents();

    if (glfwGetKey(m_window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window.get(), true);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_W) == GLFW_PRESS) {
        m_camera.moveForward(deltaTime);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_S) == GLFW_PRESS) {
        m_camera.moveBackward(deltaTime);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_A) == GLFW_PRESS) {
        m_camera.moveLeft(deltaTime);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_D) == GLFW_PRESS) {
        m_camera.moveRight(deltaTime);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_SPACE) == GLFW_PRESS) {
        m_camera.moveTop(deltaTime);
    }
    if (glfwGetKey(m_window.get(), GLFW_KEY_X) == GLFW_PRESS) {
        m_camera.moveBot(deltaTime);
    }

    if (glfwGetKey(m_window.get(), GLFW_KEY_G) == GLFW_PRESS && !m_keyPressed.gamma) {
        m_config.gamma = !m_config.gamma;
        m_keyPressed.gamma = true;
    } if (glfwGetKey(m_window.get(), GLFW_KEY_G) == GLFW_RELEASE) {
        m_keyPressed.gamma = false;
    }

    if (glfwGetKey(m_window.get(), GLFW_KEY_B) == GLFW_PRESS && !m_keyPressed.blinn) {
        m_config.blinn = !m_config.blinn;
        m_keyPressed.blinn = true;
    } if (glfwGetKey(m_window.get(), GLFW_KEY_B) == GLFW_RELEASE) {
        m_keyPressed.blinn = false;
    }
}


// ---------------------------------- Camera

auto Window::getCamera() const
    -> const ::engine::graphic::Camera&
{
    return m_camera;
}



void Window::setCameraSpeed(
    float value
)
{
    m_camera.setSpeed(value);
}



void Window::setCameraPosition(
    float xOffset,
    float yOffset,
    float zOffset
)
{
    m_camera.setPosition(xOffset, yOffset, zOffset);
}

void Window::setCameraPosition(
    const ::glm::vec3& offset
)
{
    m_camera.setPosition(offset);
}



void Window::orienteCamera(
    float xOffset,
    float yOffset
)
{
    m_camera.oriente(xOffset, yOffset);
}

void Window::orienteCamera(
    const ::glm::vec2& offset
)
{
    m_camera.oriente(offset);
}

void Window::setCameraOrientation(
    float xOffset,
    float yOffset
)
{
    m_camera.setOrientation(xOffset, yOffset);
}

void Window::setCameraOrientation(
    const ::glm::vec2& offset
)
{
    m_camera.setOrientation(offset);
}



void Window::zoomCamera(
    float value
)
{
    m_camera.zoom(value);
}

void Window::setCameraZoom(
    float value
)
{
    m_camera.setZoom(value);
}



// ---------------------------------- Size

auto Window::getSize() const
    -> const Window::Size&
{
    return m_size;
}



// ---------------------------------- Config

auto Window::getConfig() const
    -> const Window::Config&
{
    return m_config;
}



// ---------------------------------- Configuration

void Window::configureDefault()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwSetInputMode(m_window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(m_window.get(), mouseDirectionCallback);
    glfwSetScrollCallback(m_window.get(), mouseScrollcallback);

#ifdef __APPLE__ // even if apple will soon not support OpenGL anymore
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif // __APPLE__

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

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
    glfwSwapInterval(0); // disable vsync
#endif
}

void Window::configureClearColor(
    const float rgb,
    const float alpha
)
{
    glClearColor(rgb, rgb, rgb, alpha);
}

void Window::configureClearColor(
    const float red,
    const float green,
    const float blue,
    const float alpha
)
{
    glClearColor(red, green, blue, alpha);
}



// ---------------------------------- Deleter

void Window::Deleter::operator()(
    GLFWwindow* window
)
{
    glfwDestroyWindow(window);
}



} // namespace engine::graphic




// ---------------------------------- callbacks

namespace {



struct OpenglMemoryManager {
    OpenglMemoryManager()
    {
        if (!glfwInit()) {
            throw std::runtime_error("glwfInit failed");
        }

        stbi_set_flip_vertically_on_load(true);
    }

    ~OpenglMemoryManager()
    {
        glfwTerminate();
    }
};
const OpenglMemoryManager _openglMemoryManager;


void mouseDirectionCallback(
    GLFWwindow*,
    double xPos,
    double yPos
)
{
    static float lastX;
    static float lastY;
    static short numberOfEmptyCAll = 2;

    if (numberOfEmptyCAll) {
        lastX = xPos;
        lastY = yPos;
        numberOfEmptyCAll--;
        // engine::graphic::Window::camera.oriente(0, 0);
    }

    float xOffset = xPos - lastX;
    float yOffset = lastY - yPos; // reversed since y-coordinates go from bottom to top
    lastX         = xPos;
    lastY         = yPos;


    // engine::graphic::Window::camera.oriente(xOffset, yOffset);
}

void mouseScrollcallback(
    GLFWwindow*,
    double,
    double yOffset
)
{
    // engine::graphic::Window::camera.zoom(yOffset);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebufferSizeCallback(
    GLFWwindow*,
    int width,
    int height
)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void GLAPIENTRY messageCallback(
    GLenum source,
    GLenum type,
    GLuint,
    GLenum severity,
    GLsizei,
    const GLchar* message,
    const void*
)
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



} // namespace
