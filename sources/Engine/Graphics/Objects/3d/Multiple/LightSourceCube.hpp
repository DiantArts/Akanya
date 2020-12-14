/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Multiple/LightSourceCube
** File description:
** LightsourceCube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_LIGHTSOURCECUBE_HPP___



#include "../../../Light/Dynamic/Default.hpp"
#include "../../../Shapes/3d/Cube.hpp"



namespace engine::object3d::multiple {



class LightSourceCube
    : public engine::graphic::shape3d::Cube
    , public engine::light::dynamic::Default {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit LightSourceCube(engine::Shader& shaderProgram);
    ~LightSourceCube() = default;


    // ---------------------------------------------------------------------------- override
    void transformShape(const engine::Camera& camera) const final;
    void update(float deltaTime) override;
};



} // namespace engine::object3d::multiple



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_LIGHTSOURCECUBE_HPP___
