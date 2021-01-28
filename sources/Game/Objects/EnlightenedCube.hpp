/*
** Akanya, Engine
** sources/Objects/EnlightenedCube
** An enlightened cube lol
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class EnlightenedCube
    : public engine::graphic::actor::basicShape::Cube
{
public:
    // ---------------------------------- *structors
    explicit EnlightenedCube(
        ::engine::graphic::opengl::Shader& shader,
        size_t numberOfPositions = 1
    );

    ~EnlightenedCube();



    // ---------------------------------- override

    void configureShader(
        const engine::graphic::Window& window
    ) const override;



public:
protected:
protected:
private:
private:

    // ---------------------------------- Attributes
    static void setAttributes();

};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
