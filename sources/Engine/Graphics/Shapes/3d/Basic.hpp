/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Basic
** File description:
** BasicShape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___

#include "../../Drawable.hpp"
#include "../../Transformable.hpp"

#include "../../Vertexes/Vao.hpp"
#include "../../Vertexes/Vbo.hpp"

#include "../../../Container/Vector/Texture.hpp"



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


    // ---------------------------------------------------------------------------- Model
    void drawModels(const engine::Camera&) const override final;
    virtual glm::mat4 getModel(const engine::graphic::position::Single& position) const;


    // ---------------------------------------------------------------------------- Textures
    void addTexture(const std::string_view filepath, const std::string_view name, const int index);
    const engine::container::vector::Texture& getTextures() const;


private:
    size_t m_NumberOfArrayToDraw;
    engine::container::vector::Texture             m_TextureVector; // TODO: std::optional + Material class
                                                                    // if numberOfTexture == 0
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
};



} // namespace engine::graphic::shape3d



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_BASIC_HPP___
