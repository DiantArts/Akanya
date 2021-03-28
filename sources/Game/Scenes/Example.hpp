//
// Akanya, Engine
// sources/Game/Scenes/Example
// Simple example of a scene to test things
//

#ifndef ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___

#include "Engine/Graphic/AScene.hpp"
#include "Engine/Graphic/Actors/Model.hpp"

#include "Game/Objects/Floor.hpp"

#include "Communication/Client.hpp"


namespace game::scene {



class Example
    : public engine::graphic::AScene
{

public:

    // ---------------------------------- *structors

    Example(
        ::engine::graphic::Window& window
    );

    ~Example();



    // ---------------------------------- Copy sementic

    Example(
        const Example&
    ) noexcept;

    auto operator=(
        const Example&
    ) noexcept -> Example&;



    // ---------------------------------- Move sementic

    Example(
        Example&&
    ) noexcept;

    auto operator=(
        Example&&
    ) noexcept -> Example&;



    // ---------------------------------- Update

    void update() override;



public:
    static constexpr auto world_size { 20. };



protected:
protected:
private:
private:
    ::OptionalReferenceWrapper<const ::glm::vec3> m_player_pos;
    ::OptionalReferenceWrapper<::glm::vec3> m_mate_pos;
    ::communication::Client m_client;
};



} // namespace game::scene

#endif // ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___
