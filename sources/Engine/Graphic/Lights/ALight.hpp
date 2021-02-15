//
// Akanya, Engine
// sources/Engine/Graphic/Lights/ALight
// Light base class
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___

namespace engine::graphic::light {



class ALight {

public:

    // ---------------------------------- *structors

    explicit ALight(
        std::vector<std::reference_wrapper<ALight>>& lights,
        std::string name
    );

    virtual ~ALight() = 0;


    ALight(const ALight&) = delete;
    ALight(ALight&&) = delete;

    ALight& operator=(const ALight&) = delete;
    ALight& operator=(ALight&&) = delete;


    // ---------------------------------- Name

    virtual void setIntoUbo(
        const ::engine::graphic::opengl::Ubo& ubo,
        int& iDirectionalLight,
        int& iPointLight,
        int& iSpotLight
    ) const = 0;

    virtual void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const = 0;
    virtual void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const = 0;



    // ---------------------------------- Shader

    const std::string& getName() const;

private:

    std::string m_name;

    std::vector<std::reference_wrapper<ALight>>& m_lights;

};



} // namespace engine::graphic::light



namespace engine::graphic { using ALight = engine::graphic::light::ALight; }

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_ALIGHT_HPP___
