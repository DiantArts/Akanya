/*
** EPITECH PROJECT, 2020
** EnlightenedCube
** File description:
** Light source as cube
*/

#include "EnlightenedCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Vertexes/Vertices.hpp"



// clang-format off

#include "LightSourceCube.hpp" // tmp
extern engine::object3d::multiple::LightSourceCube* lamp;

// clang-format on



namespace engine::object3d::multiple {



// ---------------------------------------------------------------------------- *structors

EnlightenedCube::EnlightenedCube(engine::Shader& shader)
    : Cube(shader, true, EnlightenedCube::setAttributes, "lightningMap")
{}



// ---------------------------------------------------------------------------- override

void EnlightenedCube::transformShape(const engine::Camera& camera) const
{
    engine::graphic::shape3d::Basic::transformShape(camera);
    this->set("viewPos", camera.getPosition());

    this->set("material.shininess", 32.0F);



    auto pointLightPositions { lamp->getPositions() };

    // directional light
    this->set("dirLight.direction", camera.getOrientation());
    this->set("dirLight.ambient", camera.getParameters().ambient * glm::vec3 { 0 });
    this->set("dirLight.diffuse", camera.getParameters().diffuse * glm::vec3 { 0 });
    this->set("dirLight.specular", camera.getParameters().specular * glm::vec3 { 0 });

    // point light 1
    this->set("pointLights[0].position", pointLightPositions[0]);
    this->set("pointLights[0].ambient", lamp->getParameters().ambient);
    this->set("pointLights[0].diffuse", lamp->getParameters().diffuse);
    this->set("pointLights[0].specular", lamp->getParameters().specular);
    this->set("pointLights[0].constant", lamp->getParameters().constant);
    this->set("pointLights[0].linear", lamp->getParameters().linear);
    this->set("pointLights[0].quadratic", lamp->getParameters().quadratic);

    // point light 2
    this->set("pointLights[1].position", pointLightPositions[1]);
    this->set("pointLights[1].ambient", lamp->getParameters().ambient);
    this->set("pointLights[1].diffuse", lamp->getParameters().diffuse);
    this->set("pointLights[1].specular", lamp->getParameters().specular);
    this->set("pointLights[1].constant", lamp->getParameters().constant);
    this->set("pointLights[1].linear", lamp->getParameters().linear);
    this->set("pointLights[1].quadratic", lamp->getParameters().quadratic);

    // point light 3
    this->set("pointLights[2].position", pointLightPositions[2]);
    this->set("pointLights[2].ambient", lamp->getParameters().ambient);
    this->set("pointLights[2].diffuse", lamp->getParameters().diffuse);
    this->set("pointLights[2].specular", lamp->getParameters().specular);
    this->set("pointLights[2].constant", lamp->getParameters().constant);
    this->set("pointLights[2].linear", lamp->getParameters().linear);
    this->set("pointLights[2].quadratic", lamp->getParameters().quadratic);

    // point light 4
    this->set("pointLights[3].position", pointLightPositions[3]);
    this->set("pointLights[3].ambient", lamp->getParameters().ambient);
    this->set("pointLights[3].diffuse", lamp->getParameters().diffuse);
    this->set("pointLights[3].specular", lamp->getParameters().specular);
    this->set("pointLights[3].constant", lamp->getParameters().constant);
    this->set("pointLights[3].linear", lamp->getParameters().linear);
    this->set("pointLights[3].quadratic", lamp->getParameters().quadratic);

    // spotLight
    this->set("spotLight.position", camera.getPosition());
    this->set("spotLight.direction", camera.getFront());
    this->set("spotLight.ambient", lamp->getParameters().ambient);
    this->set("spotLight.diffuse", lamp->getParameters().diffuse);
    this->set("spotLight.specular", lamp->getParameters().specular);
    this->set("spotLight.constant", lamp->getParameters().constant);
    this->set("spotLight.linear", lamp->getParameters().linear);
    this->set("spotLight.quadratic", lamp->getParameters().quadratic);
    this->set("spotLight.cutOff", glm::cos(glm::radians(12.5F)));
    this->set("spotLight.outerCutOff", glm::cos(glm::radians(15.0F)));
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


} // namespace engine::object3d::multiple
