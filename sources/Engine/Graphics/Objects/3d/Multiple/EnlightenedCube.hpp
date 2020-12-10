/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Multiple/EnlightenedCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___

#include "../../../Shapes/3d/Multiple/UpdatedCube.hpp"



namespace engine::object3d::multiple {



class EnlightenedCube : public engine::shape3d::multiple::UpdatedCube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit EnlightenedCube(engine::Shader& shader);
    ~EnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void      setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
};



} // namespace engine::object3d::multiple



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_MULTIPLE_ENLIGHTENEDCUBE_HPP___
