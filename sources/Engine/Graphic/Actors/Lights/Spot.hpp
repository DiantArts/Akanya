//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Lights/Spot
// Light source shooting in a specifique direction
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_SPOT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_SPOT_HPP___



namespace engine::graphic::actor::light {



class Spot : engine::graphic::actor::ALight {
public:
    // ---------------------------------- *structors
    Spot(
        std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>& lights,
        const std::string& name,
        const engine::graphic::actor::Positions& positions,
        glm::vec3 direction
    );

    ~Spot();


    // ---------------------------------- set
    void setIntoUbo(const ::engine::graphic::opengl::Ubo& ubo) const override final;
    void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const override final;
    void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const override final;


    // ---------------------------------- get
    static size_t getNbLight();


private:
    struct Parameters {
        const engine::graphic::actor::Positions& positions;
        glm::vec3 direction;

        glm::vec3 ambient  {   0.5F };
        glm::vec3 diffuse  {   0.3F };
        glm::vec3 specular {   1.0F };
        float constant     {   0.3F };
        float linear       {   0.3F };
        float quadratic    { 0.016F };
        float cutOff       { glm::cos(glm::radians(12.5F)) };
        float outerCutOff  { glm::cos(glm::radians(15.0F)) };

        glm::vec3 color { 1.0F, 1.0F, 1.0F };
    };
    Parameters m_parameters;

    static inline size_t m_nbLight { 0 };
};



} // namespace engine::graphic::actor::light

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_SPOT_HPP___
