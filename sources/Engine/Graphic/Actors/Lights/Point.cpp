/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/Lights/Point
** Light source illuminating in all direction from a point
*/

#include "pch.hpp"

#include "Point.hpp"



namespace engine::graphic::actor::light {



// ---------------------------------- *structors

Point::Point(const std::string& name, const engine::graphic::actor::Positions& positions)
    : ALight(name), m_parameters(positions)
{
    m_nbLight += m_parameters.positions.size();
}

Point::~Point()
{
    m_nbLight -= m_parameters.positions.size();
}



// ---------------------------------- set

void Point::setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const
{
    // shader.set("nrPointLight", m_nbLight);
    // shader.set("nrDirLight", m_nbLight);
    // shader.set("nrSpotLight", m_nbLight);

    size_t baseNameSize { this->getName().size() };
    std::string name;

    if (m_parameters.positions.size() <= 1) {
        shader.set(this->getName() + ".color", m_parameters.color);
        name.reserve(baseNameSize + 12);
        name += this->getName();
        name += '.';
        name += "position";
        shader.set(name, m_parameters.positions[0]);
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
        name.replace(baseNameSize + 1, std::string::npos, "color");
        shader.set(name, m_parameters.color);
    } else {
        size_t i { 0 };
        name.reserve(baseNameSize + 13);
        name += this->getName();
        name += '[';
        for (const auto& position : m_parameters.positions) {
            std::string indexStr { std::to_string(i) };
            name.replace(baseNameSize + 1, std::string::npos, indexStr);
            name.replace(baseNameSize + indexStr.size() + 1, std::string::npos, "].");

            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "position");
            shader.set(name, position);
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
            name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "color");
            shader.set(name, m_parameters.color);
            ++i;
        }
    }
}

void Point::setIntoLightSourceShader(const ::engine::graphic::opengl::Shader&) const
{}



// ---------------------------------- get

size_t Point::getNbLight()
{
    return m_nbLight;
}



} // namespace engine::graphic::actor::light
