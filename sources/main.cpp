/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <functional>
#include <iostream>

#include "Engine/Graphics/Objects/3d/Multiple/EnlightenedCube.hpp"
#include "Engine/Graphics/Objects/3d/Single/LightSourceCube.hpp"
#include "ExampleScene.hpp"
#include "ModelScene.hpp"


int main()
{
    try {
        ExampleScene scene;

        while (!scene.isOver()) {
            scene.manageEvents();
            scene.update();
            scene.draw();
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
