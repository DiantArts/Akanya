/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Vertexes/Vao
** File description:
** vao
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VAO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VAO_HPP___

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace engine {



class Vao {
public:
    // ---------------------------------------------------------------------------- *structors
    Vao();
    ~Vao();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Vao;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VAO_HPP___
