/*
** EPITECH PROJECT, 2020
** Light
** File description:
** Light
*/

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <Engine/Vertexes/Vao.hpp>
#include <glm/vec3.hpp>

namespace engine {

class Light : public engine::Vao {
public:
    Light(const glm::vec3& position, glm::vec3&& color = glm::vec3(0.1f, 0.1f, 0.1f));
    Light(const glm::vec3& position, const glm::vec3& color);
    Light(glm::vec3&& position, glm::vec3&& color = glm::vec3(0.1f, 0.1f, 0.1f));
    Light(glm::vec3&& position, const glm::vec3& color);
    ~Light();

    const glm::vec3& getColor() const;
    const glm::vec3& getPosition() const;

private:
    glm::vec3 m_Position;
    glm::vec3 m_Color;
};

} // namespace engine

#endif // LIGHT_HPP
