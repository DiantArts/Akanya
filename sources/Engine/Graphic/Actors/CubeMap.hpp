/*
** Akanya, Engine
** sources/Engine/CubeMap
** allow sky or things like that
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___

#include "AActor.hpp"
#include "../OpenGL/Vao.hpp"
#include "../OpenGL/Vbo.hpp"
#include "Texture.hpp"



namespace engine::graphic::actor {



class CubeMap : public engine::graphic::AActor {
public:
    // ---------------------------------- *structors
    CubeMap(::engine::graphic::opengl::Shader&              shader,
            const std::function<void()>& setAttributesFunc = CubeMap::setAttributes,
            const std::string_view       verticesFilename  = "cubeMap",
            const std::string_view       textureDirectory  = "cubeMap");
    ~CubeMap();


    // ---------------------------------- Drawable
    void draw(const engine::graphic::Camera& camera) const override;
    void drawModels(const engine::graphic::Camera& camera) const override;
    void configureShader(const engine::graphic::Camera& camera) const override;


    // ---------------------------------- defaultAttributes
    static void setAttributes();


public:
    // ---------------------------------- Textures
    class Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string& configFilepath);
        ~Texture();

        // ------------------------------------------------ bind
        void bind() const;
        GLuint get();

    private:
        std::shared_ptr<GLuint> m_id;
    };

private:
    CubeMap::Texture m_texture;
    size_t           m_numberOfArrayToDraw;
    ::engine::graphic::opengl::Vao      m_vao;
    ::engine::graphic::opengl::Vbo      m_vbo;
};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CUBEMAP_HPP___
