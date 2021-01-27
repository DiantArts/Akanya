/*
** Akanya, Engine
** sources/Engine/Actors/Vertexes/Vao
** Vertex Array Object: Contains vertex attributes pointers to get a simple use of VBOs
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___

namespace engine::graphic::opengl {



class Vao {
public:
    // ---------------------------------- *structors
    Vao();
    ~Vao();



    // ---------------------------------- Copy sementic

    Vao(
        const Vao&
    ) noexcept = delete;

    auto operator=(
        const Vao&
    ) noexcept -> Vao& = delete;



    // ---------------------------------- Move sementic

    Vao(
        Vao&&
    ) noexcept;

    auto operator=(
        Vao&&
    ) noexcept -> Vao&;


    // ---------------------------------- get
    GLuint get() const;


    // ---------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_vao;
};



} // namespace engine::graphic::opengl



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_ACTORS_VERTEXES_VAO_HPP___
