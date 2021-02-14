//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Lights/Point
// Light source illuminating in all direction from a point
//

#include "pch.hpp"

#include "Point.hpp"



namespace engine::graphic::actor::light {



// ---------------------------------- *structors

Point::Point(
    std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>& lights,
    const std::string& name,
    const engine::graphic::actor::Positions& positions
)
    : ALight(lights, name), m_parameters(positions)
{}

Point::~Point()
{}



// ---------------------------------- set

void Point::setIntoUbo(
    const ::engine::graphic::opengl::Ubo& ubo,
    int&,
    int& i,
    int&
) const
{
    size_t offset { (1 * sizeof(glm::vec4)) + (size_t)i * ((5 * sizeof(glm::vec4)) + (4 * sizeof(float))) };

    for (auto position : m_parameters.positions) {
        ubo.setSubData(offset, glm::vec4(position, 0));
        offset += 16;
        ubo.setSubData(offset, glm::vec4(m_parameters.ambient, 0));
        offset += 16;
        ubo.setSubData(offset, glm::vec4(m_parameters.diffuse, 0));
        offset += 16;
        ubo.setSubData(offset, glm::vec4(m_parameters.specular, 0));
        offset += 16;
        ubo.setSubData(offset, glm::vec4(m_parameters.color, 0));
        offset += 16;
        ubo.setSubData(offset, m_parameters.constant);
        offset += 4;
        ubo.setSubData(offset, m_parameters.linear);
        offset += 4;
        ubo.setSubData(offset, m_parameters.quadratic);
        offset += 4;
        offset += 4; // float alignment
        i++;
    }

}

void Point::setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const
{
    size_t baseNameSize { this->getName().size() };
    std::string name;

    size_t i { 0 };
    name.reserve(baseNameSize + 13);
    name += this->getName();
    name += '[';
    for (const auto& position : m_parameters.positions) {
        std::string indexStr { std::to_string(i) };
        name.replace(baseNameSize + 1, std::string::npos, indexStr);
        name.replace(baseNameSize + indexStr.size() + 1, std::string::npos, "].");

        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "position");
        shader.set(name, glm::vec4(position, 0));
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "constant");
        shader.set(name, m_parameters.constant);
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "linear");
        shader.set(name, m_parameters.linear);
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "quadratic");
        shader.set(name, m_parameters.quadratic);
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "ambient");
        shader.set(name, glm::vec4(m_parameters.ambient, 0));
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "diffuse");
        shader.set(name, glm::vec4(m_parameters.diffuse, 0));
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "specular");
        shader.set(name, glm::vec4(m_parameters.specular, 0));
        name.replace(baseNameSize + indexStr.size() + 3, std::string::npos, "color");
        shader.set(name, glm::vec4(m_parameters.color, 0));

        ++i;
    }
}

void Point::setIntoLightSourceShader(const ::engine::graphic::opengl::Shader&) const
{}



} // namespace engine::graphic::actor::light
