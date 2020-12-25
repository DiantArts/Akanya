/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Model
** File description:
** Models
*/

#include "Model.hpp"

#include "debugMacros.hpp"


namespace engine::graphic {



// ---------------------------------------------------------------------------- *structors

Model::Model(engine::Shader&    shader,
             const std::string& filepath,
             const size_t       numberOfPositions /* = 1 */,
             const bool         gamma /* = false */)
    : engine::graphic::Shape(shader, numberOfPositions), m_GammaCorrection(gamma)
{
    this->loadModel(filepath);
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
    for (auto& mesh : this->m_Meshes) {
        mesh->update(deltaTime);
    }
}



// ---------------------------------------------------------------------------- Mesh

Model::Mesh::Mesh(engine::Shader&                         shader,
           std::vector<engine::graphic::Model::Vertex>&&                  vertices,
           std::vector<GLuint>&&                          indices,
           std::vector<engine::graphic::Model::Texture>&& textures)
    : m_Shader(shader)
    , m_Vertices(std::move(vertices))
    , m_Indices(std::move(indices))
    , m_Textures(std::move(textures))
{
    this->m_Vao.bind();

    this->m_Vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, this->m_Vertices.size() * sizeof(engine::graphic::Model::Vertex), &this->m_Vertices[0],
                 GL_STATIC_DRAW);

    this->m_Ebo.bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_Indices.size() * sizeof(GLuint), &this->m_Indices[0],
                 GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(engine::graphic::Model::Vertex), nullptr);

    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(engine::graphic::Model::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::graphic::Model::Vertex, Normal)));

    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(engine::graphic::Model::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::graphic::Model::Vertex, TexCoords)));

    // vertex tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(engine::graphic::Model::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::graphic::Model::Vertex, Tangent)));

    // vertex bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(engine::graphic::Model::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::graphic::Model::Vertex, Bitangent)));
}

Model::Mesh::~Mesh()
{}

//

void Model::Mesh::draw() const
{
    size_t diffuseIndex { 1 }, specularIndex { 1 }, normalIndex { 1 }, heightIndex { 1 };

    for (size_t i = 0; i < this->m_Textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string name { "material." };
        name += this->m_Textures[i].type;
        if (this->m_Textures[i].type == "texture_diffuse") {
            name += std::to_string(diffuseIndex++);
        } else if (this->m_Textures[i].type == "texture_specular") {
            name += std::to_string(specularIndex++);
        } else if (name == "texture_normal") {
            name += std::to_string(normalIndex++);
        } else if (name == "texture_height") {
            name += std::to_string(heightIndex++);
        }

        this->m_Shader.get().set(name.c_str(), static_cast<float>(i));
        glBindTexture(GL_TEXTURE_2D, this->m_Textures[i].id);
    }
    this->m_Vao.bind();
    glDrawElements(GL_TRIANGLES, this->m_Indices.size(), GL_UNSIGNED_INT, 0);
}

//

void Model::Mesh::update(float)
{}





// ---------------------------------------------------------------------------- assimp lib
void Model::loadModel(const std::string& filepath)
{
    Assimp::Importer importer;
    const aiScene*   scene { importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                                                           aiProcess_FlipUVs | aiProcess_CalcTangentSpace) };

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        throw std::runtime_error(std::string("ERROR::ASSIMP::") + importer.GetErrorString());
    }

#ifdef __linux__
    this->m_Directory = filepath.substr(0, filepath.find_last_of('/'));
#elif _WIN32
    this->m_Directory = filepath.substr(0, filepath.find_last_of('\\'));
#elif
    this->m_Directory = filepath.substr(0, filepath.find_last_of('/'));
#endif

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

std::unique_ptr<engine::graphic::Model::Mesh> Model::processMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<engine::graphic::Model::Vertex> vertices;
    for (size_t i = 0; i < mesh->mNumVertices; i++) {
        engine::graphic::Model::Vertex vertex;

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
    for (size_t i = 0; i < mesh->mNumFaces; i++) {
        aiFace face { mesh->mFaces[i] };
        for (size_t j = 0; j < face.mNumIndices; j++) {
            indices.push_back(std::move(face.mIndices[j]));
        }
    }

    aiMaterial* material { scene->mMaterials[mesh->mMaterialIndex] };

    std::vector<engine::graphic::Model::Texture> diffuseMaps =
        loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
    std::vector<engine::graphic::Model::Texture> specularMaps =
        loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
    std::vector<engine::graphic::Model::Texture> normalMaps =
        loadMaterialTextures(material, aiTextureType_HEIGHT, "texture_normal");
    std::vector<engine::graphic::Model::Texture> heightMaps =
        loadMaterialTextures(material, aiTextureType_AMBIENT, "texture_height");

    std::vector<engine::graphic::Model::Texture> textures;
    textures.reserve(diffuseMaps.size() + specularMaps.size() + normalMaps.size() + heightMaps.size());
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());

    return std::make_unique<engine::graphic::Model::Mesh>(this->m_Shader, std::move(vertices), std::move(indices),
                                          std::move(textures));
}

std::vector<engine::graphic::Model::Texture>
Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, const std::string_view typeName)
{
    std::vector<engine::graphic::Model::Texture> textures;
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
            engine::graphic::Model::Texture texture;
            texture.id       = this->textureFromFile(str.C_Str(), this->m_Directory, this->m_GammaCorrection);
            texture.type     = typeName;
            texture.filepath = str.C_Str();
            textures.push_back(texture);
            this->m_Textures.push_back(texture);
        }
    }
    return textures;
}

GLuint Model::textureFromFile(const std::string_view textureFilename, std::string_view directory, bool)
{
    std::string textureFilepath;
    textureFilepath.reserve(directory.size() + 1 + textureFilename.size());
    textureFilepath += directory;
    textureFilepath += '/';
    textureFilepath += textureFilename;

    int        width, height, nrComponents;
    const auto data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

    if (!data) {
        throw std::runtime_error(std::string("ERROR: Failed to load '") + textureFilepath + "' texture\n");
    }

    GLenum format;
    switch (nrComponents) {
    case 1: format = GL_RED; break;
    case 3: format = GL_RGB; break;
    case 4: format = GL_RGBA; break;
    default: throw std::runtime_error("unsupported texture format found");
    }

    GLuint textureId;
    glGenTextures(1, &textureId);

    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(const_cast<unsigned char*>(data));

    return textureId;
}



} // namespace engine::graphic
