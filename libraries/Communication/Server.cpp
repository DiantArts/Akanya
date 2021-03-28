/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-evan.loiseau
** File description:
** Communication/Server.cpp
*/

#include "Communication/Server.hpp"
#include <iostream>

namespace communication {


Dispatcher::Dispatcher(Peer::MsgReceivedHandler& msg_received_handler,
                       DisconnectedHandler& disconnected_handler)
  : msg_received_handler_{
      [&](const udp::endpoint& from, Msg& msg) {
          if (msg_received_handler) {
              msg_received_handler(from, msg);
          }
          for (auto& [endpoint, player] : players_) {
              if (endpoint != from) {
                player.send_msg(msg.id != 0, msg.type,
                    msg.args[0], msg.args[1], msg.args[2]);
              }
          }
      }
    }
  , disconnected_handler_{disconnected_handler} {}


bool Dispatcher::add_peer(const udp::endpoint& endpoint, Msg::Arg game_id)
{
    if (players_.size() == 2) {
        return false;
    }

    Peer& player{players_.emplace_front(endpoint, context_).second};
    player.listen(msg_received_handler_);
    player.connect(endpoint);
    player.send_msg(true, Msg::JoinGame, game_id);
    return true;
}

void Dispatcher::run()
{
    while (!players_.empty()) {
        context_.run_for(std::chrono::seconds{1});

        players_.remove_if(
            [this](auto& player) {
                if (Peer& peer{player.second}) {
                    peer.send_msg(true, Msg::Ping);
                    return false;

                } else if (disconnected_handler_) {
                    disconnected_handler_();
                }
                return true;
            }
        );
    }
}


Server::Server(Peer::MsgReceivedHandler msg_received_handler,
               Dispatcher::DisconnectedHandler disconnected_handler)
  : peer_{context_, udp::endpoint{udp::v6(), 8765}}
  , msg_received_handler_{std::move(msg_received_handler)}
  , disconnected_handler_{std::move(disconnected_handler)}
{
    peer_.listen(
        [this](const udp::endpoint& from, const Msg& msg) {
            std::thread{&Server::join_game, this, from, msg}.detach();
        }
    );
    context_.run();
}


void Server::join_game(udp::endpoint from, Msg msg)
{
    if (msg.type != Msg::JoinGame) {
        sync<std::cerr>{} << "Unknown request " << int{msg.type} << '\n';
        return;
    }

    std::unique_lock lock{games_mutex_};

    if (const auto game_id{msg.args[0]}) {
        const auto game{games_.find(game_id)};

        if (game == games_.cend()) {
            sync<std::cerr>{} << "Error: No game with id #"
                              << std::hex << game_id << std::dec << '\n';
        } else if (!game->second.add_peer(from, game_id)) {
            sync<std::cerr>{} << "Error: Already 2 players in game #"
                              << std::hex << game_id << std::dec << '\n';
        }
    } else if (games_.size() == game_id_gen_.max()) {
        sync<std::cerr>{} << "No free game id available" << '\n';
    } else for (;;) {

        const auto [game, is_id_available]
            {games_.try_emplace(game_id_gen_(random_engine_),
                msg_received_handler_, disconnected_handler_)};

        if (is_id_available) {
            game->second.add_peer(from, game->first);
            lock.unlock();
            game->second.run();
            games_.erase(game);
            return;
        }
    }
}


} // namespace communication
