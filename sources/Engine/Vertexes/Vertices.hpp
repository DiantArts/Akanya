/*
** EPITECH PROJECT, 2020
** Vertices
** File description:
** coordonate to create a shape
*/

#pragma once



#include <string_view>
#include <vector>



namespace engine {



class Vertices {
public:
    // ---------------------------------------------------------------------------- *structors
    explicit Vertices(const std::string_view filepath);
    ~Vertices() = default;


    // ---------------------------------------------------------------------------- buffer

    void createBuffer();


private:
    std::vector<float> m_Vertices;
};



} // namespace engine
