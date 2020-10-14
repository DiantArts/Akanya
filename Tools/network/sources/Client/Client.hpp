/*
** EPITECH PROJECT, 2020
** Client
** File description:
** Client's part of the game network
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

class Client {
public:
    Client();
    ~Client();

    void process();
    std::uint_fast32_t getId() const noexcept;
    static void run(Client& client) noexcept;

private:
    void throwErrorMsg(const char *const funcName) const;

public:
    static std::uint_fast32_t id;

private:
    std::uint_fast32_t m_Id;
    std::int_fast32_t m_ServerSocketFd;
    struct sockaddr_in* m_ServerAddrPtr;
};

std::ostream& operator<<(std::ostream& os, const Client& client);

#endif // CLIENT_HPP
