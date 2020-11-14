/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <functional>
#include <iostream>
#include "Engine/Window.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Clock.hpp"
#include "Engine/Shapes/3d/Cube.hpp"
#include "Engine/Shapes/3d/EnlightenedCube.hpp"
#include "Engine/Shapes/3d/LightSourceCube.hpp"

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

int main()
{
    try {
        engine::Window window;
        engine::Clock clock;

        // engine::Shader shader("camera", "camera");
        // engine::shape3d::Cube cube(shader);
        // cube.addPosition(-5, 0, -5);

        engine::Shader shaderEnlightened("enlightened", "enlightened");
        engine::shape3d::EnlightenedCube enlightenedCube(shaderEnlightened);
        enlightenedCube.addPosition(0, 0, -5);

        engine::Shader shaderLightSource("lightSource", "lightSource");
        engine::shape3d::LightSourceCube lightSourceCube(shaderLightSource);
        lightSourceCube.addPosition(1.2f, 1.0f, 2.0f);

        window.camera.speed = 5;
        for (float deltaTime = 0; !window.shouldClose(); deltaTime = clock.getElapsedTime()) {
            window.processInput(deltaTime);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            enlightenedCube.draw(window.camera);
            lightSourceCube.draw(window.camera);

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
