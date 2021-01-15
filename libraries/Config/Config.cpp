/*
** EPITECH PROJECT, 2020
** Config
** File description:
** file class to help easier config
*/


//#include <boost/dll/runtime_symbol_info.hpp>
#include "Tools/File.hpp"

#include "Config.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> // std::ifstream

namespace config {

Config::Config(std::string path) // = ".config"
    : filepath(path)
{
    //const auto filepath{ boost::dll::program_location().parent_path() / ".config" };
}

void Config::printInfo() const
{
    
    for (const auto& line : this->mapVec) {
        std::cout << "\"" << line.first << "\" = { ";
        for (const auto& elem : line.second) {
            std::cout << "\"" << elem << "\" ";
        }
        std::cout << "}" << std::endl;
    }
}

void Config::loadFile(std::string filename)
{
    if (!filename.empty())
        this->filepath = filename;

    std::ifstream shaderFile { tools::file::openReadFile(this->filepath) };
    std::string line;

    while(std::getline(shaderFile, line)) {
        if (line.empty())
            continue;
        const auto& parts = line | std::ranges::views::split(';');
        std::vector<std::string> vecTmp;

        for (auto const& elem : parts) {
            std::string value;
            for (auto const& e : elem)
                value += e;
            vecTmp.push_back(value);
        }
        const auto str = vecTmp[0];
        vecTmp.erase(vecTmp.begin());
        this->mapVec[str] = vecTmp;
    }
    shaderFile.close();
}

void Config::saveFile(std::string filename,
    std::unordered_map<std::string, std::vector<std::string>> umap)
{
    if (!filename.empty())
        this->filepath = filename;

    auto shaderFile { tools::file::openWriteFile(this->filepath) };

    for (const auto& line : umap) {
        shaderFile << line.first;
        for (const auto& elem : line.second) {
            shaderFile << ";" << elem;
        }
        shaderFile << std::endl;
    }
    shaderFile.close();
}

void Config::saveFile(std::string filename)
{
    if (!filename.empty())
        this->filepath = filename;

    auto shaderFile { tools::file::openWriteFile(this->filepath) };

    for (const auto& line : this->mapVec) {
        shaderFile << line.first;
        for (const auto& elem : line.second) {
            shaderFile << ";" << elem;
        }
        shaderFile << std::endl;
    }
    shaderFile.close();
}

void Config::saveValue(std::string filename, std::string varName, std::vector<std::string> values)
{

}

void Config::loadValue(std::string filename, std::string varName)
{

}



}