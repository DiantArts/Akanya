/*
** EPITECH PROJECT, 2020
** includes/pch
** File description:
** g++ -x c++-header pch.hpp -I../externs/
*/

#ifndef ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
#define ___INCLUDE_GUARD_INCLUDES_PCH_HPP___


#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <ranges>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_map>
#include <variant>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/mat2x2.hpp>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <stb/stb_image.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "debugMacros.hpp"
#include "optimizationBuiltins.hpp"

#include "Tools/File.hpp"
#include "Tools/FuncAlias.hpp"
#include "Tools/Iterator.hpp"
#include "Tools/String.hpp"

#include "Engine/Filepaths.hpp"
#include "Engine/Window.hpp"
#include "Engine/Actors/Vertexes/Vao.hpp"
#include "Engine/Actors/Vertexes/Vbo.hpp"
#include "Engine/Actors/Vertexes/Ebo.hpp"
#include "Engine/Actors/Vertexes/Fbo.hpp"
#include "Engine/Clock.hpp"
#include "Engine/Shader.hpp"



#endif // ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
