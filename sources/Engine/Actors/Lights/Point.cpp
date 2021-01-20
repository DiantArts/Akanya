/*
** EPITECH PROJECT, 2020
** sources/Engine/Actors/Lights/Point
** File description:
** Light source illuminating in all direction from a point
*/

#include "Point.hpp"



namespace engine::actor::light {



// ---------------------------------------------------------------------------- *structors

Point::Point(const std::string& name, const engine::actor::Positions& positions)
    : ALight(name), m_Parameters(positions)
{}

Point::~Point()
{}



// ---------------------------------------------------------------------------- set
void Point::setIntoThisShader(const engine::Shader& shader) const
{
    if (m_Parameters.positions.size() == 1) {
        shader.set(this->getName() + ".position", m_Parameters.positions[0]);
        shader.set(this->getName() + ".ambient", m_Parameters.ambient);
        shader.set(this->getName() + ".diffuse", m_Parameters.diffuse);
        shader.set(this->getName() + ".specular", m_Parameters.specular);
        shader.set(this->getName() + ".constant", m_Parameters.constant);
        shader.set(this->getName() + ".linear", m_Parameters.linear);
        shader.set(this->getName() + ".quadratic", m_Parameters.quadratic);
    } else {
        size_t i { 0 };
        size_t baseNameSize { this->getName().size() };
        std::string name;
        name.reserve(baseNameSize + 13);
        name += this->getName();
        name += '[';
        for (const auto& position : m_Parameters.positions) {
            std::string indexStr { std::to_string(i) };
            name.insert(baseNameSize + 1, indexStr);
            name.insert(baseNameSize + indexStr.size() + 1, "].");

            name.insert(baseNameSize + indexStr.size() + 3, "position");
            shader.set(name, position);
            name.insert(baseNameSize + indexStr.size() + 3, "ambient");
            shader.set(name, m_Parameters.ambient);
            name.insert(baseNameSize + indexStr.size() + 3, "diffuse");
            shader.set(name, m_Parameters.diffuse);
            name.insert(baseNameSize + indexStr.size() + 3, "specular");
            shader.set(name, m_Parameters.specular);
            name.insert(baseNameSize + indexStr.size() + 3, "constant");
            shader.set(name, m_Parameters.constant);
            name.insert(baseNameSize + indexStr.size() + 3, "linear");
            shader.set(name, m_Parameters.linear);
            name.insert(baseNameSize + indexStr.size() + 3, "quadratic");
            shader.set(name, m_Parameters.quadratic);
        }
    }
}



} // namespace engine::actor::light
