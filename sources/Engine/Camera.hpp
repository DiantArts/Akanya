/*
** EPITECH PROJECT, 2020
** sources/Engine/Camera
** File description:
** Camera
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___

#define GLFW_INCLUDE_NONE
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Graphics/Light/Dynamic/Default.hpp"



namespace engine {



class Camera : public engine::light::dynamic::Default {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Camera() = default;
    ~Camera()         = default;


    // ---------------------------------------------------------------------------- speed
    void adjustLocalSpeed(const float deltaTime);

    void setSpeed(const float value);

    float getSpeed() const;


    // ---------------------------------------------------------------------------- move
    void move(const float xOffset, const float yOffset, const float zOffset);
    void move(const glm::vec3& offset);

    void moveForward(const float deltaTime);
    void moveBackward(const float deltaTime);

    void moveLeft(const float deltaTime);
    void moveRight(const float deltaTime);

    void moveTop(const float deltaTime);
    void moveBot(const float deltaTime);


    // ---------------------------------------------------------------------------- Position
    void setPosition(const float xOffset, const float yOffset, const float zOffset);
    void setPosition(const glm::vec3& offset);

    const glm::vec3& getPosition() const;


    // ---------------------------------------------------------------------------- Orientation
    void oriente(const float xOffset, const float yOffset);
    void oriente(const glm::vec2& offset);

    void setOrientation(const float xOffset, const float yOffset);
    void setOrientation(const glm::vec2& offset);

    void adjustOrientation();

    const glm::vec3& getOrientation() const;
    const glm::vec3& getFront() const;


    // ---------------------------------------------------------------------------- Zoom
    void  zoom(const float value);
    void  setZoom(const float value);
    float getZoom() const;


    // ---------------------------------------------------------------------------- view
    glm::mat4 getView() const;

public:
    // ---------------------------------------------------------------------------- mouse config
    static constexpr float minPitch = -89.999F;
    static constexpr float maxPitch = 89.999F;
    static constexpr float minZoom  = 1.0F;
    static constexpr float maxZoom  = 45.0F;


private:
    float     m_Speed { 2.5F };
    float     m_Zoom { 45.0F };
    glm::vec3 m_Sensitivity { 0.1F, 0.1F, 1.0F };

    glm::vec3 m_Position { 0.0F, 0.0F, 3.0F };
    glm::vec3 m_Front { 0.0F, 0.0F, -1.0F };
    glm::vec3 m_Up { 0.0F, 1.0F, 0.0F };

    glm::vec3 m_ReversedDirection { 0.5F, 0.5F, 0.5F };
    float     m_Yaw { -90.0F };
    float     m_Pitch { 0.0F };

    float m_Velocity; // speed taking in count deltaTime
};



} // namespace engine



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CAMERA_HPP___
