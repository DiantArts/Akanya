/*
** Akanya, Engine
** sources/Engine/Actors/Lights/Spot
** Light source shooting in a specifique direction
*/

#include "pch.hpp"

#include "Spot.hpp"



namespace engine::graphic::actor::light {



// ---------------------------------- *structors

Spot::Spot(const std::string& name, const engine::graphic::actor::Positions& positions, glm::vec3 direction)
    : ALight(name), m_parameters(positions, direction)
{
    m_nbLight += m_parameters.positions.size();
}

Spot::~Spot()
{
    m_nbLight -= m_parameters.positions.size();
}



// ---------------------------------- set

void Spot::setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const
{
    size_t baseNameSize { this->getName().size() };
    std::string name;

    if (m_parameters.positions.size() == 1) {
        name.reserve(baseNameSize + 12);
        name += this->getName();
        name += '.';
        name += "position";
        shader.set(name, m_parameters.positions[0]);
        name.replace(baseNameSize + 1, std::string::npos, "direction");
        shader.set(name, m_parameters.direction);
        name.replace(baseNameSize + 1, std::string::npos, "ambient");
        shader.set(name, m_parameters.ambient);
        name.replace(baseNameSize + 1, std::string::npos, "diffuse");
        shader.set(name, m_parameters.diffuse);
        name.replace(baseNameSize + 1, std::string::npos, "specular");
        shader.set(name, m_parameters.specular);
        name.replace(baseNameSize + 1, std::string::npos, "constant");
        shader.set(name, m_parameters.constant);
        name.replace(baseNameSize + 1, std::string::npos, "linear");
        shader.set(name, m_parameters.linear);
        name.replace(baseNameSize + 1, std::string::npos, "quadratic");
        shader.set(name, m_parameters.quadratic);
        name.replace(baseNameSize + 1, std::string::npos, "cutOff");
        shader.set(name, m_parameters.cutOff);
        name.replace(baseNameSize + 1, std::string::npos, "outerCutOff");
        shader.set(name, m_parameters.outerCutOff);
        name.replace(baseNameSize + 1, std::string::npos, "color");
        shader.set(name, m_parameters.color);
    } else {
        size_t i { 0 };
        name.reserve(baseNameSize + 16);
        name += this->getName();
        name += '[';
        for (const auto& position : m_parameters.positions) {
            std::string indexStr { std::to_string(i) };
            name.replace(baseNameSize + 1, std::string::npos, indexStr);
            name.replace(baseNameSize + indexStr.size() + 1, std::string::npos, "].");

            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "position");
            shader.set(name, position);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "direction");
            shader.set(name, m_parameters.direction);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "ambient");
            shader.set(name, m_parameters.ambient);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "diffuse");
            shader.set(name, m_parameters.diffuse);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "specular");
            shader.set(name, m_parameters.specular);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "constant");
            shader.set(name, m_parameters.constant);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "linear");
            shader.set(name, m_parameters.linear);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "quadratic");
            shader.set(name, m_parameters.quadratic);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "cutOff");
            shader.set(name, m_parameters.cutOff);
            name.replace(baseNameSize + indexStr.size() + 3,std::string::npos,  "outerCutOff");
            shader.set(name, m_parameters.outerCutOff);
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "color");
            shader.set(name, m_parameters.color);
            ++i;
        }
    }
}

void Spot::setIntoLightSourceShader(const ::engine::graphic::opengl::Shader&) const
{}



// ---------------------------------- get

size_t Spot::getNbLight()
{
    return m_nbLight;
}



} // namespace engine::graphic::actor::light
