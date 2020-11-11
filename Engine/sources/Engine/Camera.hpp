/*
** EPITECH PROJECT, 2020
** Camera
** File description:
** Camera
*/

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace engine {

class Camera {
public:
    Camera(const float speed = 0.1);
    ~Camera();

// ---------------------------------------------------------------------------- movement
    void adjustLocalSpeed(const float deltaTime);
    void moveForward(const float deltaTime);
    void moveBackward(const float deltaTime);
    void moveLeft(const float deltaTime);
    void moveRight(const float deltaTime);

// ---------------------------------------------------------------------------- view
    glm::mat4 getView() const;

public:
    float speed;

private:
    glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 m_Front = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 m_Up = glm::vec3(0.0f, 1.0f,  0.0f);

    float m_LocalSpeed; // speed taking in count deltaTime

    // glm::vec3 m_Target;
    // glm::vec3 m_ReversedDirection;
};

} // namespace engine

#endif // CAMERA_HPP
