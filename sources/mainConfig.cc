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

    std::string b;

    config.readValue("some.complex.path", b);
    b += " guys";
    config.addValue("some.complex.path", b);
    std::cout << b << std::endl;

    std::vector<std::pair<std::string, std::string> > vecb;

    //config.readValue("animals", vecb);
    config.addValue("animals.rabbit", "not white");
    //config.addValue("animals", vecb);
    


    config.saveFile();
    return 0;
}
