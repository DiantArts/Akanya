/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <functional>
#include <iostream>

#include "Engine/Camera.hpp"
#include "Engine/Clock.hpp"
#include "Engine/Objects/3d/Multiple/EnlightenedCube.hpp"
#include "Engine/Objects/3d/Single/LightSourceCube.hpp"
#include "Engine/Shader.hpp"
#include "Engine/Window.hpp"

extern engine::object3d::single::LightSourceCube& getLamp(); // tmp

int main()
{
    try {
        engine::Window window;
        engine::Clock  clock;

        engine::Shader                              enlightenedShader("enlightened", "enlightened");
        engine::object3d::multiple::EnlightenedCube enlightenedCubes(enlightenedShader);
        enlightenedCubes.addTexture("container.png", "material.diffuse", 0);
        enlightenedCubes.addTexture("containerBorders.png", "material.specular", 1);
        enlightenedCubes.addPosition(0.6, 0, -1.0f);
        enlightenedCubes.addPosition(-0.6, 0, -1.5f);

        window.camera.setSpeed(5);
        window.camera.setPosition(0.5, 1.5f, 3.0f);
        window.camera.setOrientation(-95, -15);
        for (float deltaTime = 0; !window.shouldClose(); deltaTime = clock.getElapsedTime()) {
            window.processInput(deltaTime);

            // glm::vec3 lightColor(sin(glfwGetTime() * 2.0f), sin(glfwGetTime() * 0.7f), sin(glfwGetTime()
            // * 1.3f)); getLamp().setLightDiffuse(lightColor * glm::vec3(0.5f));
            // getLamp().setLightAmbient(lightColor * glm::vec3(0.5f) * glm::vec3(0.2f));
            getLamp().setPosition(
                glm::vec3(cos(glfwGetTime() * 2) * 10.0f, 5, -1 + sin(glfwGetTime() * 2) * 10.0f));

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            enlightenedCubes.draw(window.camera);
            getLamp().draw(window.camera);

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
