/*
** EPITECH PROJECT, 2020
** Vao
** File description:
** vaos
*/

#ifndef VAO_HPP
#define VAO_HPP

#include <GLFW/glfw3.h>

namespace DiEngine {

class Vao {
public:
    Vao() noexcept;
    ~Vao() noexcept;

    GLuint get() const noexcept;

    void bind() noexcept;
    void unbind() noexcept;

private:
    GLuint m_vao;
};

} // namespace DiEngine

#endif // VAO_HPP
