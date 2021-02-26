//
// Akanya, Engine
// sources/Engine/Window
// Abstraction of GLFW
//

#include "pch.hpp"

#include "../Core/Events/KeyPressed.hpp"
#include "../Core/Events/KeyReleased.hpp"
#include "../Core/Events/MouseButtonPressed.hpp"
#include "../Core/Events/MouseButtonReleased.hpp"
#include "../Core/Events/MousePosition.hpp"
#include "../Core/Events/MouseScroll.hpp"
#include "../Core/Events/KeyModifier.hpp"



namespace {

void keyModifierCallback(
    GLFWwindow* window,
    unsigned int codepoint,
    int mods
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

void keyCallback(
    GLFWwindow* window,
    int keyCode,
    int,
    int action,
    int mods
);

void mousePositionCallback(
    GLFWwindow* window,
    double xPos,
    double yPos
);

void mouseButtoncallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods
);

void mouseScrollcallback(
    GLFWwindow* window,
    double xoffset,
    double yoffset
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

    glfwSetWindowUserPointer(m_window.get(), reinterpret_cast<void*>(&m_eventContainer));

    //this->centerCursor();
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



// ---------------------------------- input

void Window::processInput(
    engine::graphic::AScene& scene
)
{
    glfwPollEvents();
    m_eventContainer.resolve(scene);
}

void Window::centerCursor() const
{
    glfwSetCursorPos(m_window.get(), m_size.width / 2, m_size.height / 2);
}

auto Window::getCursorPosition() const
    -> ::glm::vec2
{
    double xPos, yPos;
    glfwGetCursorPos(m_window.get(), &xPos, &yPos);
    return ::glm::vec2 { xPos, yPos };
}



// ---------------------------------- Size

auto Window::getSize() const
    -> const Window::Size&
{
    return m_size;
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
    glfwSetCursorPosCallback(m_window.get(), mousePositionCallback);
    glfwSetScrollCallback(m_window.get(), mouseScrollcallback);
    glfwSetMouseButtonCallback(m_window.get(), mouseButtoncallback);
    //glfwSetCharModsCallback(m_window.get(), keyModifierCallback);
    glfwSetKeyCallback(m_window.get(), keyCallback);

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



class OpenglMemoryManager {
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

    static constinit const OpenglMemoryManager _;
};
const OpenglMemoryManager OpenglMemoryManager::_;


void keyModifierCallback(
    GLFWwindow* window,
    unsigned int codepoint,
    int mods
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    events.emplace<::engine::core::event::KeyModifier>(std::move(codepoint), std::move(mods));
}

void keyCallback(
    GLFWwindow* window,
    int keyCode,
    int,
    int action,
    int mods [[ gnu::unused ]]
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    if (action == GLFW_PRESS) {
        events.emplace<::engine::core::event::KeyPressed>(std::move(keyCode));
    } else if (action == GLFW_RELEASE) {
        events.emplace<::engine::core::event::KeyReleased>(std::move(keyCode));
    }
}

void mousePositionCallback(
    GLFWwindow* window,
    double xPos,
    double yPos
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    events.emplace<::engine::core::event::MousePosition>(std::move(xPos), std::move(yPos));
}

void mouseButtoncallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods [[ gnu::unused ]]
)
{
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    if (action == GLFW_PRESS) {
        events.emplace<::engine::core::event::MouseButtonPressed>(std::move(button));
    } else if (action == GLFW_RELEASE) {
        events.emplace<::engine::core::event::MouseButtonReleased>(std::move(button));
    }
}

void mouseScrollcallback(
    GLFWwindow* window,
    double xoffset,
    double yoffset [[ gnu::unused ]]
)
{
    // engine::graphic::Window::camera.zoom(yOffset);
    std::cout << "yo" << std::endl;
    auto& events = *reinterpret_cast<::engine::core::event::Container*>(glfwGetWindowUserPointer(window));
    events.emplace<::engine::core::event::MouseScroll>(std::move(xoffset), std::move(yoffset));
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
