/*
** EPITECH PROJECT, 2020
** sources/Objects/Backpack
** File description:
** basic model backpack
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___

#include "Engine/Actors/Model.hpp"



namespace game::object {



class Backpack : public engine::actor::Model {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Backpack(engine::Shader& shader, const size_t numberOfPositions);
    ~Backpack();


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
};



} // namespace game::object

#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
