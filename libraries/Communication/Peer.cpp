/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Peer.cpp
*/

#include "Communication/Peer.hpp"
#include <iostream>
#include <thread>

namespace communication {


Peer::operator bool() noexcept
{
    if (connected_ && clock::now() - last_ping_ > std::chrono::seconds{5}) {
        udp::socket::connect({udp::v6(), 0});
        connected_ = false;
    }
    return connected_;
}

void Peer::connect(const udp::endpoint& to)
{
    udp::socket::connect(to);
    connected_ = true;
    sent_msg_id_ = received_msg_id_ = {};
    last_ping_ = clock::now();
}


void Peer::send_msg(bool important, Msg::Type type,
    Msg::Arg arg1, Msg::Arg arg2, Msg::Arg arg3)
{
    std::unique_ptr<Msg> msg{new Msg{{}, type, {arg1, arg2, arg3}}};
    const auto buffer{boost::asio::buffer(msg.get(), sizeof *msg)};

    if (important) {
        msg->id = ++sent_msg_id_;
        sent_msgs_[msg->id] = *msg;
    }
    async_send(buffer, [this, msg{std::move(msg)}](...) { log_msg("<-", *msg); });
}

void Peer::send_game_id(const udp::endpoint& to, Msg::Arg game_id)
{
    std::unique_ptr<Msg> msg{new Msg{{}, Msg::JoinGame, {game_id, 0, 0}}};
    const auto buffer{boost::asio::buffer(msg.get(), sizeof *msg)};

    async_send_to(buffer, to, [this, msg{std::move(msg)}](...) { log_msg("<-", *msg); });
}


void Peer::listen(MsgReceivedHandler msg_received_handler)
{
    auto msg{std::make_unique<Msg>()};
    const auto buffer{boost::asio::buffer(msg.get(), sizeof *msg)};
    auto endpoint_ptr{std::make_unique<udp::endpoint>()};
    auto& endpoint{*endpoint_ptr};

    async_receive_from(buffer, endpoint,
        [this, handler{std::move(msg_received_handler)},
            msg{std::move(msg)}, endpoint{std::move(endpoint_ptr)}]
        (const boost::system::error_code& error, std::size_t size) {
            if (error == boost::asio::error::operation_aborted) {
                return;
            }
            log_msg("->", *msg);

            if (!error && size == sizeof *msg) {
                if (connected_ && msg->id != 0) {
                    while (++received_msg_id_ != msg->id) {
                        send_msg(true, Msg::Ping, received_msg_id_);
                    }
                }

                if (connected_ && msg->type == Msg::Ping) {
                    if (msg->args[0]) {
                        const auto [_, type, args]{sent_msgs_[msg->args[0]]};
                        send_msg(true, type, args[0], args[1], args[2]);
                    } else if (msg->id != 0) {
                        send_msg(false, Msg::Ping);
                    } else {
                        last_ping_ = clock::now();
                    }
                } else if (handler) {
                    handler(*endpoint, *msg);
                }
            }

            listen(std::move(handler));
        }
    );
}


void Peer::log_msg(std::string_view direction, const Msg& msg) const
{
    sync<std::clog> clog;

    try { clog << remote_endpoint(); } catch (...) { clog << "…"; }
    clog << ' ' << direction << ' ';
    try { clog << local_endpoint (); } catch (...) { clog << "…"; }
    clog << " : ";

    clog << int{msg.id} << ' ' << int{msg.type} << ' '
         << msg.args[0] << ' ' << msg.args[1] << ' ' << msg.args[2] << '\n';
}


} // namespace communication
