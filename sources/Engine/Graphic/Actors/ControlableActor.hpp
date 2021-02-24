//
// Akanya
// sources/Engine/Graphic/Actors/ControlableActor
// Allow actor to be controlable
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLEACTOR_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLEACTOR_HPP___

namespace engine::graphic::actor {



class ControlableActor
{

public:

    // ---------------------------------- *structors

    explicit ControlableActor();

    virtual ~ControlableActor();



    // ---------------------------------- Copy sementic

    ControlableActor(
        const ControlableActor&
    ) noexcept = delete;

    auto operator=(
        const ControlableActor&
    ) noexcept -> ControlableActor& = delete;



    // ---------------------------------- Copy sementic

    ControlableActor(
        ControlableActor&&
    ) noexcept;

    auto operator=(
        ControlableActor&&
    ) noexcept -> ControlableActor&;



    // ---------------------------------- Assign

    template<
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        std::is_base_of_v<engine::graphic::actor::AControlable, ActorType>
    ActorType& emplace(
        const std::string& shaderFilepath,
        auto&&... args
    )
    {
        auto actorPtr { std::make_unique<ActorType>(shaderFilepath, std::forward<decltype(args)>(args)...) };
        auto& actorRef { *actorPtr };
        m_actor = ::std::move(actorPtr);
        m_controlable = actorRef;
        return actorRef;
    }



    // ---------------------------------- Conversion

    operator ::engine::graphic::AActor&() { return *m_actor; }

    operator const ::engine::graphic::AActor&() const { return *m_actor; }



    operator ::engine::graphic::actor::AControlable&() { return m_controlable->get(); }

    operator const ::engine::graphic::actor::AControlable&() const { return m_controlable->get(); }




    // ---------------------------------- Get

    ::engine::graphic::AActor& getActorPart() { return *m_actor; }

    const ::engine::graphic::AActor& getActorPart() const { return *m_actor; }



    ::engine::graphic::actor::AControlable& control() { return m_controlable->get(); }

    const ::engine::graphic::actor::AControlable& control() const { return m_controlable->get(); }




public:
protected:
protected:
private:
private:

    ::std::unique_ptr<::engine::graphic::AActor> m_actor;
    OptionalReferenceWrapper<::engine::graphic::actor::AControlable> m_controlable;

};



} // namespace engine::graphic::actor



namespace engine::graphic { using ControlableActor = engine::graphic::actor::ControlableActor; }

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ACTORS_ACONTROLABLEACTOR_HPP___
