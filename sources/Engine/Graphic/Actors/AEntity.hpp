//
// Akanya
// sources/Engine/Graphic/Actors/AEntity
// Actor controlable
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AENTITY_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AENTITY_HPP___

namespace engine::graphic::actor {



class AEntity
    : public ::engine::graphic::AActor
    , public ::engine::graphic::actor::AControlable
{

public:

    // ---------------------------------- *structors

    explicit AEntity(
        const std::string& shaderFilepath,
        size_t numberOfPositions
    );

    ~AEntity();



    // ---------------------------------- Copy sementic

    AEntity(
        const AEntity&
    ) noexcept = delete;

    auto operator=(
        const AEntity&
    ) noexcept -> AEntity& = delete;



    // ---------------------------------- Copy sementic

    AEntity(
        AEntity&&
    ) noexcept = delete;

    auto operator=(
        AEntity&&
    ) noexcept -> AEntity& = delete;



public:
protected:
protected:
private:
private:

};



} // namespace engine::graphic::actor

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AENTITY_HPP___
