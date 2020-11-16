/*
** EPITECH PROJECT, 2020
** UpdatedMultipleCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/Multiple/UpdatedCube.hpp"

#include "Engine/Objects/3d/LightSourceCube.hpp" // tmp
extern engine::object3d::LightSourceCube& getLamp();

namespace engine::shape3d::multiple {

UpdatedCube::UpdatedCube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    // engine::Vertices("updatedCube").createBuffer();
    // vertex attribute
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    // glEnableVertexAttribArray(0);
    // normal attribute
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // glEnableVertexAttribArray(1);

    engine::Vertices("lightningMap").createBuffer();

    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // normal attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

UpdatedCube::~UpdatedCube()
{}

void UpdatedCube::setAllIntoShader(const engine::Camera&)
{}

glm::mat4 UpdatedCube::getModel(const glm::vec3&)
{
    auto model(glm::mat4(1.0f));
    model = glm::translate(model, getLamp().getPosition());
    model = glm::scale(model, glm::vec3(0.2f));
    return model;
}

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}

} // namespace engine::shape3d::multiple
