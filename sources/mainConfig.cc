/*
** EPITECH PROJECT, 2020
** sources/main
** File description:
** Main of the program, must be simple
*/

#include "Config/Config.hpp"

//g++ sources/mainConfig.cc libraries/Config/Config.cpp libraries/Tools/File.cpp -std=c++20 -I libraries/

int main()
{
    config::Config config;

    config.loadFile(".config");
    config.loadValue(".mdr", "bread");
    config.printInfo();
    
    //config.saveFile(".mdr");
}
