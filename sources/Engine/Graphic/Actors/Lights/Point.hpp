//
// Akanya, Engine
// sources/Engine/Graphic/Actors/Lights/Point
// Light source illuminating in all direction from a point
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___



namespace engine::graphic::actor::light {



class Point : engine::graphic::actor::ALight {
public:
    // ---------------------------------- *structors
    Point(
        std::vector<std::reference_wrapper<engine::graphic::actor::ALight>>& lights,
        const std::string& name,
        const engine::graphic::actor::Positions& positions
    );

    ~Point();


    // ---------------------------------- set
    void setIntoUbo(const ::engine::graphic::opengl::Ubo& ubo) const override final;
    void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const override final;
    void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const override final;


    // ---------------------------------- get
    static size_t getNbLight();


protected:
    struct Parameters {
        const engine::graphic::actor::Positions& positions;

        glm::vec3 ambient  {  0.1F  };
        glm::vec3 diffuse  {  0.5F  };
        glm::vec3 specular {  1.0F  };
        float constant     {  1.0F  };
        float linear       {  1.0F };
        float quadratic    { 0.064F };

        glm::vec3 color { 1.0F, 1.0F, 1.0F };
    };
    Parameters m_parameters;

    static inline size_t m_nbLight { 0 };
};



} // namespace engine::graphic::actor::light



namespace engine::graphic::actor {

template<typename ActorType>
concept PointLightActorType =
    std::derived_from<ActorType, engine::graphic::AActor> &&
    std::derived_from<ActorType, engine::graphic::actor::light::Point>;

} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___
