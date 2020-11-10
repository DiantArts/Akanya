/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <iostream>
#include "Engine/Window.hpp"
#include "Engine/Shapes/Triangle.hpp"
// #include "Engine/Shapes/Rectangle.hpp"
// #include "Engine/Shapes/TestTexture.hpp"

int main()
{
    try {
        // init a window + every OpenGL's extentions
        engine::Window window;
        engine::Shader shaderProgram("data/shaders/vertex", "data/shaders/fragment");
        // engine::Shader shaderProgramTexture("data/shaders/vertex_texture", "data/shaders/fragment_texture");

        engine::Triangle triangle(shaderProgram);
        // engine::TestTexture testTexture(shaderProgramTexture);

        while (!window.shouldClose()) {
            window.processInput();

            // clear the window using glClearColor's value
            glClear(GL_COLOR_BUFFER_BIT);

            triangle.draw();

            window.swapBuffers();
        }

        return EXIT_SUCCESS;
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "ERROR: unknown" << std::endl;
        return EXIT_FAILURE;
    }
}

// glUniform4f(glGetUniformLocation(this->id, "ourColor"),
        // 0.0f, (std::sin(glfwGetTime()) / 2.0f) + 0.5f, 0.0f, 1.0f);
