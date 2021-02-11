/*
** EPITECH PROJECT, 2020
** sources/main
** File description:
** Main of the program, must be simple
*/

//g++ -o test_config tests/testConfig.cpp libraries/Config/PropertyTree.cpp -std=c++20 -I libraries/ -Wall -Wextra && ./test_config --log_level=unit_scope

#define BOOST_TEST_MODULE boost_test_config_lib
#include <boost/test/included/unit_test.hpp>

#include "Config/PropertyTree.hpp"

BOOST_AUTO_TEST_CASE( test_int )
{
    try {
        config::PropertyTree config(".config.json");
        auto res = config.get<int>("height");

        int value = 320;

        BOOST_TEST(res == value);
    } catch (...) {
        BOOST_TEST(false);
    }
}

BOOST_AUTO_TEST_CASE( test_string_path )
{
    try {
        config::PropertyTree config(".config.json");
        auto res = config.get<std::string>("some.complex.path");

        std::string str = "hello";

        BOOST_TEST(res == str);
    } catch (...) {
        BOOST_TEST(false);
    }
}

BOOST_AUTO_TEST_CASE( test_vectors )
{
    try {
        config::PropertyTree config(".config.json");
        auto res = config.get<std::vector<std::string>>("fruits");

        std::vector<std::string> vecTest = {"apple", "raspberry", "orange"};

        BOOST_TEST(res == vecTest);
    } catch (...) {
        BOOST_TEST(false);
    }
}

BOOST_AUTO_TEST_CASE( test_maps )
{
    try {
        config::PropertyTree config(".config.json");
        auto res = config.getFilepaths();

        std::map<std::string, std::string> mapFilepathTest;
        mapFilepathTest["textures"]  = "./data/textures/";
        mapFilepathTest["vertices"]  = "./data/vertices/";
        mapFilepathTest["model"]  = "./data/3dModels/";
        mapFilepathTest["fragments"]  = "./data/shaders/fragments/";
        mapFilepathTest["vertexes"]  = "./data/shaders/vertexes/";
        mapFilepathTest["geometries"]  = "./data/shaders/geometries/";

        BOOST_TEST(res == mapFilepathTest);
    } catch (...) {
        BOOST_TEST(false);
    }
}



BOOST_AUTO_TEST_CASE( test_vectors_vectors )
{
    try {
        config::PropertyTree config(".config.json");
        auto res = config.get<std::vector<std::vector<std::string>>>("matrix");

        std::vector<std::vector<std::string>> vecVecTest;
        vecVecTest.push_back({"1", "2", "3"});
        vecVecTest.push_back({"4", "5", "6"});
        vecVecTest.push_back({"7", "8", "9"});

        BOOST_TEST(res == vecVecTest);
    } catch (...) {
        BOOST_TEST(false);
    }
}
