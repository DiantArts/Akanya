//
// Akanya, Engine
// sources/Game/Scenes/Example
// Simple example of a scene to test things
//

#include "pch.hpp"
#include "Example.hpp"

#include "Game/Objects/Floor.hpp"
#include "Game/Objects/Backpack.hpp"
#include "Game/Objects/EnlightenedCube.hpp"
#include "Game/Objects/LightSourceCube.hpp"
#include "Game/Entities/Player.hpp"


namespace {
constexpr auto precision {
    ::std::numeric_limits<::communication::Msg::Arg>::max()
        / ::game::scene::Example::world_size
};
}


// ---------------------------------- *structors

::game::scene::Example::Example(
    ::engine::graphic::Window& window
)
    : ::engine::graphic::AScene(window)
    , m_client {
        [] {
            ::communication::Msg::Arg game_id;
            ::std::cout << "Enter game id (0 to create new game): " << ::std::flush;
            ::std::cin >> ::std::hex >> game_id >> ::std::dec;
            return game_id;
        },
        [](const auto& stop_requested) {
            while (!stop_requested) {
                ::std::cout << "Loading..." << ::std::endl;
                ::std::this_thread::sleep_for(::std::chrono::seconds { 1 });
            }
        },
        [this](const auto& msg) {
            switch (msg.type) {
                case ::communication::Msg::Ping: break;
                case ::communication::Msg::JoinGame:
                    ::std::printf("Joined game #%04hX\n", msg.args[0]); break;
                case ::communication::Msg::MovePlayer:
                    m_mate_pos->get() = {
                        msg.args[0] / ::precision,
                        msg.args[1] / ::precision,
                        msg.args[2] / ::precision
                    };
            }
        }
    }
{
    auto& lightSource { this->emplaceActor<::game::object::LightSourceCube>(4) };
    lightSource.instances[0] = { -3.0F, 0.0F, 0.0F };
    lightSource.instances[1] = { -1.0F, 0.0F, 0.0F };
    lightSource.instances[2] = {  1.0F, 0.0F, 0.0F };
    lightSource.instances[3] = {  3.0F, 0.0F, 0.0F };

    this->emplaceActor<::game::object::Floor>();

    auto& player { this->emplacePlayer<::game::entity::Player>("multiEnlightened") };
    m_player_pos = player.instances[0] = { 1.0f, 0.0f, 4.0f };
    auto& mate { this->emplaceActor<::game::entity::Player>("multiEnlightened") };
    m_mate_pos = mate.instances[0] = { 1.0f, 0.0f, 4.0f };
}

::game::scene::Example::~Example() = default;



// ---------------------------------- Update

void ::game::scene::Example::update()
{
    AScene::update();

    const auto& player_pos { m_player_pos->get() };
    m_client->send_msg(false,
        ::communication::Msg::MovePlayer,
        player_pos.x * ::precision,
        player_pos.y * ::precision,
        player_pos.z * ::precision
    );
}
