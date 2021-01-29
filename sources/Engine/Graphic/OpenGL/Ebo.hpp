//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Ebo
// Element Buffer Object: help to determine which vertex to draw
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_EBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_EBO_HPP___



namespace engine::graphic::opengl {



class Ebo {
public:
    // ---------------------------------- *structors
    Ebo();
    ~Ebo();



    // ---------------------------------- Copy sementic

    Ebo(
        const Ebo&
    ) noexcept = delete;

    auto operator=(
        const Ebo&
    ) noexcept -> Ebo& = delete;



    // ---------------------------------- Move sementic

    Ebo(
        Ebo&&
    ) noexcept;

    auto operator=(
        Ebo&&
    ) noexcept -> Ebo&;


    // ---------------------------------- get
    GLuint get() const;


    // ---------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_ebo;
};



} // namespace engine::graphic::opengl



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_VERTEXES_EBO_HPP___
