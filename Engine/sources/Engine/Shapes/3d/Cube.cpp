/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include <glm/gtc/matrix_transform.hpp> // glm::perspective, glm::rotate, glm:::translate
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Shapes/3d/Cube.hpp"

namespace engine::shape3d {

Cube::Cube(engine::Shader& shader, glm::vec3 position /* = glm::vec3(0, 0, 0) */)
    : Drawable(shader, position)
{
    engine::Vertices("cube").createBuffer();

    // position corrd attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // texture corrd attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->addTexture("wall.jpg", "texture1", 0);
    this->addTexture("awesomeface.png", "texture2", 1);
}

Cube::~Cube()
{}

void Cube::setAllIntoShader(const engine::Camera&)
{}

glm::mat4 Cube::getModel(const glm::vec3& position)
{
    return glm::rotate(glm::translate(glm::mat4(1.0f), position), glm::radians(20.0f),
            glm::vec3(1.0f, 0.3f, 0.5f));
}

size_t Cube::getNumberOfArrayToDraw()
{
    return this->numberOfArrayToDraw;
}

} // namespace engine::shape3d
