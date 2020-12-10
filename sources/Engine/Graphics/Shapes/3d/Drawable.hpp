/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Drawable
** File description:
** Drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_DRAWABLE_HPP___

#include <functional>
#include <vector>

#include <glm/vec3.hpp>

#include "../../../Camera.hpp"
#include "../../../Container/Vector/Texture.hpp"
#include "../../../Shader.hpp"
#include "../../Vertexes/Vao.hpp"
#include "../../Vertexes/Vbo.hpp"



namespace engine::shape3d {



class Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Drawable(engine::Shader&              shader,
                      const std::function<void()>& setAttributes,
                      const size_t                 numberOfTextures = 1);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    void         update(const engine::Camera& camera);
    virtual void draw(const engine::Camera& camera) = 0;


    // ---------------------------------------------------------------------------- Textures
    void addTexture(const std::string_view filepath, const std::string_view name, const int index);

    const engine::container::vector::Texture& getTextures() const;


    // ---------------------------------------------------------------------------- Shader
    void                  setShader(engine::Shader& shader);
    const engine::Shader& getShader() const;
    engine::Shader&       getShader();

    // ---------------------------------------------------------------------------- Scale
    void setScale(const float scaleX, const float scaleY, const float scaleZ);
    void setScale(const glm::vec3& scale);
    void setScale(glm::vec3&& scale);

    const glm::vec3& getScale() const;


protected:
    // ---------------------------------------------------------------------------- pure virtuals
    virtual void      setAllIntoShader(const engine::Camera& camera) = 0;
    virtual glm::mat4 getModel(const glm::vec3& position)            = 0;
    virtual size_t    getNumberOfArrayToDraw()                       = 0;


protected:
    std::reference_wrapper<engine::Shader> m_Shader;
    engine::Vao                            m_Vao;
    engine::container::vector::Texture     m_TextureVector;

    glm::vec3 m_Scale { 1.0F, 1.0F, 1.0F };

private:
    engine::Vbo m_Vbo;
    GLuint      m_Ebo;
};



} // namespace engine::shape3d



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_DRAWABLE_HPP___
