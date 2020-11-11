/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <functional>
#include "Window.hpp" // need to be included before <GLFW/glfw3.h>
#include <GLFW/glfw3.h>
#include "Engine/Camera.hpp"
#include "debugMacros.hpp"

void mouseDirectionCallback(GLFWwindow* window [[ gnu::unused ]], double xpos, double ypos)
{
    (void)xpos;
    (void)ypos;
}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
void framebufferSizeCallback(GLFWwindow* window [[ gnu::unused ]],
int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// GLAPIENTRY: Windows compatibility tool
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
