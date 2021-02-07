//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Lights/Directional
// Light source comming from infinitly far away
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_DIRECTIONAL_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_DIRECTIONAL_HPP___



namespace engine::graphic::actor::light {



class Directional : public engine::graphic::actor::ALight {
public:
    // ---------------------------------- *structors
    Directional(
        std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>& lights,
        const std::string& name,
        glm::vec3 direction
    );

    ~Directional();


    // ---------------------------------- set
    void setIntoUbo(
        const ::engine::graphic::opengl::Ubo& ubo,
        int& i,
        int&,
        int&
    ) const override final;

    void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const override final;
    void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const override final;


    // ---------------------------------- get
    static size_t getNbLight();



private:
    struct Parameters {
        glm::vec3 direction;

        glm::vec3 ambient  { 0.5F };
        glm::vec3 diffuse  { 0.3F };
        glm::vec3 specular { 1.0F };

        glm::vec3 color { 1.0F, 1.0F, 1.0F };
    };
    Parameters m_parameters;

    static inline size_t m_nbLight { 0 };
};



} // namespace engine::graphic::actor::light



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_DIRECTIONAL_HPP___
