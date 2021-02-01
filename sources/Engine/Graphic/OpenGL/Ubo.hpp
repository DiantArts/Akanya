//
// Akanya, Engine
// sources/Engine/Graphic/OpenGL/Ubo
// Uniform Buffer Object : Share memory with multiple shaders
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_UBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_UBO_HPP___

namespace engine::graphic::opengl {



class Ubo {

public:

    // ---------------------------------- *structors

    Ubo(
        size_t size,
        int index
    );
    ~Ubo();



    // ---------------------------------- Copy sementic

    Ubo(
        const Ubo&
    ) noexcept = delete;

    auto operator=(
        const Ubo&
    ) noexcept -> Ubo& = delete;



    // ---------------------------------- Move sementic

    Ubo(
        Ubo&&
    ) noexcept;

    auto operator=(
        Ubo&&
    ) noexcept -> Ubo&;



    // ---------------------------------- get

    GLuint get() const;



    // ---------------------------------- bind

    void bind() const;
    void unbind() const;



    // ---------------------------------- SubData


    template <
        typename DataType
    > void setOneSubData(
        GLintptr offset,
        DataType& dataptr
    ) const
    {
        this->bind();
        this->setSubData(offset, dataptr);
        this->unbind();
    }

    template <
        typename DataType
    > void setOneSubData(
        GLintptr offset,
        DataType&& dataptr
    ) const
    {
        this->bind();
        this->setSubData(offset, dataptr);
        this->unbind();
    }



    template <
        typename DataType
    > void setSubData(
        GLintptr offset,
        DataType& dataptr
    ) const
    {
        glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(dataptr), &dataptr);
    }

    template <
        typename DataType
    > void setSubData(
        GLintptr offset,
        DataType&& dataptr
    ) const
    {
        glBufferSubData(GL_UNIFORM_BUFFER, offset, sizeof(dataptr), &dataptr);
    }



private:
    GLuint m_ubo;

};



} // namespace engine::graphic::opengl



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_OPENGL_UBO_HPP___
