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

/*
std::string& 
    PropertyTree::readValue(const std::string path, std::string& single)
{
    single = this->root.get<std::string>(path);
    return single;
}//*/

std::vector<std::string>& 
    PropertyTree::readValue(const std::string path, std::vector<std::string>& fruits)
{
    for (pt::ptree::value_type &fruit : this->root.get_child(path))
    {
        // fruit.first contain the string ""
        fruits.push_back(fruit.second.get_value<std::string>());
    }
    return fruits;
}

std::vector< std::vector<std::string> >& 
    PropertyTree::readValue(const std::string path, std::vector< std::vector<std::string> >& matrix)
{
    matrix.reserve(10);
    for (int x = 0; pt::ptree::value_type &row : this->root.get_child(path)) {
        std::vector<std::string> cube;
        for (int y = 0; pt::ptree::value_type &cell : row.second) {
            cube.push_back(cell.second.get_value<std::string>());
            y++;
        }
        matrix.push_back(cube);
        x++;
    }
    return matrix;
}

std::map<std::string, std::string>& 
    PropertyTree::readValue(const std::string path, std::map<std::string, std::string>& animals)
{
    // A vector to allow storing our animals

    // Iterator over all animals
    for (pt::ptree::value_type &animal : this->root.get_child(path)) {
        // Get the label of the node
        std::string name = animal.first;
        // Get the content of the node
        std::string color = animal.second.get_value<std::string>();
        animals[name] = color;
    }
    return animals;
}

std::map<std::string, std::vector<std::string> >& 
    PropertyTree::readValue(const std::string path, std::map<std::string, std::vector<std::string> >& namedMatrix)
{
    // Iterator over all namedMatrix
    for (pt::ptree::value_type &row : this->root.get_child(path))
    {
        // Get the label of the node
        std::string name = row.first;

        std::string childPath(path + ".");
        childPath += name;
        // Get the content of the node
        for (pt::ptree::value_type &fruit : this->root.get_child(childPath)) {
            namedMatrix[name].push_back(fruit.second.get_value<std::string>());
        }
    }
    return namedMatrix;
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
    this->root.put_child(path, fruits_node);
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
    // Add the node to this->root
    this->root.put_child(path, matrix_node);
}

void PropertyTree::addValue(const std::string path,
    const std::map<std::string, std::string>& animals)
{
    pt::ptree animals_node;
    // Add animals as childs
    for (auto &animal : animals)
        animals_node.put(animal.first, animal.second);
    // Add the new node to this->root
    this->root.put_child(path, animals_node);
}

void PropertyTree::addValue(const std::string path,
    const std::map<std::string, std::vector<std::string> >& namedMatrix)
{
    pt::ptree animals_node;

    for (auto &row : namedMatrix) {
        pt::ptree cells_node;
        for (auto &cell : row.second)
        {
            // Create an unnamed node containing the value
            pt::ptree cell_node;
            cell_node.put("", cell);

            // Add this node to the list.
            cells_node.push_back(std::make_pair("", cell_node));
        }
        animals_node.put_child(row.first, cells_node);
    }
    // Add the new node to this->root
    this->root.put_child(path, animals_node);
}


} // config
