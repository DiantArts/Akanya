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

#include "Mesh.hpp"



namespace engine {



class Model {
public:
    explicit Model(engine::Shader& shader, const std::string& filepath, bool gamma = false);
    ~Model();


    // ---------------------------------------------------------------------------- Draw
    void draw() const;


    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;


private:
    // ---------------------------------------------------------------------------- assimp lib
    void                          loadModel(const std::string& filepath);
    void                          processNode(aiNode* node, const aiScene* scene);
    std::unique_ptr<engine::Mesh> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<engine::Texture>
    loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string_view typeName);

    GLuint textureFromFile(const std::string_view textureFilepath, std::string_view directory, bool gamma);


private:
    std::vector<engine::Texture>               m_Textures;
    std::vector<std::unique_ptr<engine::Mesh>> m_Meshes;
    std::string                                m_Directory;
    bool                                       m_GammaCorrection;

    mutable std::reference_wrapper<engine::Shader> m_Shader;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MODEL_HPP___
