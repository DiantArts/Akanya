/*
** Akanya, Engine
** sources/Game/Scenes/Example
** Simple example of a scene to test things
*/

#ifndef ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___

#include "Engine/Graphic/AScene.hpp"
#include "Engine/Graphic/Actors/Model.hpp"


#include "Game/Objects/Floor.hpp"


namespace game::scene {



class Example : public engine::graphic::AScene {
public:
    // ---------------------------------- *structors
    Example();
    ~Example();

private:
};



} // namespace game::scene

#endif // ___INCLUDE_GUARD_SOURCES_GAME_SCENES_EXAMPLE_HPP___
