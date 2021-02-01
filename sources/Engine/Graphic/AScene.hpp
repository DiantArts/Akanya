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

#include "Actors/Lights/Directional.hpp"
#include "Actors/Lights/Point.hpp"
#include "Actors/Lights/Spot.hpp"

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

    void manageEvents();



    // ---------------------------------- Draw

    void draw() const;

    void drawActors() const;

    void drawFps() const;



    // ---------------------------------- Update

    virtual void update();



    // ---------------------------------- Vector Actors

    template <
        typename ActorType
    > auto emplaceActor(
        engine::graphic::opengl::Shader& shader,
        auto&&... args
    ) -> ActorType&
    {
        static_assert(std::is_base_of_v<engine::graphic::AActor, ActorType>, "Only actors can be emplaced back");
        return static_cast<ActorType&>(*m_vectorActors.emplace_back(std::make_unique<ActorType>(
                shader,
                std::forward<decltype(args)>(args)...)
            ));
    }

#if MAX_NB_DIR_LIGHT > 0
    template <
        std::derived_from<engine::graphic::actor::light::Directional> ActorType
    > auto emplaceActor(
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
        std::derived_from<engine::graphic::actor::light::Point> ActorType
    > auto emplaceActor(
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
        std::derived_from<engine::graphic::actor::light::Spot> ActorType
    >
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



        // ---------------------------------- iterator

        auto begin()
            -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::iterator;

        auto begin()
            const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator;

        auto cbegin()
            const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator;



        auto end()
            -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::iterator;

        auto end()
            const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator;

        auto cend()
            const -> std::unordered_map<std::string, ::engine::graphic::opengl::Shader>::const_iterator;



    public:
    protected:
    protected:
    private:
    private:

        std::unordered_map<std::string, ::engine::graphic::opengl::Shader> m_shaderMap;

    };

    ::engine::graphic::Window& m_window;

    AScene::ShaderMap m_shaderMap;

    std::vector<std::unique_ptr<::engine::graphic::AActor>> m_vectorActors;
    std::vector<::engine::graphic::actor::CubeMap> m_vectorCubeMap;




protected:
private:
private:

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

    std::vector<std::reference_wrapper<engine::graphic::actor::ALight>> m_lights;

    engine::graphic::opengl::Ubo m_lightInformationsUbo;



    bool m_isOver { false };

    mutable ::engine::core::Clock m_eventClock;
    mutable ::engine::core::Clock m_updateClock;

    mutable ::engine::core::Clock m_fpsClock;
    mutable float m_elapsed { 0 };
    mutable int m_fps { 0 };

};




} // namespace engine::graphic


// template <> auto ::engine::graphic::AScene::emplaceActor<engine::graphic::actor::light::Directional>(
    // auto&&... args
// ) -> engine::graphic::actor::light::Directional&;
// {
    // using DirectionalLight = engine::graphic::actor::light::Directional;
    // return static_cast<DirectionalLight&>(*m_vectorActors.emplace_back(std::make_unique<DirectionalLight>(std::forward<decltype(args)>(args)...)));
// }

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_GRAPHIC_ASCENE_HPP___
