/*
** EPITECH PROJECT, 2020
** main
** File description:
** test
*/

#include "Cube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Vertexes/Vertices.hpp"



namespace engine::shape3d::single {



// ---------------------------------------------------------------------------- *structors

Cube::Cube(engine::Shader&              shader,
           const glm::vec3&             position /* = glm::vec3(0, 0, 0) */,
           const std::string_view       verticesFileName /* = "updateCube" */,
           const std::function<void()>& attributesSetter /* []{ ... } */,
           const size_t                 numberOfTextures /* = 1 */)
    : Drawable(shader, position, attributesSetter, numberOfTextures)
{
    engine::Vertices(verticesFileName).createBuffer();
    this->addTexture("wall.jpg", "texture1", 0);
    this->addTexture("awesomeface.png", "texture2", 1);
}



// ---------------------------------------------------------------------------- override

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



} // namespace engine::shape3d::single
