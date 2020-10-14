/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "DiEngine/Window.hpp"
#include "DiEngine/Shapes/Triangle.hpp"
#include "DiEngine/Shapes/Rectangle.hpp"
#include "DiEngine/Shapes/TestTexture.hpp"
#include "debugMacros.hpp"

int main()
{
    // init a window + every OpenGL's extentions
    DiEngine::Window window;
    // DiEngine::Shader shaderProgram("data/shaders/vertex", "data/shaders/fragment");
    DiEngine::Shader shaderProgramTexture("data/shaders/vertex_texture", "data/shaders/fragment_texture");

    DiEngine::Triangle triangle(shaderProgramTexture);
    // DiEngine::Rectangle rectangle(shaderProgram);
    // DiEngine::TestTexture testTexture(shaderProgramTexture);

    while (!window.shouldClose()) {
        window.processInput();

        // clear the window using glClearColor's value
        glClear(GL_COLOR_BUFFER_BIT);

        triangle.draw();
        // rectangle.draw();
        // testTexture.draw();

        window.swapBuffers();
        glfwPollEvents();
    }

    DEBUG_MSG("exiting correctly");
    return 0;
}

// glUniform4f(glGetUniformLocation(this->id, "ourColor"),
        // 0.0f, (std::sin(glfwGetTime()) / 2.0f) + 0.5f, 0.0f, 1.0f);
