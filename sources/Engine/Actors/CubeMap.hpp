/*
** EPITECH PROJECT, 2020
** sources/Engine/CubeMap
** File description:
** allow sky or things like that
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___

#include <string_view>

#include "AActor.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"
#include "Texture.hpp"



namespace engine::actor {



class CubeMap : public engine::actor::AActor {
public:
    // ---------------------------------------------------------------------------- *structors
    CubeMap(engine::Shader&              shader,
            const std::function<void()>& setAttributesFunc = CubeMap::setAttributes,
            const std::string_view       verticesFilename  = "cubeMap",
            const std::string_view       textureDirectory  = "cubeMap");
    ~CubeMap();


    // ---------------------------------------------------------------------------- Drawable
    void draw(const engine::Camera& camera) const override;
    void drawModels(const engine::Camera& camera) const override;
    void configureShader(const engine::Camera& camera) const override;


    // ---------------------------------------------------------------------------- defaultAttributes
    static void setAttributes();


public:
    // ---------------------------------------------------------------------------- Textures
    class Texture : public engine::actor::Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string& configFilepath);
        ~Texture();

        // ------------------------------------------------ bind
        void bind() const;
    };

private:
    CubeMap::Texture m_Texture;
    size_t           m_NumberOfArrayToDraw;
    engine::Vao      m_Vao;
    engine::Vbo      m_Vbo;
};



} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___
