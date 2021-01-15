/*
** EPITECH PROJECT, 2020
** sources/Scenes/Example
** File description:
** Simple example of a scene, mainly to test things
*/

#ifndef ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___

#include "Engine/AScene.hpp"
#include "Engine/Actors/Model.hpp"




namespace game::scene {



class Example : public engine::AScene {
public:
    // ---------------------------------------------------------------------------- *structors
    Example();
    ~Example();

private:
};



} // namespace game::scene

#endif // ___INCLUDE_GUARD_SOURCES_SCENES_EXAMPLE_HPP___
