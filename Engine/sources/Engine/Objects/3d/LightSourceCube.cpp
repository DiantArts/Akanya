/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#include <glm/gtc/matrix_transform.hpp>
#include "Engine/Vertexes/Vertices.hpp"
#include "Engine/Objects/3d/LightSourceCube.hpp"

extern glm::vec3 lightPos;

namespace engine::object3d {

LightSourceCube::LightSourceCube(engine::Shader& shader)
    : UpdatedCube(shader)
{}

LightSourceCube::~LightSourceCube()
{}

void LightSourceCube::setAllIntoShader()
{}

} // namespace engine::object3d
