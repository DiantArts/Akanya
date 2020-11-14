/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#ifndef UPDATE_CUBE_HPP
#define UPDATE_CUBE_HPP

#include <Engine/Shapes/3d/Drawable.hpp>

namespace engine::shape3d {

class UpdatedCube : public engine::shape3d::Drawable {
public:
    UpdatedCube(engine::Shader& shaderProgram);
    virtual ~UpdatedCube();

    virtual size_t getNumberOfArrayToDraw() override final;

    virtual void setAllIntoShader();
    virtual glm::mat4 getModel(const glm::vec3& position);

protected:
    constexpr static size_t numberOfArrayToDraw = 36;
};

} // namespace engine::shape3d

#endif // UPDATE_CUBE_HPP
