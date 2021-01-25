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
    PropertyTree(const std::string& filepath);
    ~PropertyTree() = default;

    void loadFile(const std::string& filepath);

    void saveFile();
    void saveFile(const std::string& filepath);


//  PATTERN : varName;value1;value2
public:
    template <typename T>
    T& get(const std::string& path)
    {
        T var;
        try {
            return this->readValue(path, var);
        } catch (const boost::wrapexcept<boost::property_tree::ptree_bad_path>& e) {
            throw std::runtime_error(std::string("While get node '") + path +
                                     std::string("' (") + e.what() + ')');
        }
    };

private:
    std::vector<std::string>&                         readValue(const std::string& path, std::vector<std::string>& fruits);
    std::vector< std::vector<std::string> >&          readValue(const std::string& path, std::vector< std::vector<std::string> >& matrix);
    std::map<std::string, std::string>&               readValue(const std::string& path, std::map<std::string, std::string>& animals);
    std::map<std::string, std::vector<std::string> >& readValue(const std::string& path, std::map<std::string, std::vector<std::string> >& namedMatrix);
    template <typename T>
    T& readValue(const std::string& path, T& single)
    {
        return this->root.get<T>(path);
    };

public:
    template <typename T>
    void add(const std::string& path, const T& value)
    {
        try {
            this->addValue(path, value);
            return;
        } catch (const boost::wrapexcept<boost::property_tree::ptree_bad_path>& e) {
            throw std::runtime_error(std::string("While add node '") + path +
                                     std::string("' (") + e.what() + ')');
        }
    };

private:
    void addValue(const std::string& path, const std::vector<std::string>& fruits);
    void addValue(const std::string& path, const std::vector< std::vector<std::string> >& matrix);
    void addValue(const std::string& path, const std::map<std::string, std::string>& animals);
    void addValue(const std::string& path, const std::map<std::string, std::vector<std::string> >& namedMatrix);
    
    template <typename T>
    void addValue(const std::string& path, const T& single)
    {
        this->root.put(path, single);
    };

private:
//------------------------ info config
    // Create a root
    pt::ptree root;
    std::string filepath;

};


} // config

#endif // ___INCLUDE_GUARD_LIBRARIES_CONFIG_PROPERTY_TREE_HPP___
