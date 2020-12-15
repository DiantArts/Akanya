/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Model
** File description:
** Models
*/

#include "Model.hpp"



namespace engine {



Model::Model(engine::Shader& shader, const std::string& filepath, bool gamma /* = false */)
    : m_GammaCorrection(gamma), m_Shader(shader)
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
    const aiScene*   scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                                                           aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        throw std::runtime_error(std::string("ERROR::ASSIMP::") + importer.GetErrorString());
    }

    this->m_Directory = filepath.substr(0, filepath.find_last_of('/'));
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (size_t i = 0; i < node->mNumMeshes; i++) {
        this->m_Meshes.push_back(processMesh(scene->mMeshes[node->mMeshes[i]], scene));
    }

    for (size_t i = 0; i < node->mNumChildren; i++) {
        processNode(node->mChildren[i], scene);
    }
}

engine::Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex>  vertices;
    std::vector<GLuint>  indices;
    std::vector<Texture> textures;

    for (size_t i = 0; i < mesh->mNumVertices; i++) {
        engine::Vertex vertex;

        vertex.Position = glm::vec3 { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z };

        if (mesh->HasNormals()) {
            vertex.Normal = glm::vec3 { mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z };
        }

        // texture coordinates
        if (mesh->mTextureCoords[0]) {
            vertex.TexCoords = glm::vec2 { mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y };
            vertex.Tangent   = glm::vec3 { mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z };
            vertex.Bitangent =
                glm::vec3 { mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z };
        } else {
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);
        }

        vertices.push_back(vertex);
    }

    for (size_t i = 0; i < mesh->mNumFaces; i++) {
        aiFace face { mesh->mFaces[i] };
        for (size_t j = 0; j < face.mNumIndices; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }

    aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];


    std::vector<engine::Texture> diffuseMaps =
        loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

    std::vector<engine::Texture> specularMaps =
        loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());

    std::vector<engine::Texture> normalMaps =
        loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());

    std::vector<engine::Texture> heightMaps =
        loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    return Mesh(std::move(vertices), std::move(indices), std::move(textures));
}

std::vector<engine::Texture>
Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string_view typeName)
{
    std::vector<Texture> textures;
    for (size_t i = 0; i < mat->GetTextureCount(type); i++) {
        aiString str;
        mat->GetTexture(type, i, &str);
        bool isTextureAlreadyLoaded { false };
        for (size_t j = 0; j < this->m_Textures.size(); j++) {
            if (std::strcmp(this->m_Textures[j].filepath.data(), str.C_Str()) == 0) {
                textures.push_back(this->m_Textures[j]);
                isTextureAlreadyLoaded = true;
                break;
            }
        }
        if (!isTextureAlreadyLoaded) {
            engine::Texture texture;
            texture.id       = this->textureFromFile(str.C_Str(), this->m_Directory, this->m_GammaCorrection);
            texture.type     = typeName;
            texture.filepath = str.C_Str();
            textures.push_back(texture);
            this->m_Textures.push_back(texture);
        }
    }
    return textures;
}

GLuint Model::textureFromFile(const std::string& textureFilename, std::string& directory, bool)
{
    int         width, height, nrComponents;
    std::string textureFilepath;
    textureFilepath.reserve(textureFilename.size() + 1 + directory.size());
    textureFilepath += directory;
    textureFilepath += '/';
    textureFilepath += textureFilename;
    const unsigned char* const data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

    GLuint textureId;

    if (data) {
        GLenum format;
        switch (nrComponents) {
        case 1: format = GL_RED; break;
        case 3: format = GL_RGB; break;
        case 4: format = GL_RGBA; break;
        default: throw std::runtime_error("unsupported texture format found");
        }

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    } else {
        std::cerr << "heyyyy" << std::endl;
        throw std::runtime_error(std::string("ERROR: Failed to load '") + textureFilepath + "' texture\n");
    }
    stbi_image_free(const_cast<unsigned char*>(data));

    return textureId;
}



} // namespace engine
