#include <iostream>

#include "Communication/Server.hpp"

int main()
{
    // try {
        communication::Server server {{},
            [] { std::cout << "Client disconnected" << std::endl; }
        };

        return EXIT_SUCCESS;
    // } catch (const std::exception& e) {
        // std::cerr << "ERROR: " << e.what() << std::endl;
        // return EXIT_FAILURE;

    // } catch (...) {
        // std::cerr << "ERROR: unknown" << std::endl;
        // return EXIT_FAILURE;

    // }
}
