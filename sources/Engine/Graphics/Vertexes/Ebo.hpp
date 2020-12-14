/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Vertexes/Ebo
** File description:
** ebo
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_EBO_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_EBO_HPP___

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>



namespace engine {



class Ebo {
public:
    // ---------------------------------------------------------------------------- *structors
    Ebo();
    ~Ebo();


    // ---------------------------------------------------------------------------- get
    GLuint get() const;


    // ---------------------------------------------------------------------------- bind
    void bind() const;
    void unbind() const;

private:
    GLuint m_Ebo;
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_VERTEXES_EBO_HPP___
