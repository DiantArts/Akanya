//
// Akanya, Engine
// sources/Engine/Graphic/Actors/ABasicShape
// Regroup every built-in shapes like Cube and Sphere
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___

#include "Texture.hpp"



namespace engine::graphic::actor {



class ABasicShape : public engine::graphic::AActor {
public:
    // ---------------------------------- *structors
    ABasicShape(
        ::engine::graphic::opengl::Shader& shader,
        const std::function<void()>& setAttributesFunc,
        std::string_view verticesFilename,
        size_t numberOfPositions = 1,
        size_t numberOfTextures  = 1
    );
    virtual ~ABasicShape() = 0;


    // ---------------------------------- Model
    virtual void drawModels(const engine::graphic::Camera& camera) const override;


public:
    // ---------------------------------- Textures
    class Texture : public engine::graphic::actor::Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string& filename, bool gammaCorrection);
        ~Texture();
    };
    void addTexture(const std::string& filepath, const std::string& name, bool gammaCorrection = false);
    void bindTextures() const;

private:
    std::vector<ABasicShape::Texture> m_textureVector;
    std::vector<ABasicShape::Texture> m_textureGammaCorrectedVector;


private:
    size_t      m_numberOfArrayToDraw;
    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ABASICSHAPE_HPP___
