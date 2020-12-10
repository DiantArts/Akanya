/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Single/Drawable
** File description:
** Drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_DRAWABLE_HPP___

#include <functional>

#include <glm/vec3.hpp>

#include "../../../../Camera.hpp"
#include "../../../../Shader.hpp"
#include "../../../Vertexes/Vao.hpp"
#include "../../../Vertexes/Vbo.hpp"
#include "../Drawable.hpp"



namespace engine::shape3d::single {



class Drawable : public engine::shape3d::Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Drawable(engine::Shader&              shader,
                      const glm::vec3&             position,
                      const std::function<void()>& setAttributes,
                      const size_t                 numberOfTextures = 1);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    void draw(const engine::Camera& camera);


    // ---------------------------------------------------------------------------- Position
    void setPosition(float positionX = 0, float positionY = 0, float positionZ = 0);
    void setPosition(const glm::vec3& position);
    void setPosition(glm::vec3&& position);

    const glm::vec3& getPosition() const;

protected:
    glm::vec3 m_Position;
};



} // namespace engine::shape3d::single



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_SINGLE_DRAWABLE_HPP___
