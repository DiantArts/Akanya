/*
** Akanya, Engine
** sources/Objects/Backpack
** basic model backpack
*/

#ifndef ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
#define ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___

#include "Engine/Graphic/Actors/Model.hpp"



namespace game::object {



class Backpack : public engine::graphic::actor::Model {
public:
    // ---------------------------------- *structors
    explicit Backpack(::engine::graphic::opengl::Shader& shader, const size_t numberOfPositions);
    ~Backpack();


    // ---------------------------------- override
    void configureShader(const ::engine::graphic::Window& window) const override final;


private:
};



} // namespace game::object

#endif // ___INCLUDE_GUARD_SOURCES_OBJECTS_BACKPACK_HPP___
