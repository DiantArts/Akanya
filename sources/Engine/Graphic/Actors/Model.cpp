//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Model
// This class loads models from .objs (at least and for the moment)
//

#include "pch.hpp"
#include "Model.hpp"


namespace engine::graphic::actor {



// ---------------------------------- *structors

Model::Model(::engine::graphic::opengl::Shader&    shader,
    const glm::mat4& projection,
             const std::string& filename,
             const size_t       numberOfPositions /* = 1 */,
             const bool         gamma /* = false */)
    : engine::graphic::AActor(shader, projection, numberOfPositions), m_gammaCorrection(gamma)
{
    this->loadModel(filename);
}

Model::~Model()
{}



// ---------------------------------- overrides

void Model::drawModels() const
{
    for (const auto& position : this->instances) {
        this->setIntoShader("model", this->getModel(position));
        for (auto& mesh : m_meshes) {
            mesh->draw();
        }
    }
}



void Model::update(float deltaTime)
{
    this->useShader();
    for (auto& mesh : m_meshes) {
        mesh->update(deltaTime);
    }
    glUseProgram(0);
}



// ---------------------------------- Mesh

Model::Mesh::Mesh(const ::engine::graphic::opengl::Shader&         shader,
                  std::vector<Model::Vertex>&&  vertices,
                  std::vector<GLuint>&&         indices,
                  std::vector<Model::Texture>&& textures)
    : m_shader(shader)
    , m_vertices(std::move(vertices))
    , m_indices(std::move(indices))
    , m_textures(std::move(textures))
{
    m_vao.bind();

    m_vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Model::Vertex), &m_vertices[0],
                 GL_STATIC_DRAW);

    m_ebo.bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), &m_indices[0],
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



void Model::Mesh::draw() const
{
    for (size_t i = 0; i < m_textures.size(); ++i) {
        glActiveTexture(GL_TEXTURE0 + i);
        m_shader.set(m_textures[i].getName().c_str(), static_cast<float>(i));
        glBindTexture(GL_TEXTURE_2D, m_textures[i].get());
    }
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}



void Model::Mesh::update(float)
{}



// ---------------------------------- assimp lib
void Model::loadModel(const std::string& filename)
{
    Assimp::Importer importer;

#ifdef __linux__
    m_directoryName = filename.substr(0, filename.find_last_of('/'));
#elif _WIN32
    m_directoryName = filename.substr(0, filename.find_last_of('\\'));
#elif
    m_directoryName = filename.substr(0, filename.find_last_of('/'));
#endif

    std::string filepath;
    filepath.reserve(::engine::core::config::filepath::model.size() + 1 + filename.size());
    filepath += ::engine::core::config::filepath::model;
    filepath += '/';
    filepath += filename;
    const aiScene* scene { importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_GenSmoothNormals |
                                                           aiProcess_FlipUVs | aiProcess_CalcTangentSpace) };

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        throw std::runtime_error("ERROR::ASSIMP::"s + importer.GetErrorString());
    }

    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (size_t i = 0; i < node->mNumMeshes; ++i) {
        m_meshes.push_back(processMesh(scene->mMeshes[node->mMeshes[i]], scene));
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
        textures.emplace_back(str.C_Str(), m_directoryName, typeName, i);
    }
}

Model::Texture::Texture(const std::string&     filename,
                        const std::string&     directoryName,
                        const std::string_view typeName,
                        const size_t           i)
    : engine::graphic::actor::Texture(filename)
{
    if (m_id.use_count() == 1) { // if need initialisation
        std::string textureFilepath;
        textureFilepath.reserve(::engine::core::config::filepath::model.size() + directoryName.size() + filename.size() + 2);
        textureFilepath += ::engine::core::config::filepath::model;
        textureFilepath += '/';
        textureFilepath += directoryName;
        textureFilepath += '/';
        textureFilepath += filename;

        int        width, height, nrComponents;
        const auto data { stbi_load(textureFilepath.c_str(), &width, &height, &nrComponents, 0) };

        if (!data) {
            throw std::runtime_error("Failed to load '"s + textureFilepath + "' texture");
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

        glBindTexture(GL_TEXTURE_2D, *m_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(const_cast<unsigned char*>(data));
    }

    m_name.reserve(typeName.size() + 10);
    m_name += "material.";
    m_name += typeName.data();
    m_name += std::to_string(i);
}

Model::Texture::~Texture()
{}

const std::string& Model::Texture::getName() const
{
    return m_name;
}



} // namespace engine::graphic::actor
