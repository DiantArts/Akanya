/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#pragma once



#include "Drawable.hpp"



namespace engine::shape3d::single {



class Cube : public engine::shape3d::single::Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Cube(
        engine::Shader&              shaderProgram,
        const glm::vec3&             position         = glm::vec3(0, 0, 0),
        const std::string_view       verticesFileName = "updateCube",
        const std::function<void()>& attributesSetter =
            [] {
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                                      (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
            },
        const size_t numberOfTextures = 1);
    ~Cube() = default;


    // ---------------------------------------------------------------------------- override
    void      setAllIntoShader(const engine::Camera& camera) override;
    glm::mat4 getModel(const glm::vec3& position) override;
    size_t    getNumberOfArrayToDraw() override;


public:
    constexpr static size_t numberOfArrayToDraw { 36 };
};



} // namespace engine::shape3d::single
