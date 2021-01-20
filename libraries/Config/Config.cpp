/*
** EPITECH PROJECT, 2020
** Config
** File description:
** file class to help easier config
*/


//#include <boost/dll/runtime_symbol_info.hpp>
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

void Config::loadFile(const std::string filename)
{
    if (!filename.empty())
        this->filepath = filename;

    std::string line;
    std::ifstream shaderFile(this->filepath);

    if (!shaderFile.is_open()) {
        throw std::runtime_error(std::string("unable to open '") + std::string(this->filepath) + '\'');
    }

    while(std::getline(shaderFile, line)) {
        line = line.substr(0, line.find('#'));
        if (line.empty())
            continue;
        std::vector<std::string> vecTmp;

        for (auto const& elem : line | std::ranges::views::split(';')) {
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

void Config::saveFile(const std::string filename,
    std::unordered_map<std::string, std::vector<std::string>>& umap)
{
    if (!filename.empty())
        this->filepath = filename;

    std::ofstream shaderFile(this->filepath);

    if (!shaderFile.is_open()) {
        throw std::runtime_error(std::string("unable to open '") + std::string(this->filepath) + '\'');
    }

    for (const auto& line : umap) {
        shaderFile << line.first;
        for (const auto& elem : line.second) {
            shaderFile << ";" << elem;
        }
        shaderFile << std::endl;
    }
    shaderFile.close();
}

void Config::saveFile(const std::string filename)
{
    if (!filename.empty())
        this->filepath = filename;

    std::ofstream shaderFile(this->filepath);

    if (!shaderFile.is_open()) {
        throw std::runtime_error(std::string("unable to open '") + std::string(this->filepath) + '\'');
    }

    for (const auto& line : this->mapVec) {
        shaderFile << line.first;
        for (const auto& elem : line.second) {
            shaderFile << ";" << elem;
        }
        shaderFile << std::endl;
    }
    shaderFile.close();
}

void Config::saveValue(std::string, std::string, std::vector<std::string>&)
{

}

void Config::loadValue(std::string, std::string)
{

}



}
