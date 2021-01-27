/*
** Akanya, Engine
** sources/Objects/ShadowCube
** Trying to implement shadows, just a trial
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_SHADOWCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_SHADOWCUBE_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class ShadowCube : public engine::graphic::actor::basicShape::Cube {
public:
    // ---------------------------------- *structors
    explicit ShadowCube(::engine::graphic::opengl::Shader& shader, size_t numberOfPositions = 1);
    ~ShadowCube() = default;


    // ---------------------------------- override
    void configureShader(const engine::graphic::Camera& camera) const final;


private:
    // ---------------------------------- Attributes
    static void setAttributes();
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_SHADOWCUBE_HPP___
