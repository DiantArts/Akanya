/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/ABasicShape
** File description:
** Regroup every built-in shapes like Cube and Sphere
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___

#include "AShape.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"



namespace engine::actor {



class ABasicShape : public engine::actor::AShape {
public:
    // ---------------------------------------------------------------------------- *structors
    ABasicShape(engine::Shader&              shader,
                const std::function<void()>& setAttributes,
                std::string_view             verticesFilename,
                size_t                       numberOfPositions = 1,
                size_t                       numberOfTextures  = 1);
    virtual ~ABasicShape() = 0;


    // ---------------------------------------------------------------------------- Model
    virtual void drawModels(const engine::Camera& camera) const override;


private:
    size_t      m_NumberOfArrayToDraw;
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;


public:
    // ---------------------------------------------------------------------------- Textures
    class Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string&    filename,
                const engine::Shader& shader,
                const std::string&    name,
                size_t                textureIndex);
        ~Texture();


        // ------------------------------------------------ bind
        void bind() const;


    private:
        GLuint m_Id;
        GLenum m_Index;
    };
    void addTexture(std::string_view filepath, std::string_view name);

private:
    std::vector<ABasicShape::Texture> m_TextureVector;
    size_t                            numberOfTextures { 0 };
};



} // namespace engine::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_ABASICSHAPE_HPP___
