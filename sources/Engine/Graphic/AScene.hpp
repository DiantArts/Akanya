//
// Akanya, Engine
// sources/Engine/Core/AScene
// Basic scene template
//

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ASCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ASCENE_HPP___

#include "../Core/Clock.hpp"
#include "Actors/ABasicShape.hpp"
#include "Actors/CubeMap.hpp"
#include "Shadows.hpp"

#include "Lights/Directional.hpp"
#include "Lights/Point.hpp"
#include "Lights/Spot.hpp"

#include "nbLights.hpp"



namespace engine::core::event { class AEvent; }
namespace engine::core::event { class KeyPressed; }
namespace engine::core::event { class KeyReleased; }
namespace engine::core::event { class MousePosition; }



namespace engine::graphic {



class AScene {

public:

    // ---------------------------------- *structors

    AScene(
        ::engine::graphic::Window& m_window
    );

    virtual ~AScene() = 0;



    // ---------------------------------- Copy sementic

    AScene(
        const AScene&
    ) noexcept = delete;

    auto operator=(
        const AScene&
    ) noexcept -> AScene& = delete;



    // ---------------------------------- Move sementic

    AScene(
        AScene&&
    ) noexcept = delete;

    auto operator=(
        AScene&&
    ) noexcept -> AScene& = delete;



    // ---------------------------------- Loop

    bool isOver() const;

    void setToOver();



    void manageEvents();



    // ---------------------------------- Draw

    void draw() const;

    void drawActors() const;

    void drawFps() const;



    // ---------------------------------- Update

    virtual void update();

    void attachCameraToPlayer();



    // ---------------------------------- Vector Actors

    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        (!std::is_base_of_v<engine::graphic::ALight, ActorType>)
    auto emplaceActor(
        auto&&... args
    ) -> ActorType&
    {
        return static_cast<ActorType&>(*m_actors.emplace_back(std::make_shared<ActorType>(
                std::forward<decltype(args)>(args)...)
            ));
    }

#if MAX_NB_DIRECTIONAL_LIGHT > 0
    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        std::is_base_of_v<engine::graphic::light::Directional, ActorType>
    auto emplaceActor(
        auto&&... args
    ) -> ActorType&
    {
        ++m_lightInformations.nbDirectionalLight;
        return static_cast<ActorType&>(*m_actors.emplace_back(std::make_shared<ActorType>(
                m_lights,
                std::forward<decltype(args)>(args)...)
            ));
    }
#endif

#if MAX_NB_POINT_LIGHT > 0
    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        std::is_base_of_v<engine::graphic::light::Point, ActorType>
    auto emplaceActor(
        size_t numberOfInstances,
        auto&&... args
    ) -> ActorType&
    {
        m_lightInformations.nbPointLight += numberOfInstances;
        return static_cast<ActorType&>(*m_actors.emplace_back(std::make_shared<ActorType>(
                m_lights,
                numberOfInstances,
                std::forward<decltype(args)>(args)...)
            ));
    }
#endif

#if MAX_NB_SPOT_LIGHT > 0
    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        std::is_base_of_v<engine::graphic::light::Spot, ActorType>
    auto emplaceActor(
        size_t numberOfInstances,
        auto&&... args
    ) -> ActorType&
    {
        m_lightInformations.nbSpotLight += numberOfInstances;
        return static_cast<ActorType&>(*m_actors.emplace_back(std::make_shared<ActorType>(
                m_lights,
                numberOfInstances,
                std::forward<decltype(args)>(args)...)
            ));
    }
#endif

    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        std::is_base_of_v<engine::graphic::actor::AControlable, ActorType> &&
        (!std::is_base_of_v<engine::graphic::ALight, ActorType>)
    auto emplacePlayer(
        const std::string& shaderFilepath,
        auto&&... args
    ) -> ActorType&
    {
        ::engine::graphic::actor::ControlableActor tmp;
        auto& player { tmp.emplace<ActorType>(
            shaderFilepath,
            std::forward<decltype(args)>(args)...
        ) };
        m_controlableActors.emplace_back(std::move(tmp));
        m_player = { m_controlableActors.back() };
        m_camera.attach(m_player->get());
        return player;
    }



public:
protected:
    OptionalReferenceWrapper<::engine::graphic::actor::ControlableActor> m_player;
    std::vector<::engine::graphic::actor::ControlableActor> m_controlableActors;
    std::vector<std::shared_ptr<::engine::graphic::AActor>> m_actors;
    std::vector<::engine::graphic::actor::CubeMap> m_cubeMap;




protected:
private:
private:

    ::engine::graphic::Window& m_window;
    ::engine::graphic::Camera m_camera;



    struct LightInformations {
        bool gamma;
        bool blinn;

#if MAX_NB_DIRECTIONAL_LIGHT > 0
        GLuint nbDirectionalLight;
#endif

#if MAX_NB_POINT_LIGHT > 0
        uint nbPointLight;
#endif

#if MAX_NB_SPOT_LIGHT > 0
        uint nbSpotLight;
#endif
    };
    LightInformations m_lightInformations;

    std::vector<std::reference_wrapper<engine::graphic::ALight>> m_lights;



    bool m_isOver { false };

    mutable ::engine::core::Clock m_updateClock;

    mutable ::engine::core::Clock m_fpsClock;
    mutable float m_elapsed { 0 };
    mutable int m_fps { 0 };

    engine::graphic::opengl::Ubo m_lightInformationsUbo;

    friend ::engine::core::event::AEvent;
    friend ::engine::core::event::KeyPressed;
    friend ::engine::core::event::KeyReleased;
    friend ::engine::core::event::MousePosition;
};




} // namespace engine::graphic

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ASCENE_HPP___
