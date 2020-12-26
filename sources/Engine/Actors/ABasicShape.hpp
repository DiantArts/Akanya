/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/BasicShape
** File description:
** BasicShape
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___

#include "AShape.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"



namespace engine::actor {



class BasicShape : public engine::actor::AShape {
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


private:
    size_t      m_NumberOfArrayToDraw;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;


public:
    // ---------------------------------------------------------------------------- Textures
    class Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(std::string_view filepath, engine::Shader& shader, const std::string& name, size_t textureIndex)
        ~Texture();


        // ------------------------------------------------ bind
        void bind() const;


    private:
        GLuint m_Id;
        GLenum m_Index;
    };

protected:
    void addTexture(std::string_view filepath, std::string_view name);

private:
    std::vector<BasicShape::Texture> m_TextureVector;
    size_t numberOfTextures { 0 };
};



} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_BASICSHAPE_HPP___
