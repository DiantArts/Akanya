//
// Akanya, Engine
// sources/Objects/Backpack
// basic model backpack
//

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___

#include "Engine/Graphic/Actors/Model.hpp"



namespace game::object {



class Backpack
    : public engine::graphic::actor::Model
{

public:

    // ---------------------------------- *structors

    explicit Backpack(
        const std::string& shaderFilepath,
        const size_t numberOfPositions
    );
    ~Backpack();



    // ---------------------------------- Copy sementic

    Backpack(
        const Backpack&
    ) noexcept;

    auto operator=(
        const Backpack&
    ) noexcept -> Backpack&;



    // ---------------------------------- Move sementic

    Backpack(
        Backpack&&
    ) noexcept;

    auto operator=(
        Backpack&&
    ) noexcept -> Backpack&;


    // ---------------------------------- override

    void configureShader() const override final;



public:
protected:
protected:
private:
private:

};



} // namespace game::object

#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
