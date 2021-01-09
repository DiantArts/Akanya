/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Model
** File description:
** This class loads models from .objs (at least and for the moment)
*/

#include "Model.hpp"

#include <stb/stb_image.h>

#include "debugMacros.hpp"

#include "../Filepaths.hpp"


namespace engine::actor {



// ---------------------------------------------------------------------------- *structors

Model::Model(engine::Shader&    shader,
             const std::string& filename,
             const size_t       numberOfPositions /* = 1 */,
             const bool         gamma /* = false */)
    : engine::actor::AActor(shader, numberOfPositions), m_GammaCorrection(gamma)
{
    this->loadModel(filename);
    DEBUG_MSG("model created");
}

Model::~Model()
{}



// ---------------------------------------------------------------------------- overrides

void Model::drawModels(const engine::Camera&) const
{
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        for (auto& mesh : this->m_Meshes) {
            mesh->draw();
        }
    }
}

//

void Model::update(float deltaTime)
{
    this->useShader();
    for (auto& mesh : this->m_Meshes) {
        mesh->update(deltaTime);
    }
    glUseProgram(0);
}



// ---------------------------------------------------------------------------- Mesh

Model::Mesh::Mesh(const engine::Shader&         shader,
                  std::vector<Model::Vertex>&&  vertices,
                  std::vector<GLuint>&&         indices,
                  std::vector<Model::Texture>&& textures)
    : m_Shader(shader)
    , m_Vertices(std::move(vertices))
    , m_Indices(std::move(indices))
    , m_Textures(std::move(textures))
{
    this->m_Vao.bind();

    this->m_Vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, this->m_Vertices.size() * sizeof(Model::Vertex), &this->m_Vertices[0],
                 GL_STATIC_DRAW);

    this->m_Ebo.bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_Indices.size() * sizeof(GLuint), &this->m_Indices[0],
                 GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex), nullptr);

    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex),
                          reinterpret_cast<void*>(offsetof(Model::Vertex, Normal)));

    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex),
                          reinterpret_cast<void*>(offsetof(Model::Vertex, TexCoords)));

    // vertex tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex),
                          reinterpret_cast<void*>(offsetof(Model::Vertex, Tangent)));

    // vertex bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Model::Vertex),
                          reinterpret_cast<void*>(offsetof(Model::Vertex, Bitangent)));
}

Model::Mesh::~Mesh()
{}

//

void Model::Mesh::draw() const
{
    for (size_t i = 0; i < this->m_Textures.size(); ++i) {
        glActiveTexture(GL_TEXTURE0 + i);
        this->m_Shader.set(this->m_Textures[i].getName().c_str(), static_cast<float>(i));
        glBindTexture(GL_TEXTURE_2D, this->m_Textures[i].get());
    }
    this->m_Vao.bind();
    glDrawElements(GL_TRIANGLES, this->m_Indices.size(), GL_UNSIGNED_INT, 0);
}

//

void Model::Mesh::update(float)
{}



// ---------------------------------------------------------------------------- assimp lib
void Model::loadModel(const std::string& filename)
{
    Assimp::Importer importer;

#ifdef __linux__
    this->m_DirectoryName = filename.substr(0, filename.find_last_of('/'));
#elif _WIN32
    this->m_DirectoryName = filename.substr(0, filename.find_last_of('\\'));
#elif
    this->m_DirectoryName = filename.substr(0, filename.find_last_of('/'));
#endif

    std::string filepath;
    filepath.reserve(engine::filepath::model.size() + 1 + filename.size());
    filepath += engine::filepath::model;
    filepath += '/';
    filepath += filename;
    const aiScene* scene { importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                                                           aiProcess_FlipUVs | aiProcess_CalcTangentSpace) };

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        throw std::runtime_error(std::string("ERROR::ASSIMP::") + importer.GetErrorString());
    }

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (size_t i = 0; i < node->mNumMeshes; ++i) {
        this->m_Meshes.push_back(processMesh(scene->mMeshes[node->mMeshes[i]], scene));
    }

    for (size_t i = 0; i < node->mNumChildren; ++i) {
        processNode(node->mChildren[i], scene);
    }
}

