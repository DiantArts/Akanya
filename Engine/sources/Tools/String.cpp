/*
** EPITECH PROJECT, 2020
** File
** File description:
** file tools to help easier code
*/

#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <sstream>  // std::stringstream
#include "File.hpp" // std::string_view

#include <iostream>

namespace tools::string {

bool endsWith(const std::string_view a, const std::string_view b)
{
    return std::equal(a.begin() + a.size() - b.size(), a.end(), b.begin());
}

} // namespace tools::string
