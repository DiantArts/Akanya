//
// Akanya
// sources/main
// Main of the program, must be simple
//

#include "pch.hpp"

#include "Game/Scenes/Example.hpp"



int main()
{
    try {
        ::engine::graphic::Window window;
        ::game::scene::Example scene(window);

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