std::unique_ptr<Model::Mesh> Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Model::Vertex> vertices;
    for (size_t i = 0; i < mesh->mNumVertices; ++i) {
        Model::Vertex vertex;

        vertex.Position = glm::vec3 { std::move(mesh->mVertices[i].x), std::move(mesh->mVertices[i].y),
                                      std::move(mesh->mVertices[i].z) };

        if (mesh->HasNormals()) {
            vertex.Normal = glm::vec3 { std::move(mesh->mNormals[i].x), std::move(mesh->mNormals[i].y),
                                        std::move(mesh->mNormals[i].z) };
        }

        if (mesh->mTextureCoords[0]) {
            vertex.TexCoords = glm::vec2 { std::move(mesh->mTextureCoords[0][i].x),
                                           std::move(mesh->mTextureCoords[0][i].y) };
            vertex.Tangent   = glm::vec3 { std::move(mesh->mTangents[i].x), std::move(mesh->mTangents[i].y),
                                         std::move(mesh->mTangents[i].z) };
            vertex.Bitangent =
                glm::vec3 { std::move(mesh->mBitangents[i].x), std::move(mesh->mBitangents[i].y),
                            std::move(mesh->mBitangents[i].z) };
        }

        vertices.push_back(vertex);
    }

    std::vector<GLuint> indices;
    for (size_t i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face { mesh->mFaces[i] };
        for (size_t j = 0; j < face.mNumIndices; ++j) {
            indices.push_back(std::move(face.mIndices[j]));
        }
    }

    aiMaterial* material { scene->mMaterials[mesh->mMaterialIndex] };

    std::vector<Model::Texture> textures;
    loadMaterialTextures(textures, material, aiTextureType_DIFFUSE, "texture_diffuse");
    loadMaterialTextures(textures, material, aiTextureType_SPECULAR, "texture_specular");
    loadMaterialTextures(textures, material, aiTextureType_HEIGHT, "texture_normal");
    loadMaterialTextures(textures, material, aiTextureType_AMBIENT, "texture_height");

    return std::make_unique<Model::Mesh>(this->getShader(), std::move(vertices), std::move(indices),
                                         std::move(textures));
}

void Model::loadMaterialTextures(std::vector<Model::Texture>& textures,
                                 aiMaterial*                  material,
                                 const aiTextureType          type,
                                 const std::string_view       typeName)
{
    for (size_t i { 0 }; i < material->GetTextureCount(type); ++i) {
        aiString str;
        material->GetTexture(type, i, &str);
        textures.emplace_back(str.C_Str(), this->m_DirectoryName, typeName, i);
    }
}

Model::Texture::Texture(const std::string&     filename,
                        const std::string&     directoryName,
                        const std::string_view typeName,
                        const size_t           i)
    : engine::actor::Texture(filename)
{
    if (this->m_Id.use_count() == 1) { // if need initialisation
        std::string textureFilepath;
        textureFilepath.reserve(engine::filepath::model.size() + directoryName.size() + filename.size() + 2);
        textureFilepath += engine::filepath::model;
        textureFilepath += '/';
        textureFilepath += directoryName;
        textureFilepath += '/';
        textureFilepath += filename;

        int        width, height, nrComponents;
        const auto data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

        if (!data) {
            throw std::runtime_error(std::string("Failed to load '") + textureFilepath + "' texture");
        }

        GLenum format;
        switch (nrComponents) {
        case 1: format = GL_RED; break;
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default:
            stbi_image_free(const_cast<unsigned char*>(data));
            throw std::runtime_error("unsupported texture format found");
        }

        glBindTexture(GL_TEXTURE_2D, *this->m_Id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(const_cast<unsigned char*>(data));
    }

    this->m_Name.reserve(typeName.size() + 10);
    this->m_Name += "material.";
    this->m_Name += typeName.data();
    this->m_Name += std::to_string(i);
}

Model::Texture::~Texture()
{}

const std::string& Model::Texture::getName() const
{
    return this->m_Name;
}



} // namespace engine::actor
