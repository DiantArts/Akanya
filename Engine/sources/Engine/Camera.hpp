/*
** EPITECH PROJECT, 2020
** Camera
** File description:
** Camera
*/

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace engine {

class Camera {
public:
    Camera();
    ~Camera();

// ---------------------------------------------------------------------------- movement
    void adjustLocalSpeed(const float deltaTime);
    void setSpeed(const float value);
    float getSpeed() const;

    void move(const float xOffset, const float yOffset, const float zOffset);
    void move(const glm::vec3& offset);
    void setPosition(const float xOffset, const float yOffset, const float zOffset);
    void setPosition(const glm::vec3& offset);
    const glm::vec3& getPosition() const;

    void moveForward(const float deltaTime);
    void moveBackward(const float deltaTime);
    void moveLeft(const float deltaTime);
    void moveRight(const float deltaTime);
    void moveTop(const float deltaTime);
    void moveBot(const float deltaTime);

// ---------------------------------------------------------------------------- Orientation
    void oriente(const float xOffset, const float yOffset);
    void oriente(const glm::vec2& offset);
    void setOrientation(const float xOffset, const float yOffset);
    void setOrientation(const glm::vec2& offset);
    glm::vec3 getOrientation() const;

    void adjustDirection();

// ---------------------------------------------------------------------------- Orientation
    void zoom(const float value);
    void setZoom(const float value);
    float getZoom() const;

// ---------------------------------------------------------------------------- view
    glm::mat4 getView() const;

public:
// ---------------------------------------------------------------------------- mouse config
    constexpr static float minPitch = -89.999f;
    constexpr static float maxPitch = 89.999f;
    constexpr static float minZoom = 1.0f;
    constexpr static float maxZoom = 45.0f;

private:
    float m_Speed = 2.5f;
    float m_Zoom = 45.0f;
    glm::vec3 m_Sensitivity = glm::vec3{0.1f, 0.1f, 1.0f};

    glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_Up = glm::vec3(0.0f, 1.0f,  0.0f);

    glm::vec3 m_ReversedDirection = glm::vec3(0.5f, 0.5f, 0.5f);
    float m_Yaw = -90.0f;
    float m_Pitch = 00.0f;

    glm::vec3 m_Target;

    float m_Velocity; // speed taking in count deltaTime
};

} // namespace engine
