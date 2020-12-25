/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Multiple/EnlightenedCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___

#include "../../../Shapes/3d/Cube.hpp"



namespace engine::object3d::multiple {



class EnlightenedCube : public engine::graphic::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit EnlightenedCube(engine::Shader& shader);
    ~EnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void transformShape(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::object3d::multiple



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
