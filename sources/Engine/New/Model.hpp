/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Model
** File description:
** Models
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Mesh.hpp"

#include <string_view>



namespace engine {



class Model {
public:
    explicit Model(engine::Shader& shader, const std::string& filepath);
    ~Model();


    // ---------------------------------------------------------------------------- Draw
    void draw() const;


    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;


private:
    // ---------------------------------------------------------------------------- assimp lib
    void loadModel(const std::string& filepath);
    void processNode(aiNode* node, const aiScene* scene);
    engine::Mesh processMesh(aiNode* mesh, const aiScene* scene);
    std::vector<engine::Texture> loadMeterialTextures(aiMaterial* mat, aiTextureType type,
            const std::string_view typeName);



private:
    std::vector<engine::Mesh> m_Meshes;
    std::string m_Directory;

    mutable std::reference_wrapper<engine::Shader> m_Shader;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___
