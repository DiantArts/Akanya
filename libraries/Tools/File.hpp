/*
** EPITECH PROJECT, 2020
** libraries/Tools/File
** File description:
** file tools to help easier code
*/

#ifndef ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___

#include <string_view>



namespace tools::file {



extern std::string read(std::string_view filepath);
extern std::ifstream openReadFile(std::string_view filepath);
extern std::ofstream openWriteFile(std::string_view filepath);



} // namespace tools::file



#endif // ___INCLUDE_GUARD_LIBRARIES_TOOLS_FILE_HPP___
