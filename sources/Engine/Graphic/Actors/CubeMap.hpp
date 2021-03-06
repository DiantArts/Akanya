//
// Akanya, Engine
// sources/Engine/Graphic/Actor/CubeMap
// allow sky or things like that
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTOR_CUBEMAP_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTOR_CUBEMAP_HPP___

#include "Texture.hpp"



namespace engine::graphic::actor {



class CubeMap
    : public engine::graphic::AActor
{

public:
    // ---------------------------------- *structors
    CubeMap(
        const std::string& shaderFilepath,
        const std::function<void()>& setAttributesFunc = []{
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        },
        const std::string& verticesFilename  = "cubeMap",
        const std::string& textureDirectory  = "cubeMap"
    );

    ~CubeMap();



    // ---------------------------------- Copy sementic

    CubeMap(
        const CubeMap&
    ) noexcept;

    auto operator=(
        const CubeMap&
    ) noexcept -> CubeMap&;



    // ---------------------------------- Move sementic

    CubeMap(
        CubeMap&&
    ) noexcept;

    auto operator=(
        CubeMap&&
    ) noexcept -> CubeMap&;



    // ---------------------------------- Drawable
    void draw() const override;

    void drawModels() const override;



public:
protected:
protected:
private:
private:

    class Texture {

    public:

        // ---------------------------------- *structors

        Texture(const std::string& configFilepath);
        ~Texture();



        // ---------------------------------- Copy sementic

        Texture(
            const Texture&
        ) noexcept;

        auto operator=(
            const Texture&
        ) noexcept -> Texture&;



        // ---------------------------------- Move sementic

        Texture(
            Texture&&
        ) noexcept;

        auto operator=(
            Texture&&
        ) noexcept -> Texture&;


        // ---------------------------------- bind
        void bind() const;
        GLuint get();



    public:
    protected:
    protected:
    private:
    private:
        std::shared_ptr<GLuint> m_id;

    };
    CubeMap::Texture m_texture;

    size_t m_numberOfArrayToDraw;
    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;

};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTOR_CUBEMAP_HPP___
