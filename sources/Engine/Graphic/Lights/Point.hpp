//
// Akanya, Engine
// sources/Engine/Graphic/Lights/Point
// Light source illuminating in all direction from a point
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___

namespace engine::graphic::light {



class Point : engine::graphic::ALight {
public:
    // ---------------------------------- *structors
    Point(
        std::vector<std::reference_wrapper<engine::graphic::ALight>>& lights,
        const std::string& name,
        const engine::graphic::actor::Positions& positions
    );

    ~Point();


    // ---------------------------------- set
    void setIntoUbo(
        const ::engine::graphic::opengl::Ubo& ubo,
        int&,
        int& i,
        int&
    ) const override final;

    void setIntoEnlightenedShader(const ::engine::graphic::opengl::Shader& shader) const override final;
    void setIntoLightSourceShader(const ::engine::graphic::opengl::Shader& shader) const override final;


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
    mutable Parameters m_parameters;
};



} // namespace engine::graphic::light



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_LIGHTS_POINT_HPP___
