/*
** EPITECH PROJECT, 2020
** UpdatedCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/UpdatedCube.hpp"

extern glm::vec3 lightPos;

namespace engine::shape3d {

UpdatedCube::UpdatedCube(engine::Shader& shader)
    : Drawable(shader, 1)
{
    engine::Vertices("updatedCube").createBuffer();

    // vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

UpdatedCube::~UpdatedCube()
{}

void UpdatedCube::setAllIntoShader()
{}

glm::mat4 UpdatedCube::getModel(const glm::vec3&)
{
    auto model(glm::mat4(1.0f));
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));
    return model;
}

size_t UpdatedCube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}

} // namespace engine::shape3d
