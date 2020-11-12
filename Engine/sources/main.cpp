/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <functional>
#include <iostream>
#include "Engine/Window.hpp"
#include "Engine/Shapes/2d/Triangle.hpp"
#include "Engine/Shapes/3d/Cube.hpp"
#include "Engine/Shapes/3d/ImprovedCube.hpp"
#include "Engine/Clock.hpp"

int main()
{
    try {
        engine::Window window;
        engine::Shader shaderProgram("data/shaders/vertexes/camera", "data/shaders/fragments/camera");
        engine::shape3d::ImprovedCube cube(shaderProgram);
        // engine::shape3d::Cube cube(shaderProgram);
        engine::Clock clock;

        window.camera.speed = 5;
        for (float deltaTime = 0; !window.shouldClose(); deltaTime = clock.getElapsedTime()) {
            window.processInput(deltaTime);

            glClear(GL_COLOR_BUFFER_BIT);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            cube.draw(window.camera);

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
