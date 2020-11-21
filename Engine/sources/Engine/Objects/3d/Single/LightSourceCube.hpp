/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/

#pragma once



#include "../../../Shapes/3d/Single/UpdatedCube.hpp"



namespace engine {



struct LightParameters {
    glm::vec3 ambient { 0.2f, 0.2f, 0.2f };
    glm::vec3 diffuse { 0.5f, 0.5f, 0.5f };
    glm::vec3 specular { 1.0f, 1.0f, 1.0f };
};



namespace object3d::single {



class LightSourceCube : public engine::shape3d::single::UpdatedCube {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit LightSourceCube(engine::Shader& shaderProgram, const glm::vec3& position = glm::vec3(0, 0, 0));
    ~LightSourceCube() = default;


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



} // namespace object3d::single
} // namespace engine
