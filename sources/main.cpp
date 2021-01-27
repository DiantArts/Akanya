/*
** EPITECH PROJECT, 2020
** sources/main
** File description:
** Main of the program, must be simple
*/

#include "pch.hpp"

#include "Game/Scenes/Example.hpp"
#include "Game/Scenes/AdvancedLight.hpp"

#include "Engine/Events/Keyboard.hpp"

void keyPressedHandler(engine::event::KeyPressed& event)
{
    std::cout << __FUNCTION__  << ": " << event.getName() << std::endl;
}

void keyReleasedHandler(engine::event::KeyReleased& event)
{
    std::cout << __FUNCTION__  << ": " << event << std::endl;
}



int main()
{
    // std::unique_ptr<engine::AEvent> event { new engine::event::KeyPressed(10) };
    // std::function<void(engine::event::KeyPressed&)> func1 = keyPressedHandler;
    // std::function<void(engine::event::KeyReleased&)> func2 = keyReleasedHandler;
    // event->handleWith(func1);
    // event->handleWith(func2);
    // return 0;
    try {
        game::scene::Example scene;
        // game::scene::AdvancedLight scene;

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
