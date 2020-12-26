/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Default
** File description:
** Default light that needs to be improve somehow
*/

#include "Default.hpp"
#include "Default.hpp"

#include <glm/gtc/matrix_transform.hpp>



namespace engine::light {



// ---------------------------------------------------------------------------- *structors

Default::Default(const light::dynamic::Parameters& parameters) : m_Parameters(parameters)
{}

Default::Default(light::dynamic::Parameters&& parameters) : m_Parameters(std::move(parameters))
{}

Default::~Default()
{}



// ---------------------------------------------------------------------------- Parameters

void Default::setLightParameters(const engine::light::dynamic::Parameters& parameters)
{
    this->m_Parameters = parameters;
}

void Default::setLightParameters(engine::light::dynamic::Parameters&& parameters)
{
    this->m_Parameters = std::move(parameters);
}



void Default::setLightAmbient(const glm::vec3& ambient)
{
    this->m_Parameters.ambient = ambient;
}



void Default::setLightAmbient(glm::vec3&& ambient)
{
    this->m_Parameters.ambient = std::move(ambient);
}

void Default::setLightDiffuse(const glm::vec3& diffuse)
{
    this->m_Parameters.diffuse = diffuse;
}



void Default::setLightDiffuse(glm::vec3&& diffuse)
{
    this->m_Parameters.diffuse = std::move(diffuse);
}

void Default::setLightSpecular(const glm::vec3& specular)
{
    this->m_Parameters.specular = specular;
}



void Default::setLightSpecular(glm::vec3&& specular)
{
    this->m_Parameters.specular = std::move(specular);
}


void Default::setLightConstant(const float constant)
{
    this->m_Parameters.constant = constant;
}

void Default::setLightLinear(const float linear)
{
    this->m_Parameters.linear = linear;
}

void Default::setLightQuadratic(const float quadratic)
{
    this->m_Parameters.quadratic = quadratic;
}



const engine::light::dynamic::Parameters& Default::getParameters() const
{
    return this->m_Parameters;
}


} // namespace engine::light
