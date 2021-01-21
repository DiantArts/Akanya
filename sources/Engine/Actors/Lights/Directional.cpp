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
{
    ++m_NbLight;
}

Directional::~Directional()
{
    --m_NbLight;
}



// ---------------------------------------------------------------------------- set

void Directional::setIntoEnlightenedShader(const engine::Shader& shader) const
{
    size_t baseNameSize { this->getName().size() };
    std::string name;

    shader.set(this->getName() + ".color", m_Parameters.color);
    name.reserve(baseNameSize + 12);
    name += this->getName();
    name += '.';
    name += "direction";
    shader.set(name, m_Parameters.direction);
    name.replace(baseNameSize + 1, std::string::npos, "ambient");
    shader.set(name, m_Parameters.ambient);
    name.replace(baseNameSize + 1, std::string::npos, "diffuse");
    shader.set(name, m_Parameters.diffuse);
    name.replace(baseNameSize + 1, std::string::npos, "specular");
    shader.set(name, m_Parameters.specular);
    name.replace(baseNameSize + 1, std::string::npos, "color");
    shader.set(name, m_Parameters.color);
}

void Directional::setIntoLightSourceShader(const engine::Shader&) const
{}



// ---------------------------------------------------------------------------- get

size_t Directional::getNbLight()
{
    return m_NbLight;
}



} // namespace engine::actor::light
