/*
** EPITECH PROJECT, 2020
** Vertices
** File description:
** coordonate to create a shape
*/

#pragma once

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
