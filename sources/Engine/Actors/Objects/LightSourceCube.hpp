/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Single/LightSourceCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___

#include "../Lights/Default.hpp"
#include "../BasicShapes/Cube.hpp"



namespace engine::object {



class LightSourceCube
    : public engine::actor::basicShape::Cube
    , public engine::light::Default {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit LightSourceCube(engine::Shader& shaderProgram, size_t numberOfPositions = 1);
    ~LightSourceCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const override;
    void update(float deltaTime) override;
};



} // namespace engine::object



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___
