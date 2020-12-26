/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "EnlightenedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../Vertexes/Vertices.hpp"



// clang-format off

#include "LightSourceCube.hpp" // tmp
extern engine::object::LightSourceCube* lamp;

// clang-format on



namespace engine::object {



// ---------------------------------------------------------------------------- *structors

EnlightenedCube::EnlightenedCube(engine::Shader& shader, const size_t numberOfPositions)
    : Cube(shader, numberOfPositions, 1, EnlightenedCube::setAttributes, "lightningMap")
{}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::configureShader(const engine::Camera& camera) const
{
    engine::actor::ABasicShape::configureShader(camera);
    this->setIntoShader("viewPos", camera.getPosition());

    this->setIntoShader("material.shininess", 32.0F);



    // directional light
    this->setIntoShader("dirLight.direction", camera.getOrientation());
    this->setIntoShader("dirLight.ambient", camera.getParameters().ambient * glm::vec3 { 0 });
    this->setIntoShader("dirLight.diffuse", camera.getParameters().diffuse * glm::vec3 { 0 });
    this->setIntoShader("dirLight.specular", camera.getParameters().specular * glm::vec3 { 0 });

    // point light 1
    this->setIntoShader("pointLights[0].position", lamp->instances[0]);
    this->setIntoShader("pointLights[0].ambient", lamp->getParameters().ambient);
    this->setIntoShader("pointLights[0].diffuse", lamp->getParameters().diffuse);
    this->setIntoShader("pointLights[0].specular", lamp->getParameters().specular);
    this->setIntoShader("pointLights[0].constant", lamp->getParameters().constant);
    this->setIntoShader("pointLights[0].linear", lamp->getParameters().linear);
    this->setIntoShader("pointLights[0].quadratic", lamp->getParameters().quadratic);

    // point light 2
    this->setIntoShader("pointLights[1].position", lamp->instances[1]);
    this->setIntoShader("pointLights[1].ambient", lamp->getParameters().ambient);
    this->setIntoShader("pointLights[1].diffuse", lamp->getParameters().diffuse);
    this->setIntoShader("pointLights[1].specular", lamp->getParameters().specular);
    this->setIntoShader("pointLights[1].constant", lamp->getParameters().constant);
    this->setIntoShader("pointLights[1].linear", lamp->getParameters().linear);
    this->setIntoShader("pointLights[1].quadratic", lamp->getParameters().quadratic);

    // point light 3
    this->setIntoShader("pointLights[2].position", lamp->instances[2]);
    this->setIntoShader("pointLights[2].ambient", lamp->getParameters().ambient);
    this->setIntoShader("pointLights[2].diffuse", lamp->getParameters().diffuse);
    this->setIntoShader("pointLights[2].specular", lamp->getParameters().specular);
    this->setIntoShader("pointLights[2].constant", lamp->getParameters().constant);
    this->setIntoShader("pointLights[2].linear", lamp->getParameters().linear);
    this->setIntoShader("pointLights[2].quadratic", lamp->getParameters().quadratic);

    // point light 4
    this->setIntoShader("pointLights[3].position", lamp->instances[3]);
    this->setIntoShader("pointLights[3].ambient", lamp->getParameters().ambient);
    this->setIntoShader("pointLights[3].diffuse", lamp->getParameters().diffuse);
    this->setIntoShader("pointLights[3].specular", lamp->getParameters().specular);
    this->setIntoShader("pointLights[3].constant", lamp->getParameters().constant);
    this->setIntoShader("pointLights[3].linear", lamp->getParameters().linear);
    this->setIntoShader("pointLights[3].quadratic", lamp->getParameters().quadratic);

    // spotLight
    this->setIntoShader("spotLight.position", camera.getPosition());
    this->setIntoShader("spotLight.direction", camera.getFront());
    this->setIntoShader("spotLight.ambient", lamp->getParameters().ambient);
    this->setIntoShader("spotLight.diffuse", lamp->getParameters().diffuse);
    this->setIntoShader("spotLight.specular", lamp->getParameters().specular);
    this->setIntoShader("spotLight.constant", lamp->getParameters().constant);
    this->setIntoShader("spotLight.linear", lamp->getParameters().linear);
    this->setIntoShader("spotLight.quadratic", lamp->getParameters().quadratic);
    this->setIntoShader("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->setIntoShader("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
}



// ---------------------------------------------------------------------------- Attributes

void EnlightenedCube::setAttributes()
{
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


} // namespace engine::object
