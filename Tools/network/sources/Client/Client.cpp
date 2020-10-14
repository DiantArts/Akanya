/*
** EPITECH PROJECT, 2020
** Client
** File description:
** Client's part of the game network
*/

#include <csignal>
#include <thread>
#include <chrono>
#include <atomic>
#include <cerrno>
#include <sstream>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "debugMacros.hpp"
#include "Client.hpp"

namespace parameter {
    static volatile bool isRunning = true; // set to false when SIGINT is caught
    static char errorMsg[256];

    const char *const addr = "127.0.0.1";
    static constexpr auto port = 8081;
} // namespace parameter

std::uint_fast32_t Client::id = 1;

static void signalHandler(int _ [[ gnu::unused ]])
{
    DEBUG_MSG("signal caught");
    parameter::isRunning = false;
}

Client::Client()
    : m_Id(id++), m_ServerSocketFd(socket(AF_INET, SOCK_STREAM, 0))
    , m_ServerAddrPtr(new struct sockaddr_in)
{
    signal(SIGINT, signalHandler);

    if (this->m_ServerSocketFd == -1) {
        this->throwErrorMsg("socket()"); // socket() failed
    }
    if (!this->m_ServerAddrPtr) {
        this->throwErrorMsg("new[]"); // new[] failed
    }

    // fill struct addr
    memset(this->m_ServerAddrPtr, 0, sizeof(struct sockaddr_in));
    this->m_ServerAddrPtr->sin_family = AF_INET;
    this->m_ServerAddrPtr->sin_addr.s_addr = inet_addr(parameter::addr);
    this->m_ServerAddrPtr->sin_port = htons(parameter::port);

    // try to connect to server
    DEBUG_MSG(*this << ": trying to connect to " << parameter::addr << ":" << parameter::port);
    if (connect(this->m_ServerSocketFd, reinterpret_cast<struct sockaddr*>(this->m_ServerAddrPtr),
                sizeof(*this->m_ServerAddrPtr))) {
        this->throwErrorMsg("connect()"); // connect failed
    }
    DEBUG_MSG(*this << ": connected");
}

Client::~Client()
{
    close(this->m_ServerSocketFd);
    delete this->m_ServerAddrPtr;
}

void Client::process()
{
    DEBUG_TIME;

    while (parameter::isRunning) {
        std::cout << *this << ": " << std::endl;
        std::string bufInput;
        if (!std::getline(std::cin, bufInput)) {
            return ;
        }
        write(this->m_ServerSocketFd, bufInput.c_str(), bufInput.size());
    }
}

std::uint_fast32_t Client::getId() const noexcept
{
    return this->m_Id;
}

void Client::run(Client& client) noexcept
{
    try {
        client.process();
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << client << e.what() << "\n";
    } catch (...) {
        std::cerr << "ERROR: " << client << "unknown\n";
    }
}

void Client::throwErrorMsg(const char *const funcName) const
{
    std::string str("[Client ");
    str += std::to_string(this->m_Id);
    str += "]: ";
    str += funcName;
    str += " failed: ";

#if (_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE // POSIX
    char *buf;
    int res = strerror_r(errno, parameter::errorMsg, sizeof(tmpbuf));

    if (res < 0) { // glibc < 2.13
        if (errno == EINVAL) {
            memcpy(buf, "Unknown error code", sizeof("Unknown error code"));
        }
    } else if (res) { // glibc >= 2.13
        if (res == EINVAL) {
            memcpy(buf, "Unknown error code", sizeof("Unknown error code"));
        }
    }

    if (parameter::errorMsg) {
        std::size_t tmplen = strlen(tmpbuf);
        str = memcpy(buf, tmpbuf, MIN(tmplen + 1, parameter::errorMsg));
        str[MIN(tmplen, parameter::errorMsg - 1)] = '\0';
    } else {
        str += buf;
    }
#else // GNU
    str += strerror_r(errno, parameter::errorMsg, 256);
#endif
    throw std::runtime_error(str);
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "[Client " << client.getId() << "]";
    return os;
}
