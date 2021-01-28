/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/Lights/ALight
** Light base class
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___

#include "../../Shadows.hpp"



namespace engine { class Shader; }



namespace engine::graphic::actor::light {



class ALight {
public:
    // ---------------------------------- *structors
    explicit ALight(std::string name);
    virtual ~ALight() = 0;


    ALight(const ALight&) = delete;
    ALight(ALight&&) = delete;

    ALight& operator=(const ALight&) = delete;
    ALight& operator=(ALight&&) = delete;

    // ---------------------------------- static
    static const std::vector<std::reference_wrapper<ALight>>& getAll();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator begin();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator cbegin();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator end();
    static std::vector<std::reference_wrapper<ALight>>::const_iterator cend();


    // ---------------------------------- Others
    virtual void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const = 0;
    virtual void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const = 0;
    const std::string& getName() const;

private:
    std::string m_name;
};



} // namespace engine::graphic::actor::light

namespace engine::graphic::actor { using ALight = engine::graphic::actor::light::ALight; }



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___