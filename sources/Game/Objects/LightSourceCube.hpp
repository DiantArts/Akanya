/*
** Akanya, Engine
** sources/Objects/LightSourceCube
** A lamp ?
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"
#include "Engine/Graphic/Actors/Lights/Point.hpp"
#include "Engine/Graphic/Actors/Lights/Spot.hpp"



namespace game::object {



class LightSourceCube
    : public engine::graphic::actor::basicShape::Cube
    , public engine::graphic::actor::light::Point {
public:
    // ---------------------------------- *structors
    explicit LightSourceCube(::engine::graphic::opengl::Shader& shaderProgram, size_t numberOfPositions = 1);
    ~LightSourceCube() = default;


    // ---------------------------------- override
    void configureShader(const engine::graphic::Camera& camera) const override;
    void update(float deltaTime) override;
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
