/*
** EPITECH PROJECT, 2020
** sources/main
** File description:
** Main of the program, must be simple
*/

#include "main.hpp"
#include <iostream>

#include "ExampleScene.hpp"


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
