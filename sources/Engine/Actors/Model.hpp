/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Model
** File description:
** This class loads models from .objs (at least and for the moment)
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___

#include <string_view>

#include <assimp/Importer.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "AActor.hpp"
#include "Texture.hpp"
#include "Vertexes/Ebo.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"



namespace engine::actor {



class Model : public engine::actor::AActor {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Model(engine::Shader&    shader,
                   const std::string& filename,
                   size_t             numberOfPositions = 1,
                   bool               gamma             = false);
    ~Model();


    // ---------------------------------------------------------------------------- Overrides
    virtual void update(float deltaTime) override;
    virtual void drawModels(const engine::Camera& camera) const override;

private:
    // ---------------------------------------------------------------------------- Texture
    class Texture : public engine::actor::Texture {
    public:
        // ------------------------------------------------ *structors
        Texture(const std::string& filename,
                const std::string& directoryName,
                std::string_view   type,
                size_t             i);
        ~Texture();

        const std::string& getName() const;

    private:
        std::string m_Name;
    };


    // ---------------------------------------------------------------------------- Vertex
    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords { 0.0F };
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
    };


    // ---------------------------------------------------------------------------- Mesh
    class Mesh {
    public:
        // ---------------------------------------------------------- *structors
        explicit Mesh(const engine::Shader&         shader,
                      std::vector<Model::Vertex>&&  vertices,
                      std::vector<GLuint>&&         indices,
                      std::vector<Model::Texture>&& textures);
        ~Mesh();

        // ---------------------------------------------------------- Draw
        void         draw() const;
        virtual void update(float deltaTime);

    private:
        const engine::Shader& m_Shader;

        engine::Vao m_Vao;
        engine::Vbo m_Vbo;
        engine::Ebo m_Ebo;

        std::vector<Model::Vertex>  m_Vertices;
        std::vector<GLuint>         m_Indices;
        std::vector<Model::Texture> m_Textures;
    };


private:
    // ---------------------------------------------------------------------------- assimp lib
    void                         processNode(aiNode* node, const aiScene* scene);
    std::unique_ptr<Model::Mesh> processMesh(aiMesh* mesh, const aiScene* scene);

    void loadModel(const std::string& filename);
    void loadMaterialTextures(std::vector<Model::Texture>& textures,
                              aiMaterial*                  material,
                              const aiTextureType          type,
                              const std::string_view       typeName);


private:
    std::vector<Model::Texture>               m_Textures;
    std::vector<std::unique_ptr<Model::Mesh>> m_Meshes;
    std::string                               m_DirectoryName;
    bool                                      m_GammaCorrection;
};



} // namespace engine::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___
