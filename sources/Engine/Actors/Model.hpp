/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Model
** File description:
** This class loads models from .objs (at least and for the moment)
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___

#include <assimp/Importer.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "AShape.hpp"
#include "Vertexes/Ebo.hpp"
#include "Vertexes/Vao.hpp"
#include "Vertexes/Vbo.hpp"



namespace engine::actor {



class Model : public engine::actor::AShape {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Model(engine::Shader&    shader,
                   const std::string& filepath,
                   size_t             numberOfPositions = 1,
                   bool               gamma             = false);
    ~Model();


    // ---------------------------------------------------------------------------- Overrides
    virtual void update(float deltaTime) override;
    virtual void drawModels(const engine::Camera& camera) const override;

private:
    // ---------------------------------------------------------------------------- Texture
    struct Texture {
        GLuint      id;
        std::string type;
        std::string filepath;
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
        explicit Mesh(const engine::Shader&                        shader,
                      std::vector<engine::actor::Model::Vertex>&&  vertices,
                      std::vector<GLuint>&&                        indices,
                      std::vector<engine::actor::Model::Texture>&& textures);
        ~Mesh();

        // ---------------------------------------------------------- Draw
        void         draw() const;
        virtual void update(float deltaTime);

    private:
        const engine::Shader& m_Shader;

        engine::Vao m_Vao;
        engine::Vbo m_Vbo;
        engine::Ebo m_Ebo;

        std::vector<engine::actor::Model::Vertex>  m_Vertices;
        std::vector<GLuint>                        m_Indices;
        std::vector<engine::actor::Model::Texture> m_Textures;
    };


private:
    // ---------------------------------------------------------------------------- assimp lib
    void                                        loadModel(const std::string& filepath);
    void                                        processNode(aiNode* node, const aiScene* scene);
    std::unique_ptr<engine::actor::Model::Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<engine::actor::Model::Texture>
    loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string_view typeName);

    GLuint textureFromFile(std::string_view textureFilepath, std::string_view directory, bool gamma);


private:
    std::vector<engine::actor::Model::Texture>               m_Textures;
    std::vector<std::unique_ptr<engine::actor::Model::Mesh>> m_Meshes;
    std::string                                              m_Directory;
    bool                                                     m_GammaCorrection;
};



} // namespace engine::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_MODEL_HPP___
