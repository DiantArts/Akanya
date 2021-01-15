/*
** EPITECH PROJECT, 2020
** libraries/Config/Config
** File description:
** file class to help easier config
*/
#ifndef ___INCLUDE_GUARD_LIBRARIES_CONFIG_CONFIG_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_CONFIG_CONFIG_HPP___


#include <vector>
#include <unordered_map>
#include <string_view>
#include <string>
#include <ranges>

namespace config {

class Config {
public:
    Config(std::string path = ".config");
    ~Config() = default;

//  PATTERN : varName;value1;value2

    void loadFile(std::string filename = "");
    void saveFile(std::string filename = "");
    void saveFile(std::string filename, std::unordered_map<std::string, std::vector<std::string>> umap);

    void saveValue(std::string filename, std::string varName, std::vector<std::string> values);
    void loadValue(std::string filename, std::string varName);
    /*
    - operator<< // file << varName << value1 << value2 ...
    //*/
    void printInfo() const;

private:
//------------------------ info config
    std::string_view filepath;
    std::unordered_map<std::string, std::vector<std::string>> mapVec;

//    std::vector<std::vector<std::string>> vec;

};


} // config

#endif // ___INCLUDE_GUARD_LIBRARIES_CONFIG_CONFIG_HPP___
