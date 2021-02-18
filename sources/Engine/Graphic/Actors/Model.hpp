//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Model
// This class loads models from .objs (at least and for the moment)
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_MODEL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_MODEL_HPP___

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include "Texture.hpp"



namespace engine::graphic::actor {



class Model
    : public engine::graphic::AActor
{

public:

    // ---------------------------------- *structors
    explicit Model(
        const std::string& shaderFilepath,
        const std::string& filename,
        size_t numberOfPositions = 1,
        bool gamma = false
    );

    ~Model();



    // ---------------------------------- Copy sementic

    Model(
        const Model&
    ) noexcept = delete;

    auto operator=(
        const Model&
    ) noexcept -> Model& = delete;



    // ---------------------------------- Move sementic

    Model(
        Model&&
    ) noexcept = delete;

    auto operator=(
        Model&&
    ) noexcept -> Model& = delete;



    // ---------------------------------- Overrides

    virtual void update(
        float deltaTime
    ) override;

    virtual void drawModels() const override;



protected:
protected:

    class Texture
        : public engine::graphic::actor::Texture
    {

    public:

        // ------------------------------------------------ *structors
        Texture(
            const std::string& filename,
            const std::string& directoryName,
            std::string_view   type,
            size_t             i
        );



        // ---------------------------------- Copy sementic

        Texture(
            const Texture&
        ) noexcept;

        auto operator=(
            const Texture&
        ) noexcept -> Texture&;



        // ---------------------------------- Move sementic

        Texture(
            Texture&&
        ) noexcept;

        auto operator=(
            Texture&&
        ) noexcept -> Texture&;

        ~Texture();

        const std::string& getName() const;

    private:
        std::string m_name;

    };


    struct Vertex {
        glm::vec3 Position;
        glm::vec3 Normal;
        glm::vec2 TexCoords { 0.0F };
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
    };


    class Mesh {

    public:

        // ---------------------------------------------------------- *structors
        explicit Mesh(
            const ::engine::graphic::opengl::Shader&         shader,
            std::vector<Model::Vertex>&&  vertices,
            std::vector<GLuint>&&         indices,
            std::vector<Model::Texture>&& textures
        );

        ~Mesh();



        // ---------------------------------- Copy sementic

        Mesh(
            const Mesh&
        ) noexcept;

        auto operator=(
            const Mesh&
        ) noexcept -> Mesh&;



        // ---------------------------------- Move sementic

        Mesh(
            Mesh&&
        ) noexcept;

        auto operator=(
            Mesh&&
        ) noexcept -> Mesh&;



        // ---------------------------------------------------------- Draw
        void draw() const;

        virtual void update(
            float deltaTime
        );



    public:
    protected:
    protected:
    private:
    private:

        const ::engine::graphic::opengl::Shader& m_shader;

        ::engine::graphic::opengl::Vao m_vao;
        ::engine::graphic::opengl::Vbo m_vbo;
        ::engine::graphic::opengl::Ebo m_ebo;

        std::vector<Model::Vertex>  m_vertices;
        std::vector<GLuint>         m_indices;
        std::vector<Model::Texture> m_textures;

    };



    // ---------------------------------- assimp lib

    void processNode(aiNode* node, const aiScene* scene);

    std::unique_ptr<::engine::graphic::actor::Model::Mesh> processMesh(aiMesh* mesh, const aiScene* scene);

    void loadModel(const std::string& filename);

    void loadMaterialTextures(std::vector<Model::Texture>& textures,
                              aiMaterial*                  material,
                              const aiTextureType          type,
                              const std::string_view       typeName);


private:

    std::vector<Model::Texture>               m_textures;
    std::vector<std::unique_ptr<Model::Mesh>> m_meshes;
    std::string                               m_directoryName;
    bool                                      m_gammaCorrection;

};



} // namespace engine::graphic::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_MODEL_HPP___
