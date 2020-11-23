/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#pragma once



#include "../../../Shapes/3d/Multiple/UpdatedCube.hpp"



namespace engine::object3d::multiple {



class EnlightenedCube : public engine::shape3d::multiple::UpdatedCube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit EnlightenedCube(engine::Shader& shader);
    ~EnlightenedCube() = default;


    // ---------------------------------------------------------------------------- override
    void setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
};



} // namespace engine::object3d::multiple
