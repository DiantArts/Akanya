//
// Akanya, Engine
// sources/Engine/Graphic/Lights/ALight
// Light base class
//

#include "pch.hpp"



namespace engine::graphic::light {



// ---------------------------------- *structors

ALight::ALight(
    std::vector<std::reference_wrapper<ALight>>& lights,
    std::string name
)
    : m_name(std::move(name))
    , m_lights(lights)
{
    m_lights.emplace_back(*this);
}

ALight::~ALight()
{
    std::erase_if(m_lights, [this](const auto& elem) { return &elem.get() == this; });
}



// ---------------------------------- Name

const std::string& ALight::getName() const
{
    return m_name;
}



} // namespace engine::graphic::light
