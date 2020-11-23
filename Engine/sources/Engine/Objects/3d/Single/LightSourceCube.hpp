/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#pragma once



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
