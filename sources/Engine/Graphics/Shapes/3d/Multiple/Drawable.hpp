/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Shapes/3d/Multiple/Drawable
** File description:
** drawable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_DRAWABLE_HPP___

#include <functional>
#include <vector>

#include <glm/vec3.hpp>

#include "../../../../Camera.hpp"
#include "../../../../Shader.hpp"
#include "../../../Vertexes/Vao.hpp"
#include "../../../Vertexes/Vbo.hpp"
#include "../Drawable.hpp"



namespace engine::shape3d::multiple {



class Drawable : public engine::shape3d::Drawable {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Drawable(engine::Shader&              shader,
                      const std::function<void()>& setAttributes,
                      const size_t                 numberOfTextures = 1);
    virtual ~Drawable() = 0;


    // ---------------------------------------------------------------------------- Draw
    void draw(const engine::Camera& camera);


    // ---------------------------------------------------------------------------- Positions
    void addPosition(float x = 0, float y = 0, float z = 0);
    void addPosition(glm::vec3 position);

    const std::vector<glm::vec3>& getPosition() const;


protected:
    std::vector<glm::vec3> m_VectorPositions;
};



} // namespace engine::shape3d::multiple



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_SHAPES_3D_MULTIPLE_DRAWABLE_HPP___
