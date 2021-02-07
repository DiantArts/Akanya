//
// Akanya, Engine
// sources/Engine/Core/Config/Filepaths
// While waiting config file, filepaths are described here
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___

#include <string>
using std::string_literals::operator""s;



namespace engine::core::config::filepath {



inline const auto textures { "./data/textures/"s };
inline const auto vertices { "./data/vertices/"s };
inline const auto model { "./data/3dModels/"s };



namespace shader {

inline const auto fragments { "./data/shaders/fragments/"s };
inline const auto vertexes { "./data/shaders/vertexes/"s };
inline const auto geometries { "./data/shaders/geometries/"s };

} // namespace shader



} // namespace engine::core::config::filepath

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_CONFIG_FILEPATHS_HPP___
