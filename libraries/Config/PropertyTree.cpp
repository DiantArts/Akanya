/*
** EPITECH PROJECT, 2020
** libraries/Config/PropertyTree
** File description:
** use boost propertyTree lib
*/

#include "PropertyTree.hpp"

namespace config {

PropertyTree::PropertyTree()
{
    // Load the json file in this ptree
    pt::read_json(".config.json", this->root);

}

void PropertyTree::saveFile()
{
    pt::write_json(".config.json", this->root);
}


void PropertyTree::readValue(const std::string path, std::string& single)
{
    single = this->root.get<std::string>(path);
}

void PropertyTree::readValue(const std::string path, std::vector<std::string>& fruits)
{
    for (pt::ptree::value_type &fruit : this->root.get_child(path))
    {
        // fruit.first contain the string ""
        fruits.push_back(fruit.second.get_value<std::string>());
    }
}

void PropertyTree::readValue(const std::string path, std::vector< std::vector<std::string> >& matrix)
{
    int x = 0;
    for (pt::ptree::value_type &row : this->root.get_child(path))
    {
        int y = 0;
        for (pt::ptree::value_type &cell : row.second)
        {
            matrix[x][y] = cell.second.get_value<std::string>();
            y++;
        }
        x++;
    }
}

void PropertyTree::readValue(const std::string path, std::vector< std::pair<std::string, std::string> >& animals)
{
    // A vector to allow storing our animals

    // Iterator over all animals
    for (pt::ptree::value_type &animal : this->root.get_child(path))
    {
        // Get the label of the node
        std::string name = animal.first;
        // Get the content of the node
        std::string color = animal.second.get_value<std::string>();
        animals.push_back(std::make_pair(name, color));
    }
}

void PropertyTree::addValue(const std::string path, const std::string& first, const std::string& second)
{
    pt::ptree fish1;
    fish1.put_value("blue");

    pt::ptree fish2;
    fish2.put_value("yellow");

    this->root.push_back(std::make_pair("fish", fish1));
    this->root.push_back(std::make_pair("fish", fish2));
}

void PropertyTree::addValue(const std::string path, const std::string& single)
{
    this->root.put(path, single);
}

void PropertyTree::addValue(const std::string path, const std::vector<std::string>& fruits)
{
    pt::ptree fruits_node;
    for (auto &fruit : fruits)
    {
        // Create an unnamed node containing the value
        pt::ptree fruit_node;
        fruit_node.put("", fruit);

        // Add this node to the list.
        fruits_node.push_back(std::make_pair("", fruit_node));
    }
    root.put_child(path, fruits_node);
}

void PropertyTree::addValue(const std::string path, const std::vector< std::vector<std::string> >& matrix)
{
    pt::ptree matrix_node;
    auto sizeI = matrix.size();
    for (int i = 0; i < sizeI; i++)
    {
        pt::ptree row;
        auto sizeJ = matrix[i].size();
        for (int j = 0; j < sizeJ; j++)
        {
            // Create an unnamed value
            pt::ptree cell;
            cell.put_value(matrix[i][j]);
            // Add the value to our row
            row.push_back(std::make_pair("", cell));
        }
        // Add the row to our matrix
        matrix_node.push_back(std::make_pair("", row));
    }
    // Add the node to the this->root
    this->root.put_child(path, matrix_node);
}

void PropertyTree::addValue(const std::string path,
    const std::vector< std::pair<std::string, std::string> >& animals)
{
    pt::ptree animals_node;
    // Add animals as childs
    for (auto &animal : animals)
        animals_node.put(animal.first, animal.second);
    // Add the new node to the this->root
    this->root.put_child(path, animals_node);
}



} // config
