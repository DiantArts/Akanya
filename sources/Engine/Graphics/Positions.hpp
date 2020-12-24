/*
** EPITECH PROJECT, 2020
** sources/Engine/Graphics/Positions
** File description:
** Positions
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITIONS_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITIONS_HPP___

#include <variant>

#include "Position/Multiple.hpp"
#include "Position/Single.hpp"


namespace engine::graphic {



class Positions : public engine::graphic::position::IPosition {
public:
    // ---------------------------------------------------------------------------- *structors
    Positions(size_t sizeToAlloc);
    ~Positions();


    // ---------------------------------------------------------------------------- override
    engine::graphic::position::Single& operator[](size_t index) override;
    const engine::graphic::position::Single& operator[](size_t index) const override;
    engine::graphic::position::Single* operator->() override;
    const engine::graphic::position::Single* operator->() const override;

    engine::graphic::position::IPosition::iterator begin() override;
    engine::graphic::position::IPosition::const_iterator begin() const override;
    engine::graphic::position::IPosition::const_iterator cbegin() const override;

    engine::graphic::position::IPosition::iterator end() override;
    engine::graphic::position::IPosition::const_iterator end() const override;
    engine::graphic::position::IPosition::const_iterator cend() const override;


    // ---------------------------------------------------------------------------- MultiplePositions
    // Note: Perform an implicit conversion into an engine::graphic::position::Multiple if needed
    void add(float x, float y, float z);
    void add(const glm::vec3& position);
    void add(glm::vec3&& position);
    void add(const engine::graphic::position::Single& position);
    void add(engine::graphic::position::Single&& position);


private:
    std::variant<engine::graphic::position::Single, engine::graphic::position::Multiple> m_Variant;
};



} // engine::graphic



#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHICS_POSITIONS_HPP___
