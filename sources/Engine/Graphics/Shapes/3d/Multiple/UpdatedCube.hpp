/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Multiple/UpdatedCube
** File description:
** Light source as a cube
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_UPDATEDCUBE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_UPDATEDCUBE_HPP___

#include "Drawable.hpp"



namespace engine::shape3d::multiple {



class UpdatedCube : public engine::shape3d::multiple::Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit UpdatedCube(
        engine::Shader&              shader,
        const std::string_view       verticesFileName = "updateCube",
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
    virtual size_t getNumberOfArrayToDraw() override final;


    // ---------------------------------------------------------------------------- virtuals
    virtual void      setAllIntoShader(const engine::Camera& camera) override;
    virtual glm::mat4 getModel(const glm::vec3& position) override;


protected:
    constexpr static size_t m_NumberOfArrayToDraw { 36 };
};



} // namespace engine::shape3d::multiple



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_UPDATEDCUBE_HPP___
