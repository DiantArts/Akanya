/*
** Akanya, Engine
** sources/Objects/Floor
** Just a floor lol
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class Floor : public engine::graphic::actor::basicShape::Cube {
public:
    // ---------------------------------- *structors
    explicit Floor(
        ::engine::graphic::opengl::Shader& shader,
        size_t numberOfPositions = 1
    );
    ~Floor() = default;


    // ---------------------------------- override
    void configureShader(
        const engine::graphic::Camera& camera
    ) const final;


private:
    // ---------------------------------- Attributes
    static void setAttributes();
};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
