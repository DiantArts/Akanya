//
// Akanya, Engine
// sources/Engine/Graphic/Lights/Directional
// Light source comming from infinitly far away
//

#include "pch.hpp"
#include "Directional.hpp"



namespace engine::graphic::light {



// ---------------------------------- *structors

Directional::Directional(
    std::vector<std::reference_wrapper<engine::graphic::ALight>>& lights,
    const std::string& name,
    glm::vec3 direction
)
    : ALight(lights, name), m_parameters(std::move(direction))
{
    ++m_nbLight;
}

Directional::~Directional()
{
    --m_nbLight;
}



// ---------------------------------- set

void Directional::setIntoUbo(
    const ::engine::graphic::opengl::Ubo&,
    int&,
    int&,
    int&
) const
{}

void Directional::setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const
{
    size_t baseNameSize { this->getName().size() };
    std::string name;

    shader.set(this->getName() + ".color", m_parameters.color);
    name.reserve(baseNameSize + 12);
    name += this->getName();
    name += '.';
    name += "direction";
    shader.set(name, m_parameters.direction);
    name.replace(baseNameSize + 1, std::string::npos, "ambient");
    shader.set(name, m_parameters.ambient);
    name.replace(baseNameSize + 1, std::string::npos, "diffuse");
    shader.set(name, m_parameters.diffuse);
    name.replace(baseNameSize + 1, std::string::npos, "specular");
    shader.set(name, m_parameters.specular);
    name.replace(baseNameSize + 1, std::string::npos, "color");
    shader.set(name, m_parameters.color);
}

void Directional::setIntoLightSourceShader(const ::engine::graphic::opengl::Shader&) const
{}



// ---------------------------------- get

size_t Directional::getNbLight()
{
    return m_nbLight;
}



} // namespace engine::graphic::light
