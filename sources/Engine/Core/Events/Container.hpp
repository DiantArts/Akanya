//
// Akanya
// sources/Engine/Core/Events/Container
// contain every events
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_CONTAINER_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_CONTAINER_HPP___

namespace engine::graphic { class AScene; }



namespace engine::core::event {



class Container {

public:

    // ---------------------------------- *structors

    explicit Container();

    ~Container();



    // ---------------------------------- Copy sementic

    Container(
        const Container&
    ) noexcept = delete;

    auto operator=(
        const Container&
    ) noexcept -> Container& = delete;



    // ---------------------------------- Copy sementic

    Container(
        Container&&
    ) noexcept;

    auto operator=(
        Container&&
    ) noexcept -> Container&;



    // ---------------------------------- Resolver

    template<
        std::derived_from<AEvent> EventType
    > void emplace(
        auto&&... args
    )
    {
        m_events.push_back(std::make_unique<EventType>(std::forward<decltype(args)>(args)...));
    }


    // ---------------------------------- Resolver

    void resolve(
        engine::graphic::AScene& scene
    );



public:
protected:
protected:
private:
private:

    std::deque<std::unique_ptr<::engine::core::AEvent>> m_events;

};



} // namespace engine::core::event

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_EVENTS_CONTAINER_HPP___
