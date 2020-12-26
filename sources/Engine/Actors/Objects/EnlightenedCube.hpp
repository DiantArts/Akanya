/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Multiple/EnlightenedCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___

#include "../BasicShapes/Cube.hpp"



namespace engine::object {



class EnlightenedCube : public engine::actor::basicShape::Cube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit EnlightenedCube(engine::Shader& shader, size_t numberOfPositions = 1);
    ~EnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void configureShader(const engine::Camera& camera) const final;


private:
    // ---------------------------------------------------------------------------- Attributes
    static void setAttributes();
};



} // namespace engine::object



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
