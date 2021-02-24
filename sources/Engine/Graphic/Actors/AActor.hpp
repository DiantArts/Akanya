//
// Akanya, Engine
// sources/Engine/Graphic/Actors/AActor
// An actor is a drawable and a transformable
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___

namespace engine::graphic::actor {



class AActor
    : public engine::graphic::actor::ADrawable
    , public engine::graphic::actor::ATransformable
{

public:

    // ---------------------------------- *structors

    AActor(
        const std::string& shaderFilepath,
        size_t numberOfPositions
    );

    virtual ~AActor() = 0;



    // ---------------------------------- Copy sementic

    AActor(
        const AActor&
    ) noexcept = delete;

    auto operator=(
        const AActor&
    ) noexcept -> AActor& = delete;



    // ---------------------------------- Move sementic

    AActor(
        AActor&&
    ) noexcept = delete;

    auto operator=(
        AActor&&
    ) noexcept -> AActor& = delete;



    // ---------------------------------- ADrawable

    // just apply transform model
    auto getModel(
        const glm::vec3& position
    ) const
        -> glm::mat4;

    // ADrawable method
    virtual void drawModels() const = 0;



    // ---------------------------------- Transformable

    // = default
    virtual void update(
        float deltaTime
    );



    // ---------------------------------- Hitbox



public:
protected:
protected:
private:
private:

    ::engine::physic::Hitbox m_hitbox;

};



} // namespace engine::graphic::actor



namespace engine::graphic { using AActor = engine::graphic::actor::AActor; }

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_AACTOR_HPP___
