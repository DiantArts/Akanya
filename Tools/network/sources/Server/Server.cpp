/*
** EPITECH PROJECT, 2020
** Server
** File description:
** Server's part of the game network
*/

#include <csignal>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <cerrno>
#include <cstring>
#include <sstream>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "debugMacros.hpp"
#include "Server.hpp"

namespace global {
    std::int_fast32_t stoppingWriteFd; // writing pipe to stop the server (select)
    std::int_fast32_t stoppingReadFd;  // reading pipe to stop the server (select)
    static volatile bool isRunning = true; // set to false when SIGINT is caught
} // namespace global


static void signalHandler(int _ [[ gnu::unused ]])
{
    DEBUG_MSG("signal caught");
    global::isRunning = false;
    write(global::stoppingWriteFd, "s", 1);
}

Server::Server()
    : m_SocketFd(socket(Server::domain, Server::type, Server::protocol))
    , m_ServerAddrPtr(new struct sockaddr_in)
{
    signal(SIGINT, signalHandler);
    pipeStoppingFd();

    if (this->m_SocketFd == -1) {
        this->throwErrorMsg("socket()"); // socket() failed
    }
    if (!this->m_ServerAddrPtr) {
        this->throwErrorMsg("new[]"); // new[] failed
    }

    // fill struct addr
    memset(this->m_ServerAddrPtr, 0, sizeof(struct sockaddr_in));
    this->m_ServerAddrPtr->sin_family = Server::domain;
    this->m_ServerAddrPtr->sin_addr.s_addr = htonl(INADDR_ANY);
    this->m_ServerAddrPtr->sin_port = htons(Server::port);

    if (bind(this->m_SocketFd, reinterpret_cast<struct sockaddr *>(this->m_ServerAddrPtr),
             sizeof(*this->m_ServerAddrPtr)) == -1) {
        this->throwErrorMsg("bind()"); // bind() failed
    } else if (listen(this->m_SocketFd, Server::listenBacklog) == -1) {
        this->throwErrorMsg("listen()"); // listen() failed
    }
    DEBUG_MSG(*this << ": listening " << Server::port);

    FD_ZERO(&this->m_FdSet);
    FD_SET(this->m_SocketFd, &this->m_FdSet);
    FD_SET(global::stoppingReadFd, &this->m_FdSet);
}

Server::~Server()
{
    close(this->m_SocketFd);
    close(global::stoppingReadFd);
    close(global::stoppingWriteFd);
    delete this->m_ServerAddrPtr;
}

// ==================================================================================== commands

void Server::login()
{
    std::string buf;

    // get accounts config file
    std::ifstream serverConfigFile(Server::serverConfigFilepath);
    if (!serverConfigFile.is_open() || !std::getline(serverConfigFile, buf)) {
        this->throwErrorMsg("login (server general config)");
    }

    // get accounts config file
    std::ifstream accountsConfigFile(buf);
    if (!accountsConfigFile.is_open()) {
        this->throwErrorMsg("login (server general config)");
    }
}

// =================================================================================== interact
bool Server::interact(std::int_fast32_t clientFd)
{
    ssize_t nbytes;


    this->m_Buf[nbytes = read(clientFd, this->m_Buf, 255)] = 0;
    if (nbytes < 0) {
        this->throwErrorMsg("pselect()"); // select() failed
    } else if (!nbytes) {
        return false;
    } else {
        std::cout << "[Client " << clientFd << "]: " << this->m_Buf << std::endl;
        return true;
    }
}

// =================================================================================== process

void Server::process()
{
    DEBUG_TIME;

    while (global::isRunning) {
        fd_set readFdSet = this->m_FdSet;
        if (pselect(FD_SETSIZE, &readFdSet, nullptr, nullptr, nullptr, nullptr) < 0) {
            this->throwErrorMsg("pselect()"); // select() failed
        }
        for (int_fast32_t i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &readFdSet)) {
                if (i == this->m_SocketFd) {
                    struct sockaddr_in peerAddr;
                    this->acceptIncommingConnection(&peerAddr);
                } else if (i == global::stoppingReadFd) {
                    return ;
                } else  {
                    interact(i);
                }
            }
        }
    }
}

void Server::acceptIncommingConnection(struct sockaddr_in* peerAddr)
{
    socklen_t peerAddrSize = sizeof(peerAddr);
    int_fast32_t acceptedSocket = accept(this->m_SocketFd,
            reinterpret_cast<struct sockaddr*>(peerAddr), &peerAddrSize);

    if (acceptedSocket == -1) {
        this->throwErrorMsg("accept()"); // accept() failed
    }
    FD_SET(acceptedSocket, &this->m_FdSet);
    DEBUG_MSG("connection accepted");
}

void Server::run(Server& server) noexcept
{
    try {
        server.process();
    } catch (const std::exception& e) {
        global::isRunning = false;
        std::cerr << "ERROR: " << server << e.what() << "\n";
    } catch (...) {
        global::isRunning = false;
        std::cerr << "ERROR: " << server << "unknown\n";
    }
}

// =================================================================================== privateTools

void Server::pipeStoppingFd()
{
    int fdArray[2];

    if (pipe(fdArray)) {
        this->throwErrorMsg("pipe()"); // socket() failed
    }

    // those two fd are needed to cut the select of the server
    global::stoppingReadFd = fdArray[0];
    global::stoppingWriteFd = fdArray[1];
}


void Server::throwErrorMsg(const char *const funcName) const
{
    std::string str("[Server]: ");
    str += funcName;
    str += " failed: ";

#if (_POSIX_C_SOURCE >= 200112L) && !_GNU_SOURCE // POSIX
    char *buf;
    int res = strerror_r(errno, this->m_Buf, sizeof(tmpbuf));

    if (res < 0) { // glibc < 2.13
        if (errno == EINVAL) {
            memcpy(buf, "Unknown error code", sizeof("Unknown error code"));
        }
    } else if (res) { // glibc >= 2.13
        if (res == EINVAL) {
            memcpy(buf, "Unknown error code", sizeof("Unknown error code"));
        }
    }

    if (this->m_Buf) {
        std::size_t tmplen = strlen(tmpbuf);
        str = memcpy(buf, tmpbuf, MIN(tmplen + 1, this->m_Buf));
        str[MIN(tmplen, this->m_Buf - 1)] = '\0';
    } else {
        str += buf;
    }
#else // GNU
    str += strerror_r(errno, (char *)this->m_Buf, 256);
#endif
    throw std::runtime_error(str);
}

std::ostream& operator<<(std::ostream& os, const Server& _ [[gnu::unused]])
{
    os << "[Server]";
    return os;
}
