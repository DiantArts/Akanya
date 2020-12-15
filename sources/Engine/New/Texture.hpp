/*
** EPITECH PROJECT, 2020
** sources/Engine/New/Texture
** File description:
** Texture
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_TEXTURE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_TEXTURE_HPP___

#include <string>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>



namespace engine {



struct Texture {
    GLuint      id;
    std::string type;
    std::string filepath;
};



} // namespace engine

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_NEW_TEXTURE_HPP___
