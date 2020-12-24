/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Cube
** File description:
** BasicCube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___

#include "../../Shapes/3d/Basic.hpp"



namespace engine::graphic::shape3d {



class Cube : public engine::graphic::shape3d::Basic {
public:
    // ---------------------------------------------------------------------------- *structors
    Cube(engine::Shader&              shader,
         bool                   isMultiplePositionShape = false,
         const std::function<void()>& setAttributes           = Cube::setAttributes,
         std::string_view       verticesFilename        = "cube",
         size_t                 numberOfTextures        = 1);
    virtual ~Cube();


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::graphic::shape3d



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_CUBE_HPP___
