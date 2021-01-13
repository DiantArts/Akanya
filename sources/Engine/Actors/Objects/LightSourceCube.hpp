/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Objects/LightSourceCube
** File description:
** Lamp as cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_LIGHTSOURCECUBE_HPP___

#include "../BasicShapes/Cube.hpp"
#include "../Lights/ALight.hpp"



namespace engine::actor::object {



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



} // namespace engine::actor::object



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_OBJECTS_LIGHTSOURCECUBE_HPP___
