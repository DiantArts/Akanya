/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Objects/3d/Single/LightSourceCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___

#include "../../../Light/Dynamic/Default.hpp"
#include "../../../Shapes/3d/Single/UpdatedCube.hpp"



namespace engine::object3d::single {



class LightSourceCube
    : public engine::shape3d::single::UpdatedCube
    , public engine::light::dynamic::Default {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit LightSourceCube(engine::Shader& shaderProgram, const glm::vec3& position = glm::vec3(0, 0, 0));
    ~LightSourceCube() = default;


    // ---------------------------------------------------------------------------- override
    void      setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
};



} // namespace engine::object3d::single



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_OBJECTS_3D_SINGLE_LIGHTSOURCECUBE_HPP___
