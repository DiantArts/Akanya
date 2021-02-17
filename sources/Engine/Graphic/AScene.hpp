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



    // ---------------------------------- Camera

    void addCameraMovementState(
        Camera::MovementState state
    );

    void removeCameraMovementState(
        Camera::MovementState state
    );



    void orienteCameraFromCursorPosition(
        const glm::vec2& position
    );

    void orienteCameraFromCursorPosition(
        glm::vec2&& position
    );

    void zoomCamera(
        float value
    );



    // ---------------------------------- Camera

    void centerCursorWindow() const;


    // ---------------------------------- Vector Actors

    template <
        typename ActorType
    > requires
        std::is_base_of_v<engine::graphic::AActor, ActorType> &&
        (!std::is_base_of_v<engine::graphic::ALight, ActorType>)
    auto emplaceActor(
        engine::graphic::opengl::Shader& shader,
        auto&&... args
    ) -> ActorType&
    {
        return static_cast<ActorType&>(*m_vectorActors.emplace_back(std::make_unique<ActorType>(
                shader,
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
        engine::graphic::opengl::Shader& shader,
        auto&&... args
    ) -> ActorType&
    {
        ++m_lightInformations.nbDirectionalLight;
        return static_cast<ActorType&>(*m_vectorActors.emplace_back(std::make_unique<ActorType>(
                m_lights,
                shader,
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
        engine::graphic::opengl::Shader& shader,
        size_t numberOfInstances,
        auto&&... args
    ) -> ActorType&
    {
        m_lightInformations.nbPointLight += numberOfInstances;
        return static_cast<ActorType&>(*m_vectorActors.emplace_back(std::make_unique<ActorType>(
                m_lights,
                shader,
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
        engine::graphic::opengl::Shader& shader,
        size_t numberOfInstances,
        auto&&... args
    ) -> ActorType&
    {
        m_lightInformations.nbSpotLight += numberOfInstances;
        return static_cast<ActorType&>(*m_vectorActors.emplace_back(std::make_unique<ActorType>(
                m_lights,
                shader,
                numberOfInstances,
                std::forward<decltype(args)>(args)...)
            ));
    }
#endif




public:
protected:

    class ShaderMap {

    public:

        // ---------------------------------- *structors

        ShaderMap();

        ~ShaderMap();

        // ---------------------------------- Copy sementic

        ShaderMap(
            const ShaderMap&
        ) noexcept = delete;

        auto operator=(
            const ShaderMap&
        ) noexcept -> ShaderMap& = delete;



        // ---------------------------------- Move sementic

        ShaderMap(
            ShaderMap&&
        ) noexcept;

        auto operator=(
            ShaderMap&&
        ) noexcept -> ShaderMap&;



        // ---------------------------------- Operators

        ::engine::graphic::opengl::Shader& operator[](
            const std::string& filename
        );



    public:
    protected:
    protected:
    private:
    private:

        std::unordered_map<std::string, ::engine::graphic::opengl::Shader> m_shaderMap;

    };
    mutable AScene::ShaderMap m_shaderMap;

    std::vector<std::unique_ptr<::engine::graphic::AActor>> m_vectorActors;
    std::vector<::engine::graphic::actor::CubeMap> m_vectorCubeMap;




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


    short m_state { -2 };

    bool m_isOver { false };

    mutable ::engine::core::Clock m_updateClock;

    mutable ::engine::core::Clock m_fpsClock;
    mutable float m_elapsed { 0 };
    mutable int m_fps { 0 };

    engine::graphic::opengl::Ubo m_lightInformationsUbo;
};




} // namespace engine::graphic

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ASCENE_HPP___
