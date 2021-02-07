//
// Akanya, Engine
// sources/Engine/Graphic/Actors/BasicShapes/Cube
// this is a default built-in cube
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_BASICSHAPES_CUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_BASICSHAPES_CUBE_HPP___

#include "../ABasicShape.hpp"



namespace engine::graphic::actor::basicShape {



class Cube
    : public engine::graphic::actor::ABasicShape
{

public:

    // ---------------------------------- *structors
    Cube(
        ::engine::graphic::opengl::Shader& shader,
        size_t numberOfPositions = 1,
        size_t numberOfTextures  = 1,
        const std::function<void()>& setAttributesFunc = []{
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
        },
        const std::string& verticesFilename = "cube");

    virtual ~Cube();


public:
protected:
protected:
private:
private:

};



} // namespace engine::graphic::actor::basicShape



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_BASICSHAPES_CUBE_HPP___
