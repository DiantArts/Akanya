/*
** EPITECH PROJECT, 2020
** Light
** File description:
** Light
*/

#include <utility>
#include "Light.hpp"

namespace engine {

Light::Light(const glm::vec3& position, glm::vec3&& color /* = glm::vec3(1.0f, 1.0f, 1.0f) */)
    : m_Position(position), m_Color(std::move(color))
{}

Light::Light(const glm::vec3& position, const glm::vec3& color)
    :  m_Position(position), m_Color(color)
{}

Light::Light(glm::vec3&& position, glm::vec3&& color /* = glm::vec3(1.0f, 1.0f, 1.0f) */)
    : m_Position(std::move(position)), m_Color(std::move(color))
{}

Light::Light(glm::vec3&& position, const glm::vec3& color)
    :  m_Position(std::move(position)), m_Color(color)
{}

Light::~Light()
{}

const glm::vec3& Light::getColor() const
{
    return this->m_Color;
}

const glm::vec3& Light::getPosition() const
{
    return this->m_Position;
}

} // namespace engine
