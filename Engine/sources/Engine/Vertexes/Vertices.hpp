/*
** EPITECH PROJECT, 2020
** Vertices
** File description:
** coordonate to create a shape
*/

#ifndef VERTICES_HPP
#define VERTICES_HPP

#include <vector>
#include <string_view>

namespace engine {

class Vertices {
public:
    Vertices(const std::string_view filepath);
    ~Vertices();

    void createBuffer();

public:
    constexpr static auto directoryPath = "./data/vertices/";

private:
    std::vector<float> m_Vertices;
};

} // namespace engine

#endif // VERTICES_HPP
