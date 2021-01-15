/*
** EPITECH PROJECT, 2020
** sources/Objects/LightSourceCube
** File description:
** A lamp ?
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___

#include "Engine/Actors/BasicShapes/Cube.hpp"
#include "Engine/Actors/Lights/ALight.hpp"



namespace game::object {



class LightSourceCube
    : public engine::actor::basicShape::Cube
    , public engine::actor::ALight {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit LightSourceCube(engine::Shader& shaderProgram, size_t numberOfPositions = 1);
    ~LightSourceCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const override;
    void update(float deltaTime) override;
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
