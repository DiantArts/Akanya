/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Mesh
** File description:
** Mesh
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MESH_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MESH_HPP___

#include <functional>
#include <vector>

#include "Texture.hpp"
#include "Vertex.hpp"

#include "../Graphics/Vertexes/Ebo.hpp"
#include "../Graphics/Vertexes/Vao.hpp"
#include "../Graphics/Vertexes/Vbo.hpp"
#include "../Shader.hpp"



namespace engine {



class Mesh {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Mesh(std::vector<engine::Vertex>&&  vertices,
                  std::vector<GLuint>&&          indices,
                  std::vector<engine::Texture>&& textures);
    ~Mesh();


    // ---------------------------------------------------------------------------- Draw
    void draw(engine::Shader& shader) const;


    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;



public:
    std::vector<engine::Vertex>  m_Vertices;
    std::vector<GLuint>          m_Indices;
    std::vector<engine::Texture> m_Textures;


private:
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    engine::Ebo m_Ebo;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_MESH_HPP___
