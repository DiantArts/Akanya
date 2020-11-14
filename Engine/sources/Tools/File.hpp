/*
** EPITECH PROJECT, 2020
** File
** File description:
** file tools to help easier code
*/

#ifndef FILE_HPP
#define FILE_HPP

#include <string_view>

namespace tools::file {

extern std::string read(const std::string_view filepath);
extern std::string read(const std::string& filepath);
extern std::string read(const std::string&& filepath);

} // namespace tools::file

#endif // FILE_HPP