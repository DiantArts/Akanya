/*
** EPITECH PROJECT, 2020
** Camera
** File description:
** Camera
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace engine {

class Camera {
public:
    Camera();
    ~Camera();

// ---------------------------------------------------------------------------- movement
    void adjustLocalSpeed(const float deltaTime);
    void moveForward(const float deltaTime);
    void moveBackward(const float deltaTime);
    void moveLeft(const float deltaTime);
    void moveRight(const float deltaTime);

// ---------------------------------------------------------------------------- mouse events
    void adjustDirection(float xPos, float yPos);
    void adjustZoom(float offset);

// ---------------------------------------------------------------------------- view
    glm::mat4 getView() const;

public:
// ---------------------------------------------------------------------------- mouse config
    static float speed;
    static float zoom;

    static glm::vec3 sensitivity;

    constexpr static float minPitch = -89.999f;
    constexpr static float maxPitch = 89.999f;
    constexpr static float minZoom = 1.0f;
    constexpr static float maxZoom = 45.0f;

private:
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

#endif // CAMERA_HPP
