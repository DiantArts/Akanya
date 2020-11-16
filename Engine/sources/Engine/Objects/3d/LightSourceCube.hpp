/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#pragma once

#include <Engine/Shapes/3d/UpdatedCube.hpp>

namespace engine {

struct LightParameters {
    glm::vec3 ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    glm::vec3 diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
};

namespace object3d {

class LightSourceCube : public engine::shape3d::UpdatedCube {
public:
    LightSourceCube(engine::Shader& shaderProgram, const glm::vec3& position = glm::vec3(0, 0, 0));
    ~LightSourceCube();

    void setAllIntoShader(const engine::Camera&) override;

// ---------------------------------------------------------------------------- Light
    void setLightParameters(const engine::LightParameters& parameters);
    void setLightParameters(engine::LightParameters&& parameters);
    void setLightAmbient(const glm::vec3& ambient);
    void setLightAmbient(glm::vec3&& ambient);
    void setLightDiffuse(const glm::vec3& diffuse);
    void setLightDiffuse(glm::vec3&& diffuse);
    void setLightSpecular(const glm::vec3& specular);
    void setLightSpecular(glm::vec3&& specular);

    const engine::LightParameters& getLightParameters() const;

private:
    LightParameters m_LightParameters;
};

} // namespace object3d
} // namespace engine
