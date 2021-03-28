/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Peer.hpp
*/

#ifndef INCLUDED_COM_PEER_HPP
#define INCLUDED_COM_PEER_HPP

#include <boost/asio.hpp>

namespace communication {


template<std::ostream& ostream>
struct sync : std::ostringstream
{ ~sync() { ostream << str(); } };


struct Msg {

public:
    struct Id {
        constexpr operator uint8_t() const noexcept { return v_; }
        constexpr static uint8_t max{std::numeric_limits<uint8_t>::max()};
        constexpr Id& operator++() noexcept { return ++v_ || ++v_, *this; }
    private:
        uint8_t v_{0};
    };

public:
    enum Type : uint8_t {
        Ping,
        JoinGame,
        MovePlayer
    };

public:
    using Arg = uint16_t;

public:
    Id id;
    Type type;
    Arg args[3];
};


using boost::asio::ip::udp;

class Peer : private udp::socket {

public:
    using MsgReceivedHandler =
        std::function<void(const udp::endpoint& from, Msg&)>;
    using clock = std::chrono::steady_clock;

public:
    template<typename... SocketArgs>
    Peer(SocketArgs&&... socket_args)
      : udp::socket{std::forward<SocketArgs>(socket_args)...} {}

public:
    operator bool() noexcept;
    void connect(const udp::endpoint& to);
    void listen(MsgReceivedHandler);

    void send_msg(bool important, Msg::Type,
        Msg::Arg = 0, Msg::Arg = 0, Msg::Arg = 0);
    void send_game_id(const udp::endpoint& to, Msg::Arg game_id = 0);

private:
    void log_msg(std::string_view direction, const Msg&) const;

private:
    bool connected_{false};
    std::array<Msg, Msg::Id::max> sent_msgs_;
    Msg::Id sent_msg_id_, received_msg_id_;
    clock::time_point last_ping_;
};


} // namespace communication

#endif // INCLUDED_COM_PEER_HPP
