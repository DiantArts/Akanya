//
// Akanya, Engine
// sources/Objects/LightSourceCube
// A lamp ?
//

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"
#include "Engine/Graphic/Lights/Directional.hpp"
#include "Engine/Graphic/Lights/Point.hpp"
#include "Engine/Graphic/Lights/Spot.hpp"



namespace game::object {



class LightSourceCube
    : public engine::graphic::actor::basicShape::Cube
    , public engine::graphic::light::Point
{

public:

    // ---------------------------------- *structors

    explicit LightSourceCube(
        std::vector<std::reference_wrapper<::engine::graphic::ALight>>& lights,
        size_t numberOfPositions = 1,
        const std::string& shaderFilepath = "lightSource"
    );

    ~LightSourceCube();



    // ---------------------------------- Copy sementic

    LightSourceCube(
        const LightSourceCube&
    ) noexcept;

    auto operator=(
        const LightSourceCube&
    ) noexcept -> LightSourceCube&;



    // ---------------------------------- Move sementic

    LightSourceCube(
        LightSourceCube&&
    ) noexcept;

    auto operator=(
        LightSourceCube&&
    ) noexcept -> LightSourceCube&;



    // ---------------------------------- override

    void configureShader() const override;

    void update(float deltaTime) override;



public:
protected:
protected:
private:
private:

};



} // namespace game::object

#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_LIGHTSOURCECUBE_HPP___
