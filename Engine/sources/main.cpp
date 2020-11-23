/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <SFML/Audio.hpp>
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
        // enlightenedCubes.addPosition(0.6, 0, -1.0F);
        // enlightenedCubes.addPosition(-0.6, 0, -1.5F);

        enlightenedCubes.addPosition(0.0F, 0.0F, 0.0F);
        enlightenedCubes.addPosition(2.0F, 5.0F, -15.0F);
        enlightenedCubes.addPosition(-1.5F, -2.2F, -2.5F);
        enlightenedCubes.addPosition(-3.8F, -2.0F, -12.3F);
        enlightenedCubes.addPosition(2.4F, -0.4F, -3.5F);
        enlightenedCubes.addPosition(-1.7F, 3.0F, -7.5F);
        enlightenedCubes.addPosition(1.3F, -2.0F, -2.5F);
        enlightenedCubes.addPosition(1.5F, 2.0F, -2.5F);
        enlightenedCubes.addPosition(1.5F, 0.2F, -1.5F);
        enlightenedCubes.addPosition(-1.3F, 1.0F, -1.5F);


        window.camera.setSpeed(5);
        window.camera.setPosition(1.5, 3.0F, 7.5F);
        window.camera.setOrientation(-98, -15);



        for (float deltaTime = 0; !window.shouldClose(); deltaTime = clock.getElapsedTime()) {
            window.processInput(deltaTime);

            window.clear();
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
