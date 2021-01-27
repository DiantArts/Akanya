/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Spot
** File description:
** Light source shooting in a specifique direction
*/

#include "Spot.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

Spot::Spot(const std::string& name, const engine::actor::Positions& positions, glm::vec3 direction)
    : ALight(name), m_Parameters(positions, direction)
{
    m_NbLight += m_Parameters.positions.size();
}

Spot::~Spot()
{
    m_NbLight -= m_Parameters.positions.size();
}



// ---------------------------------------------------------------------------- set

void Spot::setIntoEnlightenedShader(const engine::Shader& shader) const
{
    size_t baseNameSize { this->getName().size() };
    std::string name;

    if (m_Parameters.positions.size() == 1) {
        name.reserve(baseNameSize + 12);
        name += this->getName();
        name += '.';
        name += "position";
        shader.set(name, m_Parameters.positions[0]);
        name.replace(baseNameSize + 1, std::string::npos, "direction");
        shader.set(name, m_Parameters.direction);
        name.replace(baseNameSize + 1, std::string::npos, "ambient");
        shader.set(name, m_Parameters.ambient);
        name.replace(baseNameSize + 1, std::string::npos, "diffuse");
        shader.set(name, m_Parameters.diffuse);
        name.replace(baseNameSize + 1, std::string::npos, "specular");
        shader.set(name, m_Parameters.specular);
        name.replace(baseNameSize + 1, std::string::npos, "constant");
        shader.set(name, m_Parameters.constant);
        name.replace(baseNameSize + 1, std::string::npos, "linear");
        shader.set(name, m_Parameters.linear);
        name.replace(baseNameSize + 1, std::string::npos, "quadratic");
        shader.set(name, m_Parameters.quadratic);
        name.replace(baseNameSize + 1, std::string::npos, "cutOff");
        shader.set(name, m_Parameters.cutOff);
        name.replace(baseNameSize + 1, std::string::npos, "outerCutOff");
        shader.set(name, m_Parameters.outerCutOff);
        name.replace(baseNameSize + 1, std::string::npos, "color");
        shader.set(name, m_Parameters.color);
    } else {
        size_t i { 0 };
        name.reserve(baseNameSize + 16);
        name += this->getName();
        name += '[';
        for (const auto& position : m_Parameters.positions) {
            std::string indexStr { std::to_string(i) };
            name.replace(baseNameSize + 1, std::string::npos, indexStr);
            name.replace(baseNameSize + indexStr.size() + 1, std::string::npos, "].");

            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "position");
            shader.set(name, position);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "direction");
            shader.set(name, m_Parameters.direction);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "ambient");
            shader.set(name, m_Parameters.ambient);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "diffuse");
            shader.set(name, m_Parameters.diffuse);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "specular");
            shader.set(name, m_Parameters.specular);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "constant");
            shader.set(name, m_Parameters.constant);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "linear");
            shader.set(name, m_Parameters.linear);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "quadratic");
            shader.set(name, m_Parameters.quadratic);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "cutOff");
            shader.set(name, m_Parameters.cutOff);
            name.replace(baseNameSize + indexStr.size() + 3,std::string::npos,  "outerCutOff");
            shader.set(name, m_Parameters.outerCutOff);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "color");
            shader.set(name, m_Parameters.color);
            ++i;
        }
    }
}

void Spot::setIntoLightSourceShader(const engine::Shader&) const
{}



// ---------------------------------------------------------------------------- get

size_t Spot::getNbLight()
{
    return m_NbLight;
}



} // namespace engine::actor::light
