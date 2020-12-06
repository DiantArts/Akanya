/*
** EPITECH PROJECT, 2020
** Filepaths
** File description:
** filepaths are fun
*/

#pragma once

#include <string>



namespace engine::filepath {



inline std::string textures { "./data/textures/" };
inline std::string vertices { "./data/vertices/" };



namespace shader {

inline std::string fragments { "./data/shaders/fragments/" };
inline std::string vertexes { "./data/shaders/vertexes/" };

} // namespace shader



} // namespace engine::filepath
