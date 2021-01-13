/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ABasicShape
** File description:
** Regroup every built-in shapes like Cube and Sphere
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___

#include "AActor.hpp"
#include "Texture.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"



namespace engine::actor {



class ABasicShape : public engine::AActor {
public:
    // ---------------------------------------------------------------------------- *structors
    ABasicShape(engine::Shader&              shader,
                const std::function<void()>& setAttributesFunc,
                std::string_view             verticesFilename,
                size_t                       numberOfPositions = 1,
                size_t                       numberOfTextures  = 1);
    virtual ~ABasicShape() = 0;


    // ---------------------------------------------------------------------------- Model
    virtual void drawModels(const engine::Camera& camera) const override;


public:
    // ---------------------------------------------------------------------------- Textures
    class Texture : public engine::actor::Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string& filename, bool gammaCorrection);
        ~Texture();
    };
    void addTexture(const std::string& filepath, const std::string& name, bool gammaCorrection = false);
    void bindTextures() const;

private:
    std::vector<ABasicShape::Texture> m_TextureVector;
    std::vector<ABasicShape::Texture> m_TextureGammaCorrectedVector;


private:
    size_t      m_NumberOfArrayToDraw;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
};



} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___
