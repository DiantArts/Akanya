/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Model
** File description:
** Models
*/

#include "Model.hpp"



namespace engine {



Model::Model(engine::Shader& shader, const std::string& filepath)
    : m_Shader(shader)
{
    this->loadModel(filepath);
}

Model::~Model()
{}



// ---------------------------------------------------------------------------- Draw
void Model::draw() const
{
    for (auto& mesh : this->m_Meshes) {
        mesh.draw(this->m_Shader.get());
    }
}



// ---------------------------------------------------------------------------- Shader

void Model::setShader(engine::Shader& shader)
{
    this->m_Shader = shader;
}

const engine::Shader& Model::getShader() const
{
    return this->m_Shader.get();
}



// ---------------------------------------------------------------------------- assimp lib
void Model::loadModel(const std::string& filepath)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{}

engine::Mesh Model::processMesh(aiNode* mesh, const aiScene* scene)
{}

std::vector<engine::Texture> Model::loadMeterialTextures(aiMaterial* mat, aiTextureType type,
        const std::string_view typeName)
{}



} // namespace engine
