//
// Akanya
// sources/Engine/Graphic/Actors/AControlable
// Allow to controle the Scene
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___

namespace engine::graphic::actor {



class AControlable {

public:

    // ---------------------------------- *structors

    explicit AControlable();

    ~AControlable();



    // ---------------------------------- Copy sementic

    AControlable(
        const AControlable&
    ) noexcept;

    auto operator=(
        const AControlable&
    ) noexcept -> AControlable&;



    // ---------------------------------- Copy sementic

    AControlable(
        AControlable&&
    ) noexcept;

    auto operator=(
        AControlable&&
    ) noexcept -> AControlable&;



public:
protected:
protected:
private:
private:

};



} // namespace engine::graphic::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLE_HPP___
