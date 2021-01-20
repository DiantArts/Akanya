/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Directional
** File description:
** Light source comming from infinitly far away
*/

#include "Directional.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

Directional::Directional(const std::string& name, glm::vec3 direction)
    : ALight(name), m_Parameters(direction)
{}

Directional::~Directional()
{}



// ---------------------------------------------------------------------------- set
void Directional::setIntoThisShader(const engine::Shader& shader) const
{
    shader.set(this->getName() + ".direction", m_Parameters.direction);
    shader.set(this->getName() + ".ambient", m_Parameters.ambient);
    shader.set(this->getName() + ".diffuse", m_Parameters.diffuse);
    shader.set(this->getName() + ".specular", m_Parameters.specular);
}



} // namespace engine::actor::light
