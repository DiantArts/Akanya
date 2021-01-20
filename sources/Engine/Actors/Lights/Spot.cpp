/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Spot
** File description:
** Light source shooting in a specifique direction
*/

#include "Spot.hpp"
#include <iostream>



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

Spot::Spot(const std::string& name, const engine::actor::Positions& positions, glm::vec3 direction)
    : ALight(name), m_Parameters(positions, direction)
{}

Spot::~Spot()
{}



// ---------------------------------------------------------------------------- set
void Spot::setIntoThisShader(const engine::Shader& shader) const
{
    if (m_Parameters.positions.size() == 1) {
        shader.set(this->getName() + ".position", m_Parameters.positions[0]);
        shader.set(this->getName() + ".direction", m_Parameters.direction);
        shader.set(this->getName() + ".ambient", m_Parameters.ambient);
        shader.set(this->getName() + ".diffuse", m_Parameters.diffuse);
        shader.set(this->getName() + ".specular", m_Parameters.specular);
        shader.set(this->getName() + ".constant", m_Parameters.constant);
        shader.set(this->getName() + ".linear", m_Parameters.linear);
        shader.set(this->getName() + ".quadratic", m_Parameters.quadratic);
        shader.set(this->getName() + ".cutOff", m_Parameters.cutOff);
        shader.set(this->getName() + ".outerCutOff", m_Parameters.outerCutOff);
    } else {
        size_t i { 0 };
        size_t baseNameSize { this->getName().size() };
        std::string name;
        name.reserve(baseNameSize + 13);
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
            ++i;
        }
    }
}



} // namespace engine::actor::light
