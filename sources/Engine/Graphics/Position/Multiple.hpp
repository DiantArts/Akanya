/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Position/Multiple
** File description:
** multiple
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___

#include <vector>

#include "../Position/Single.hpp"



namespace engine::graphic::position {



class Multiple : public engine::graphic::position::IPosition {
public:
    // ---------------------------------------------------------------------------- *structors
    Multiple(const size_t sizeToAlloc);
    ~Multiple();


    // ---------------------------------------------------------------------------- addPositions
    void add(float x, float y, float z);
    void add(const glm::vec3& position);
    void add(glm::vec3&& position);
    void add(const engine::graphic::position::Single& position);
    void add(engine::graphic::position::Single&& position);


    // ---------------------------------------------------------------------------- std::vector
    size_t size() const;

    // ---------------------------------------------------------------------------- Iterator
    engine::graphic::position::Single& operator[](size_t index) override;
    const engine::graphic::position::Single& operator[](size_t index) const override;
    engine::graphic::position::Single* operator->() override;
    const engine::graphic::position::Single* operator->() const override;

    iterator begin() override;
    const_iterator begin() const override;
    const_iterator cbegin() const override;

    iterator end() override;
    const_iterator end() const override;
    const_iterator cend() const override;


private:
    std::vector<engine::graphic::position::Single> m_VectorPositions;
};



} // namespace engine::graphic::position



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITION_MULTIPLE_HPP___
