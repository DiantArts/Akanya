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
#include "Engine/Shapes/3d/LightCube.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Clock.hpp"

int main()
{
    try {
        engine::Window window;
        engine::Clock clock;
        engine::Shader shader("data/shaders/vertexes/camera", "data/shaders/fragments/camera");
        // engine::Shader shader("data/shaders/vertexes/enlightened", "data/shaders/fragments/enlightened");
        // engine::Shader shaderLight("data/shaders/vertexes/lightSource", "data/shaders/fragments/lightSource");

        engine::shape3d::LightCube lightCube(shader);
        lightCube.addPosition(5, 2, -5);

        // engine::shape3d::Cube lightSource(shader);
        // lightSource.addPosition(-5, 2, -5);

        engine::shape3d::Cube cube(shader);
        cube.addPosition(0, 0, -5);
        cube.addTexture("data/textures/wall.jpg", "texture1", 0);
        cube.addTexture("data/textures/awesomeface.png", "texture2", 1);

        window.camera.speed = 5;
        for (float deltaTime = 0; !window.shouldClose(); deltaTime = clock.getElapsedTime()) {
            window.processInput(deltaTime);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            cube.draw(window.camera);
            lightCube.draw(window.camera);

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
