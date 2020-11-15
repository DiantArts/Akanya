/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#pragma once

#include <glm/vec3.hpp>
#include "Engine/Shader.hpp"
#include "Engine/Camera.hpp"
#include "Engine/Texture/Vector.hpp"
#include "Engine/Vertexes/Vao.hpp"
#include "Engine/Vertexes/Vbo.hpp"

namespace engine::shape3d {

class Drawable {
public:
    Drawable(engine::Shader& shader, glm::vec3 position, size_t numberOfTextures = 1);
    virtual ~Drawable();

    void changeShader(engine::Shader& shader);
    void addTexture(const std::string_view filepath, const std::string_view name, int index);
    void draw(const engine::Camera& camera);

// ---------------------------------------------------------------------------- Position
    void setPosition(float positionX = 0, float positionY = 0, float positionZ = 0);
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);
    const glm::vec3& getPosition() const;

protected:
    virtual void setAllIntoShader(const engine::Camera& camera) = 0;
    virtual glm::mat4 getModel(const glm::vec3& position) = 0;
    virtual size_t getNumberOfArrayToDraw() = 0;

protected:
    engine::Shader& m_Shader;
    glm::vec3 m_Position;

private:
    engine::Vao m_Vao;
    engine::Vbo m_Vbo;
    engine::texture::Vector m_TextureVector;

    GLuint m_Ebo;
};

} // namespace engine::shape3d
