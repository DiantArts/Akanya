/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Single/UpdatedCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_UPDATEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_UPDATEDCUBE_HPP___

#include "Drawable.hpp"



namespace engine::shape3d::single {



class UpdatedCube : public engine::shape3d::single::Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit UpdatedCube(
        engine::Shader&              shaderProgram,
        const glm::vec3&             position         = glm::vec3(0, 0, 0),
        const std::string_view       verticesFileName = "updatedCube",
        const std::function<void()>& attributesSetter =
            [] {
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                                      (void*)(3 * sizeof(float)));
                glEnableVertexAttribArray(1);
            },
        const size_t numberOfTextures = 1);
    virtual ~UpdatedCube() = default;


    // ---------------------------------------------------------------------------- final
    size_t getNumberOfArrayToDraw() override final;


    // ---------------------------------------------------------------------------- virtuals
    virtual void      setAllIntoShader(const engine::Camera& camera) override;
    virtual glm::mat4 getModel(const glm::vec3& position) override;

protected:
    constexpr static size_t numberOfArrayToDraw { 36 };
};



} // namespace engine::shape3d::single



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_UPDATEDCUBE_HPP___
