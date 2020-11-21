/*
** EPITECH PROJECT, 2020
** triangle
** File description:
** triangle
*/

#pragma once

#include <functional>

#include <glm/vec3.hpp>

#include "../../../Camera.hpp"
#include "../../../Shader.hpp"
#include "../../../Texture/Vector.hpp"
#include "../../../Vertexes/Vao.hpp"
#include "../../../Vertexes/Vbo.hpp"

namespace engine::shape3d::single {

class Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Drawable(engine::Shader&              shader,
             const glm::vec3&             position,
             const std::function<void()>& setAttributes,
             const size_t                 numberOfTextures = 1);
    virtual ~Drawable();


    // ---------------------------------------------------------------------------- Draw
    void draw(const engine::Camera& camera);


    // ---------------------------------------------------------------------------- Textures
    void addTexture(const std::string_view filepath, const std::string_view name, const int index);

    const engine::texture::Vector& getTextures() const;


    // ---------------------------------------------------------------------------- Shader
    void setShader(engine::Shader& shader);

    const engine::Shader& getShader() const;


    // ---------------------------------------------------------------------------- Scale
    void setScale(const float scaleX, const float scaleY, const float scaleZ);
    void setScale(const glm::vec3& scale);
    void setScale(glm::vec3&& scale);

    const glm::vec3& getScale() const;


    // ---------------------------------------------------------------------------- Position
    void             setPosition(float positionX = 0, float positionY = 0, float positionZ = 0);
    void             setPosition(const glm::vec3& position);
    void             setPosition(glm::vec3&& position);

    const glm::vec3& getPosition() const;


protected:
    virtual void      setAllIntoShader(const engine::Camera& camera) = 0;
    virtual glm::mat4 getModel(const glm::vec3& position)            = 0;
    virtual size_t    getNumberOfArrayToDraw()                       = 0;

protected:
    engine::Shader& m_Shader;
    glm::vec3       m_Position;

private:
    engine::texture::Vector m_TextureVector;
    engine::Vao             m_Vao;
    engine::Vbo             m_Vbo;
    GLuint                  m_Ebo;

    glm::vec3 m_Scale { 1.0f, 1.0f, 1.0f };
};

} // namespace engine::shape3d::single
