/*
** EPITECH PROJECT, 2020
** sources/main
** File description:
** Main of the program, must be simple
*/

#include "Config/Config.hpp"
#include "Config/PropertyTree.hpp"
#include <iostream>

//g++ sources/mainConfig.cc libraries/Config/Config.cpp libraries/Tools/File.cpp -std=c++20 -I libraries/

int main()
{
    config::PropertyTree config;

    std::string b = "matrix";
    
    auto  c =  config.get< std::vector<std::vector<std::string>> >(b);
    for (const auto& elems : c)
        for (const auto& elem : elems)
            std::cout << elem <<std::endl;
    /*
    config.readValue("some.complex.path", b);
    b += " guys";
    config.addValue("some.complex.path", b);
    std::cout << b << std::endl;

    std::map<std::string, std::vector<std::string> > vecb;

    config.readValue("namedMatrix", vecb);
    //config.addValue("animals.rabbit", "not white");
    for (auto &row : vecb) {
            std::cout << row.first << ": ";
        for (auto &cell : row.second) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    config.addValue("namedMatrix", vecb);
    


    config.saveFile();//*/
    return 0;
}
