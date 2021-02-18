//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Vbo
// Vertex Buffer Object : stores a large number of vertices
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_VBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_VBO_HPP___

namespace engine::graphic::opengl {



class Vbo {
public:
    // ---------------------------------- *structors
    Vbo();
    ~Vbo();



    // ---------------------------------- Copy sementic

    Vbo(
        const Vbo&
    ) noexcept = delete;

    auto operator=(
        const Vbo&
    ) noexcept -> Vbo& = delete;



    // ---------------------------------- Move sementic

    Vbo(
        Vbo&&
    ) noexcept;

    auto operator=(
        Vbo&&
    ) noexcept -> Vbo&;


    // ---------------------------------- get
    GLuint get() const;


    // ---------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_vbo;
};



} // namespace engine::graphic::opengl



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_VBO_HPP___
