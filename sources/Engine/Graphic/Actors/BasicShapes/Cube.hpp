/*
** Akanya, Engine
** sources/Engine/Actors/BasicShapes/Cube
** this is a default built-in cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_BASICSHAPES_CUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_BASICSHAPES_CUBE_HPP___

#include "../ABasicShape.hpp"



namespace engine::graphic::actor::basicShape {



class Cube : public engine::graphic::actor::ABasicShape {
public:
    // ---------------------------------- *structors
    Cube(::engine::graphic::opengl::Shader&              shader,
         size_t                       numberOfPositions = 1,
         size_t                       numberOfTextures  = 1,
         const std::function<void()>& setAttributesFunc = Cube::setAttributes,
         const std::string_view       verticesFilename  = "cube");
    virtual ~Cube();


private:
    // ---------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::graphic::actor::basicShape



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_BASICSHAPES_CUBE_HPP___
