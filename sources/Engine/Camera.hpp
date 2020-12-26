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

#include "Actors/Lights/Default.hpp"



namespace engine {



class Camera : public engine::light::Default {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Camera() = default;
    ~Camera()         = default;


    // ---------------------------------------------------------------------------- speed
    void adjustLocalSpeed(float deltaTime);

    void setSpeed(float value);

    float getSpeed() const;


    // ---------------------------------------------------------------------------- move
    void move(float xOffset, float yOffset, float zOffset);
    void move(const glm::vec3& offset);

    void moveForward(float deltaTime);
    void moveBackward(float deltaTime);

    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);

    void moveTop(float deltaTime);
    void moveBot(float deltaTime);


    // ---------------------------------------------------------------------------- Position
    void setPosition(float xOffset, float yOffset, float zOffset);
    void setPosition(const glm::vec3& offset);

    const glm::vec3& getPosition() const;


    // ---------------------------------------------------------------------------- Orientation
    void oriente(float xOffset, float yOffset);
    void oriente(const glm::vec2& offset);

    void setOrientation(float xOffset, float yOffset);
    void setOrientation(const glm::vec2& offset);

    void adjustOrientation();

    const glm::vec3& getOrientation() const;
    const glm::vec3& getFront() const;


    // ---------------------------------------------------------------------------- Zoom
    void  zoom(float value);
    void  setZoom(float value);
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
