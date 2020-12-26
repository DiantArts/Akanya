/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/Cube
** File description:
** BasicCube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___

#include "../ABasicShape.hpp"



namespace engine::actor::basicShape {



class Cube : public engine::actor::ABasicShape {
public:
    // ---------------------------------------------------------------------------- *structors
    Cube(engine::Shader&              shader,
         size_t                       numberOfPositions = 1,
         size_t                       numberOfTextures = 1,
         const std::function<void()>& setAttributesFunc = Cube::setAttributes,
         const std::string_view       verticesFilename = "cube");
    virtual ~Cube();


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::actor::basicShape



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___
