/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Basic
** File description:
** BasicShape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___

#include <string_view>

#include "../../Drawable.hpp"
#include "../../Transformable.hpp"



namespace engine::graphic::shape3d {



class Basic
    : public engine::graphic::Drawable
    , public engine::graphic::Transformable {
public:
    // ---------------------------------------------------------------------------- *structors
    Basic(engine::Shader&              shader,
          const std::function<void()>& setAttributes,
          const std::string_view       verticesFilename,
          const bool                   isMultiplePositionShape = false,
          const size_t                 numberOfTextures        = 1);
    virtual ~Basic() = 0;


    // ---------------------------------------------------------------------------- Override
    virtual void drawModels() const override;
    virtual void update(float deltaTime) override;
    virtual void transformShape(const engine::Camera& camera) const override;


    // ---------------------------------------------------------------------------- Virtuals
    virtual glm::mat4 getModel(const engine::graphic::Transformable& transformable,
                               const engine::graphic::position::Single& position) const;


private:
    size_t m_NumberOfArrayToDraw;
};



} // namespace engine::graphic::shape3d



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___
