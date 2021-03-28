/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Server.hpp
*/

#ifndef INCLUDED_COM_SERVER_HPP
#define INCLUDED_COM_SERVER_HPP

#include "Peer.hpp"
#include <list>
#include <random>
#include <unordered_map>

namespace communication {


class Dispatcher {

public:
    using DisconnectedHandler = std::function<void()>;

public:
    explicit Dispatcher(Peer::MsgReceivedHandler& msg_received_handler,
                        DisconnectedHandler& disconnected_handler);

public:
    bool add_peer(const udp::endpoint& endpoint, Msg::Arg game_id);
    void run();

private:
    boost::asio::io_context context_;
    std::list<std::pair<udp::endpoint, Peer>> players_;

    Peer::MsgReceivedHandler msg_received_handler_;
    DisconnectedHandler& disconnected_handler_;
};


class Server {

public:
    explicit Server(Peer::MsgReceivedHandler, Dispatcher::DisconnectedHandler);

private:
    void join_game(udp::endpoint from, Msg);

private:
    boost::asio::io_context context_;
    Peer peer_;

    Peer::MsgReceivedHandler msg_received_handler_;
    Dispatcher::DisconnectedHandler disconnected_handler_;

    std::default_random_engine random_engine_{std::random_device{}()};
    std::uniform_int_distribution<Msg::Arg> game_id_gen_{1};

    std::unordered_map<Msg::Arg, Dispatcher> games_;
    std::mutex games_mutex_;
};


} // namespace communication

#endif // INCLUDED_COM_SERVER_HPP
