/*
** EPITECH PROJECT, 2020
** main
** File description:
** Entry of the program
*/

#include <mutex>
#include <unistd.h>
#include <iostream>
#include <csignal>
#include <atomic>
#include <thread>
#include "Client/Client.hpp"
#include "Server/Server.hpp"

int main(const int argc, const char *const argv[] [[ gnu::unused ]])
{
    try {
        if (argc == 1) {
            Server server;
            Client client;

            std::thread serverThread(static_cast<void(*)(Server&)>(Server::run), std::ref(server));
            std::thread clientThread(static_cast<void(*)(Client&)>(Client::run), std::ref(client));

            serverThread.join();
            clientThread.join();

        } else if (argc == 2) {
            Server().process();
        } else if (argc == 3) {
            Client().process();
        }

        return EXIT_SUCCESS;

    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
}
