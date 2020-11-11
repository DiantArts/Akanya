/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** vaos
*/

#ifndef VAO_HPP
#define VAO_HPP

#include <GLFW/glfw3.h>

namespace engine {

class Vao {
public:
    Vao();
    ~Vao();

    GLuint get() const;

    void bind();
    void unbind();

private:
    GLuint m_Vao;
};

} // namespace engine

#endif // VAO_HPP
