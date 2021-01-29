//
// Akanya, Engine
// sources/Objects/EnlightenedCube
// An enlightened cube lol
//

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class EnlightenedCube
    : public ::engine::graphic::actor::basicShape::Cube
{
public:
    // ---------------------------------- *structors
    explicit EnlightenedCube(
        ::engine::graphic::opengl::Shader& shader,
        size_t numberOfPositions = 1,
        const std::function<void()>& setAttributesFunc = []{
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);
        },
        const std::string_view verticesFilename  = "lightningMap"
    );


    ~EnlightenedCube();



    // ---------------------------------- override

    void configureShader(
        const ::engine::graphic::Window& window,
        const ::engine::graphic::Camera& camera
    ) const override;



public:
protected:
protected:
private:
private:

};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_ENLIGHTENEDCUBE_HPP___
