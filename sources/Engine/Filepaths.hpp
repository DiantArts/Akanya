/*
** EPITECH PROJECT, 2020
** sources/Engine/Filepaths
** File description:
** While waiting config file, filepaths are described here
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_FILEPATHS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_FILEPATHS_HPP___

#include <string>



namespace engine::filepath {



inline std::string textures { "./data/textures/" };
inline std::string vertices { "./data/vertices/" };
inline std::string model { "./data/3dModels/" };



namespace shader {

inline std::string fragments { "./data/shaders/fragments/" };
inline std::string vertexes { "./data/shaders/vertexes/" };

} // namespace shader



} // namespace engine::filepath



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_FILEPATHS_HPP___
