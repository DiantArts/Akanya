/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Mesh
** File description:
** Mesh
*/

#include "Mesh.hpp"



namespace engine {



// ---------------------------------------------------------------------------- *structors
Mesh::Mesh(std::vector<engine::Vertex>&&  vertices,
           std::vector<GLuint>&&          indices,
           std::vector<engine::Texture>&& textures)
    : m_Vertices(std::move(vertices)), m_Indices(std::move(indices)), m_Textures(std::move(textures))
{
    this->m_Vao.bind();

    this->m_Vbo.bind();
    glBufferData(GL_ARRAY_BUFFER, this->m_Vertices.size() * sizeof(engine::Vertex), &this->m_Vertices[0],
                 GL_STATIC_DRAW);

    this->m_Ebo.bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_Indices.size() * sizeof(GLuint), &this->m_Indices[0],
                 GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(engine::Vertex), nullptr);

    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(engine::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::Vertex, Normal)));

    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(engine::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::Vertex, TexCoords)));

    // vertex tangent
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(engine::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::Vertex, Tangent)));

    // vertex bitangent
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(engine::Vertex),
                          reinterpret_cast<void*>(offsetof(engine::Vertex, Bitangent)));
}

Mesh::~Mesh()
{}



// ---------------------------------------------------------------------------- Draw
void Mesh::draw(engine::Shader& shader) const
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

        shader.set(name.c_str(), static_cast<float>(i));
        glBindTexture(GL_TEXTURE_2D, this->m_Textures[i].id);
    }
    // draw mesh
    this->m_Vao.bind();
    glDrawElements(GL_TRIANGLES, this->m_Indices.size(), GL_UNSIGNED_INT, 0);
}



} // namespace engine
