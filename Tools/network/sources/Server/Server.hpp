/*
** EPITECH PROJECT, 2020
** Server
** File description:
** Server's part of the game network
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <arpa/inet.h>

class Server {
public:
    Server();
    ~Server();

// ==================================================================================== commands
    void login();

// =================================================================================== interact
    bool interact(std::int_fast32_t clientFd);

// =================================================================================== process
    void process();
    static void run(Server& server) noexcept;

private:
// =================================================================================== privateTools
    void pipeStoppingFd();
    void throwErrorMsg(const char *const funcName) const;
    void acceptIncommingConnection(struct sockaddr_in* peerAddr);

// ==================================================================================== variables
private:
    static constexpr auto port = 8081;
    static constexpr auto domain = AF_INET;
    static constexpr auto type = SOCK_STREAM;
    static constexpr auto protocol = 0;
    static constexpr auto listenBacklog = 256;
    const char *const serverConfigFilepath = "data/server/general.conf";

private:
    std::int_fast32_t m_SocketFd;
    struct sockaddr_in* m_ServerAddrPtr;
    fd_set m_FdSet;
    char m_Buf[256];
};

std::ostream& operator<<(std::ostream& os, const Server& server);

#endif // SERVER_HPP
