/*
** Akanya, Engine
** sources/Engine/Graphic/Actors/ADrawable
** Every class inheriting from this one should be able to be drawn. Must be inheriting with ATransformable
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ADRAWABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ADRAWABLE_HPP___



namespace engine::graphic::actor::light { class ALight; }



namespace engine::graphic::actor {



class ADrawable {

public:

    // ---------------------------------- *structors

    ADrawable(
        ::engine::graphic::opengl::Shader& shader
    );

    virtual ~ADrawable() = 0;



    // ---------------------------------- Draw

    virtual void draw(
        const ::engine::graphic::Window& window,
        const ::engine::graphic::Camera& camera
    ) const;

    virtual void drawModels(
        const ::engine::graphic::Camera& camera
    ) const = 0;



    // ---------------------------------- Shader

    auto getShader() const
        -> const ::engine::graphic::opengl::Shader&;

    void useShader() const;

    virtual void configureShader(
        const ::engine::graphic::Window& window,
        const ::engine::graphic::Camera& camera
    ) const;


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
        this->getShader().set(name, args...);
    }

    template <
        typename... Args
    >
    void setIntoShader(
        std::string&& name,
        const Args&... args
    ) const
    {
        this->getShader().set(std::move(name), args...);
    }

    void setIntoShader(
        const engine::graphic::actor::light::ALight& light
    ) const;


protected:
private:
private:
    const ::engine::graphic::opengl::Shader& m_shader;

    static inline size_t idGiver { 0 };
    const size_t m_id { idGiver++ };

};



} // namespace engine::graphic::actor



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ADRAWABLE_HPP___
