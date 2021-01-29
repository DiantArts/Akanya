//
// Akanya, Engine
// sources/Engine/Core/Config/Filepaths
// While waiting config file, filepaths are described here
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___

#include <string_view>
using std::literals::string_view_literals::operator""sv;



namespace engine::core::config::filepath {



inline auto textures { "./data/textures/"sv };
inline auto vertices { "./data/vertices/"sv };
inline auto model { "./data/3dModels/"sv };



namespace shader {

inline auto fragments { "./data/shaders/fragments/"sv };
inline auto vertexes { "./data/shaders/vertexes/"sv };
inline auto geometries { "./data/shaders/geometries/"sv };

} // namespace shader



} // namespace engine::core::config::filepath

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___
