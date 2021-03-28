/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Client.hpp
*/

#ifndef INCLUDED_COM_CLIENT_HPP
#define INCLUDED_COM_CLIENT_HPP

#include "Peer.hpp"

namespace communication {


class Client {

private:
    static inline const auto server_address
        {boost::asio::ip::make_address("::1")};
public:
    struct StopRequested {
        template<typename Fn>
        StopRequested(Fn&& fn) : fn_{std::forward<Fn>(fn)} {}
        operator bool() const { return fn_(); }
    private:
        std::function<bool()> fn_;
    };

private:
    using GameIdGetter = std::function<Msg::Arg()>;
    using GameLoadingHandler = std::function<void(const StopRequested&)>;
    using MsgReceivedHandler = std::function<void(const Msg&)>;

public:
    explicit Client(GameIdGetter, GameLoadingHandler, MsgReceivedHandler);
    ~Client() { context_.stop(); sender_thread_.join(); }

public:
    Peer* operator->();

private:
    boost::asio::io_context context_;
    Peer peer_;
    std::thread sender_thread_;

    std::packaged_task<Msg::Arg()> game_id_getter_;
    std::shared_future<Msg::Arg> game_id_;
    GameLoadingHandler game_loading_handler_;
};


} // namespace communication

#endif // INCLUDED_COM_CLIENT_HPP
