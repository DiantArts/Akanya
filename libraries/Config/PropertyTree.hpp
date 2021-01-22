/*
** EPITECH PROJECT, 2020
** libraries/Config/PropertyTree
** File description:
** use PropertyTree boost's lib
*/

#ifndef ___INCLUDE_GUARD_LIBRARIES_CONFIG_PROPERTY_TREE_HPP___
#define ___INCLUDE_GUARD_LIBRARIES_CONFIG_PROPERTY_TREE_HPP___

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <map>
#include <iostream>

// Short alias for this namespace
namespace pt = boost::property_tree;




namespace config {

class PropertyTree {
public:
    PropertyTree();
    ~PropertyTree() = default;

//  PATTERN : varName;value1;value2

    template <typename T>
    T get(const std::string path)
    {
        T var;
        return this->readValue(path, var);
    };

    //std::string& readValue(const std::string path, std::string& single);
    std::vector<std::string>& readValue(const std::string path, std::vector<std::string>& fruits);
    std::vector< std::vector<std::string> >& readValue(const std::string path, std::vector< std::vector<std::string> >& matrix);
    std::map<std::string, std::string>& readValue(const std::string path, std::map<std::string, std::string>& animals);
    std::map<std::string, std::vector<std::string> >& readValue(const std::string path, std::map<std::string, std::vector<std::string> >& namedMatrix);
    template <typename T>
    T readValue(const std::string path, T single)
    {
        return this->root.get<T>(path);
    };
    void saveFile();
    
    void addValue(const std::string path, const std::string& single);
    void addValue(const std::string path, const std::vector<std::string>& fruits);
    void addValue(const std::string path, const std::vector< std::vector<std::string> >& matrix);
    void addValue(const std::string path, const std::map<std::string, std::string>& animals);
    void addValue(const std::string path, const std::map<std::string, std::vector<std::string> >& namedMatrix);
    
    /*
    - operator<< // file << varName << value1 << value2 ...
    //*/
private:
//------------------------ info config
    // Create a root
    pt::ptree root;

};


} // config

#endif // ___INCLUDE_GUARD_LIBRARIES_CONFIG_PROPERTY_TREE_HPP___
