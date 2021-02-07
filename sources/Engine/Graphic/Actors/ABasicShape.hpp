//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ABasicShape
// Regroup every built-in shapes like Cube and Sphere
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___

#include "Texture.hpp"



namespace engine::graphic::actor {



class ABasicShape
    : public engine::graphic::AActor
{

public:

    // ---------------------------------- *structors

    ABasicShape(
        ::engine::graphic::opengl::Shader& shader,
        const std::function<void()>& setAttributesFunc,
        const std::string& verticesFilename,
        size_t numberOfPositions = 1,
        size_t numberOfTextures  = 1
    );

    virtual ~ABasicShape() = 0;



    // ---------------------------------- Copy sementic

    ABasicShape(
        const ABasicShape&
    ) noexcept = delete;

    auto operator=(
        const ABasicShape&
    ) noexcept -> ABasicShape& = delete;



    // ---------------------------------- Move sementic

    ABasicShape(
        ABasicShape&&
    ) noexcept = delete;

    auto operator=(
        ABasicShape&&
    ) noexcept -> ABasicShape& = delete;



    // ---------------------------------- ADrawable

    virtual void drawModels() const override;


public:

    class Texture :
        public engine::graphic::actor::Texture
    {

    public:

        // ------------------------------------------------ *structors
        Texture(const std::string& filename, bool gammaCorrection);
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



    public:
    protected:
    protected:
    private:
    private:

    };



    // ---------------------------------- Texture

    void addTexture(const std::string& filepath, const std::string& name, bool gammaCorrection = false);

    void bindTextures() const;



protected:
protected:

private:

    std::vector<ABasicShape::Texture> m_textureVector;
    std::vector<ABasicShape::Texture> m_textureGammaCorrectedVector;

    size_t      m_numberOfArrayToDraw;
    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___
