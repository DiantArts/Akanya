/*
** Akanya, Engine
** sources/main
** Main of the program, must be simple
*/

#include "pch.hpp"

#include "Game/Scenes/Example.hpp"
#include "Game/Scenes/AdvancedLight.hpp"

#include "Engine/Core/Events/Keyboard.hpp"

void keyPressedHandler(::engine::core::event::KeyPressed& event)
{
    std::cout << __FUNCTION__  << ": " << event.getName() << std::endl;
}

void keyReleasedHandler(::engine::core::event::KeyReleased& event)
{
    std::cout << __FUNCTION__  << ": " << event << std::endl;
}



int main()
{
    // std::unique_ptr<engine::AEvent> event { new ::engine::core::event::KeyPressed(10) };
    // std::function<void(::engine::core::event::KeyPressed&)> func1 = keyPressedHandler;
    // std::function<void(::engine::core::event::KeyReleased&)> func2 = keyReleasedHandler;
    // event->handleWith(func1);
    // event->handleWith(func2);
    // return 0;
    try {
        ::engine::graphic::Window window;
        ::game::scene::Example scene(window);
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
