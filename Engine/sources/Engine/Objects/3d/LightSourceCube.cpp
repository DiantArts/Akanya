/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Objects/3d/LightSourceCube.hpp"

namespace engine::object3d {

LightSourceCube::LightSourceCube(engine::Shader& shader, glm::vec3 position /* = glm::vec3(0, 0, 0) */)
    : UpdatedCube(shader, position)
{}

LightSourceCube::~LightSourceCube()
{}

void LightSourceCube::setAllIntoShader(const engine::Camera&)
{}

} // namespace engine::object3d
