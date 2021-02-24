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
#include <any>

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

template<typename T>
using OptionalReferenceWrapper = ::std::optional<::std::reference_wrapper<T>>;

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

#include "Engine/Graphic/OpenGL/Vao.hpp"
#include "Engine/Graphic/OpenGL/Vbo.hpp"
#include "Engine/Graphic/OpenGL/Ebo.hpp"
#include "Engine/Graphic/OpenGL/Fbo.hpp"
#include "Engine/Graphic/OpenGL/Ubo.hpp"
#include "Engine/Graphic/OpenGL/Vertices.hpp"
#include "Engine/Graphic/OpenGL/Shader.hpp"
#include "Engine/Physic/Hitbox.hpp"
#include "Engine/Graphic/Actors/Positions.hpp"
#include "Engine/Graphic/Actors/ADrawable.hpp"
#include "Engine/Graphic/Actors/ATransformable.hpp"
#include "Engine/Graphic/Actors/AControlable.hpp"
#include "Engine/Graphic/Actors/AActor.hpp"
#include "Engine/Graphic/Actors/ControlableActor.hpp"
#include "Engine/Core/Config/Filepaths.hpp"
#include "Engine/Core/Events/Type.hpp"
#include "Engine/Core/Events/AEvent.hpp"
#include "Engine/Core/Events/Container.hpp"
#include "Engine/Graphic/Window.hpp"
#include "Engine/Graphic/Camera.hpp"
#include "Engine/Graphic/Lights/ALight.hpp"



#endif // ___INCLUDE_GUARD_INCLUDES_PCH_HPP___
