/*
** EPITECH PROJECT, 2020
** Color
** File description:
** Color
*/

#ifndef COLOR_HPP
#define COLOR_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Color {
public:
    Color();
    ~Color();

private:
    glm::vec3 m_Color;
};

#endif // COLOR_HPP
