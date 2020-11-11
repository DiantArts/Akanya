/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <iostream>
#include "Engine/Window.hpp"
#include "Engine/Shapes/2d/Triangle.hpp"
#include "Engine/Shapes/3d/ModelMatrix.hpp"
#include "Engine/Shapes/3d/TestTexture.hpp"

int main()
{
    try {
        engine::Window window;
        engine::Shader shaderProgram("data/shaders/vertexes/base", "data/shaders/fragments/base");
        // engine::shape3d::ModelMatrix model(shaderProgram);
        engine::shape3d::TestTexture model(shaderProgram);

        while (!window.shouldClose()) {
            window.processInput();

            glClear(GL_COLOR_BUFFER_BIT);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            model.draw();

            window.pollEvents();
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
