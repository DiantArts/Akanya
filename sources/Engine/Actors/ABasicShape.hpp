/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/BasicShape
** File description:
** BasicShape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___

#include "../../../Container/Vector/Texture.hpp"
#include "../../Drawable.hpp"
#include "../../Transformable.hpp"
#include "../../Vertexes/Vao.hpp"
#include "../../Vertexes/Vbo.hpp"



namespace engine::graphic {



class BasicShape : public engine::graphic::Shape {
public:
    // ---------------------------------------------------------------------------- *structors
    BasicShape(engine::Shader&              shader,
               const std::function<void()>& setAttributes,
               std::string_view             verticesFilename,
               size_t                       numberOfPositions = 1,
               size_t                       numberOfTextures  = 1);
    virtual ~BasicShape() = 0;


    // ---------------------------------------------------------------------------- Model
    virtual update() void drawModels(const engine::Camera& camera) const override final;


protected:
    // ---------------------------------------------------------------------------- Textures
    void addTexture(std::string_view filepath, std::string_view name, int index);
    const engine::container::vector::Texture& getTextures() const;


private:
    size_t                             m_NumberOfArrayToDraw;
    engine::container::vector::Texture m_TextureVector; // TODO: std::optional + Material class
                                                        // if numberOfTexture == 0
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
};



} // namespace engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___
