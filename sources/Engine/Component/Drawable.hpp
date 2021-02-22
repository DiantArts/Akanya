//
// Akanya
// sources/Engine/Component/Drawable
// Drawable component
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___

#include "Engine/Graphic/Actors/Texture.hpp"



namespace engine::component {



class Drawable
{

public:

    // ---------------------------------- *structors

    explicit Drawable(
        const std::string& shaderFilepath,
        const std::string& verticesFilename,
        void (&setAttributesFunc)()
    );

    ~Drawable();



    // ---------------------------------- Draw

    void draw(
        const glm::mat4& tranform
    ) const;

    virtual void configureShader() const;



    // ---------------------------------- Texture

    void addTexture(
        const std::string& name,
        const std::string& filepath,
        bool gammaCorrection = false
    );



public:
protected:

    // ---------------------------------- Shader

    template <
        typename... Args
    >
    void setIntoShader(
        const std::string& name,
        const Args&... args
    ) const
    {
        m_shader.set(name, args...);
    }

    template <
        typename... Args
    >
    void setIntoShader(
        std::string&& name,
        const Args&... args
    ) const
    {
        m_shader.set(std::move(name), args...);
    }



protected:
private:
private:

    size_t m_numberOfArrayToDraw;
    ::engine::graphic::opengl::Vao m_vao;
    ::engine::graphic::opengl::Vbo m_vbo;
    ::engine::graphic::opengl::Shader m_shader;

    class Texture : public engine::graphic::actor::Texture {
    public:
        Texture(const std::string& filename, bool gammaCorrection);
    };
    std::vector<Drawable::Texture> m_textureVector;

};



} // namespace engine::component

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_COMPONENT_DRAWABLE_HPP___
