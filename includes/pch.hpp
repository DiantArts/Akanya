//
// Akanya, Engine
// includes/pch
// g++ -x c++-header -Wpedantic -Wall -Wextra -Wno-volatile -Wno-address -Wno-nonnull-compare -std=c++20 -Ofast -pipe -o includes/pch.hpp.gch -Iincludes -Isources -Ilibraries -Iexterns includes/pch.hpp
//

#ifndef ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
#define ___INCLUDE_GUARD_INCLUDES_PCH_HPP___



#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <ranges>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <variant>
#include <thread>
#include <utility>
#include <concepts>
#include <bitset>

#include "optimizationBuiltins.hpp"

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


using std::string_literals::operator""s;
using std::literals::string_view_literals::operator""sv;

#define BIT_SHIFT(x) (1 << x)

#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))



#include "nbLights.hpp"

constexpr auto sizeofLightType { 2 * 4 };
// constexpr auto sizeofDirectionalLightTab { MAX_NB_DIRECTIONAL_LIGHT * (5 * 16) };
constexpr auto sizeofPointLightTab { MAX_NB_POINT_LIGHT * ((5 * 16) + (4 * 4)) };
// constexpr auto sizeofPointLightTab { MAX_NB_POINT_LIGHT * ((2 * 16) + (0 * 4)) };
// constexpr auto sizeofSpotLightTab { MAX_NB_SPOT_LIGHT * ((6 * 16) + (5 * 4)) };



#include "Tools/File.hpp"
#include "Tools/FuncAlias.hpp"
#include "Tools/Iterator.hpp"
#include "Tools/String.hpp"

#include "Engine/Core/Config/Filepaths.hpp"
#include "Engine/Graphic/Window.hpp"
#include "Engine/Graphic/Camera.hpp"
#include "Engine/Graphic/OpenGL/Shader.hpp"
#include "Engine/Graphic/Lights/ALight.hpp"
#include "Engine/Graphic/Actors/AActor.hpp"
#include "Engine/Graphic/OpenGL/Vao.hpp"
#include "Engine/Graphic/OpenGL/Vbo.hpp"
#include "Engine/Graphic/OpenGL/Ebo.hpp"
#include "Engine/Graphic/OpenGL/Fbo.hpp"
#include "Engine/Graphic/OpenGL/Ubo.hpp"
#include "Engine/Graphic/OpenGL/Vertices.hpp"



#endif // ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
