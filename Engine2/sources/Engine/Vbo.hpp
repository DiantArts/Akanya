/*
** EPITECH PROJECT, 2020
** Vbo
** File description:
** Vbo
*/

#ifndef VBO_HPP
#define VBO_HPP

#include <GLFW/glfw3.h>

namespace engine {

class Vbo {
public:
    Vbo(size_t size);
    ~Vbo();

    GLuint get();
    void bind(GLenum target);

private:
    GLuint m_Vbo;
};

} // namespace engine

#endif // VBO_HPP
