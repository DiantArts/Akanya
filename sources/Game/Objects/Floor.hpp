//
// Akanya, Engine
// sources/Game/Objects/Floor
// Just a floor lol
//

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___

#include "Engine/Graphic/Actors/BasicShapes/Cube.hpp"



namespace game::object {



class Floor
    : public engine::graphic::actor::basicShape::Cube
{

public:

    // ---------------------------------- *structors

    explicit Floor(
        size_t numberOfPositions = 1,
        const std::string& shaderFilepath = "floor",
        const std::function<void()>& setAttributesFunc = []{
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);
        },
        const std::string& verticesFilename  = "floor"
    );

    ~Floor();



    // ---------------------------------- Copy sementic

    Floor(
        const Floor&
    ) noexcept = delete;

    auto operator=(
        const Floor&
    ) noexcept -> Floor& = delete;



    // ---------------------------------- Move sementic

    Floor(
        Floor&&
    ) noexcept = delete;

    auto operator=(
        Floor&&
    ) noexcept -> Floor& = delete;



    // ---------------------------------- override

    void configureShader() const override final;



public:
protected:
protected:
private:
private:

};



} // namespace game::object



#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_FLOOR_HPP___
