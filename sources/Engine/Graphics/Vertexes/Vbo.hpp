/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Vertexes/Vbo
** File description:
** vbo
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VBO_HPP___

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>



namespace engine {



class Vbo {
public:
    // ---------------------------------------------------------------------------- *structors
    Vbo();
    ~Vbo();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Vbo;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_VBO_HPP___
