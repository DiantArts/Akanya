/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Model
** File description:
** Models
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include <assimp/Importer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <glad/glad.h>
#include <stb/stb_image.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include "../Graphics/Drawable.hpp"
#include "../Graphics/Transformable.hpp"



namespace engine::actor {



class Model : public engine::actor::Shape {
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
        explicit Mesh(engine::Shader&                shader,
                      std::vector<engine::actor::Model::Vertex>&&  vertices,
                      std::vector<GLuint>&&          indices,
                      std::vector<engine::actor::Model::Texture>&& textures);
        ~Mesh();

        // ---------------------------------------------------------- Draw
        void draw() const;
        virtual void update(float deltaTime);

    private:
        std::reference_wrapper<engine::Shader> m_Shader;

        engine::Vao m_Vao;
        engine::Vbo m_Vbo;
        engine::Ebo m_Ebo;

        std::vector<engine::actor::Model::Vertex>  m_Vertices;
        std::vector<GLuint>          m_Indices;
        std::vector<engine::actor::Model::Texture> m_Textures;
    };


private:
    // ---------------------------------------------------------------------------- assimp lib
    void                                          loadModel(const std::string& filepath);
    void                                          processNode(aiNode* node, const aiScene* scene);
    std::unique_ptr<engine::actor::Model::Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<engine::actor::Model::Texture>
    loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string_view typeName);

    GLuint textureFromFile(std::string_view textureFilepath, std::string_view directory, bool gamma);


private:
    std::vector<engine::actor::Model::Texture>               m_Textures;
    std::vector<std::unique_ptr<engine::actor::Model::Mesh>> m_Meshes;
    std::string                                                m_Directory;
    bool                                                       m_GammaCorrection;
};



} // namespace engine::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___
