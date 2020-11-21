/*
** EPITECH PROJECT, 2020
** LightSourceCube
** File description:
** Light source as cube
*/


#include "LightSourceCube.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "../../../Vertexes/Vertices.hpp"



engine::object3d::single::LightSourceCube& getLamp()
{
    static engine::Shader                            lightSourceshader("lightSource", "lightSource");
    static engine::object3d::single::LightSourceCube lightSource(lightSourceshader,
                                                                 glm::vec3(2.0f, 0.8f, 0.0f));
    return lightSource;
}



namespace engine::object3d::single {



// ---------------------------------------------------------------------------- *structors

LightSourceCube::LightSourceCube(engine::Shader& shader, const glm::vec3& position /* = (0, 0, 0) */)
    : UpdatedCube(shader, position)
{
    this->setScale(0.2, 0.2, 0.2);
}

void LightSourceCube::setAllIntoShader(const engine::Camera&)
{
    this->m_Shader.set("lightColor", 1.0f, 1.0f, 1.0f);
}



// ---------------------------------------------------------------------------- Light

void LightSourceCube::setLightParameters(const engine::LightParameters& parameters)
{
    this->m_LightParameters = parameters;
}

void LightSourceCube::setLightParameters(engine::LightParameters&& parameters)
{
    this->m_LightParameters = std::move(parameters);
}



const engine::LightParameters& LightSourceCube::getLightParameters() const
{
    return this->m_LightParameters;
}

void LightSourceCube::setLightAmbient(const glm::vec3& ambient)
{
    this->m_LightParameters.ambient = ambient;
}



void LightSourceCube::setLightAmbient(glm::vec3&& ambient)
{
    this->m_LightParameters.ambient = std::move(ambient);
}

void LightSourceCube::setLightDiffuse(const glm::vec3& diffuse)
{
    this->m_LightParameters.diffuse = diffuse;
}



void LightSourceCube::setLightDiffuse(glm::vec3&& diffuse)
{
    this->m_LightParameters.diffuse = std::move(diffuse);
}

void LightSourceCube::setLightSpecular(const glm::vec3& specular)
{
    this->m_LightParameters.specular = specular;
}



void LightSourceCube::setLightSpecular(glm::vec3&& specular)
{
    this->m_LightParameters.specular = std::move(specular);
}



} // namespace engine::object3d::single
