/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Client.cpp
*/

#include "Communication/Client.hpp"
#include <thread>

namespace communication {


Client::Client(GameIdGetter game_id_getter,
               GameLoadingHandler game_loading_handler,
               MsgReceivedHandler msg_received_handler)
  : peer_{context_, udp::v6()}
  , sender_thread_{
      [this] {
          while (!context_.stopped()) {
              context_.run_for(std::chrono::seconds{1});

              if (peer_) {
                  peer_.send_msg(true, Msg::Ping);
              } else if (game_id_.valid()) {
                  peer_.send_game_id({server_address, 8765}, game_id_.get());
              }
          }
      }
    }
  , game_id_getter_{std::move(game_id_getter)}
  , game_loading_handler_{std::move(game_loading_handler)}
{
    peer_.listen(
        [this, handler{std::move(msg_received_handler)}]
        (const udp::endpoint& from, const Msg& msg) {
            if (!peer_) {
                peer_.connect(from);
            }
            if (handler) {
                handler(msg);
            }
        }
    );
}


Peer* Client::operator->()
{
    while (!peer_) {
        game_id_getter_.reset();
        game_id_ = game_id_getter_.get_future();
        game_id_getter_();

        game_loading_handler_(
            [this, start{Peer::clock::now()}] {
                return peer_ ||
                    Peer::clock::now() - start > std::chrono::seconds{5};
            }
        );
    }
    return &peer_;
}


} // namespace communication
