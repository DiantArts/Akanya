/*
** Akanya, Engine
** sources/Engine/Core/AScene
** Basic scene template
*/

#ifndef ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_ASCENE_HPP___
#define ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_ASCENE_HPP___

#include "../Core/Clock.hpp"
#include "Actors/ABasicShape.hpp"
#include "Actors/CubeMap.hpp"
#include "Shadows.hpp"



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

    void pushActor(
        std::unique_ptr<::engine::graphic::AActor>&& actor
    );

    void pushActor(
        std::unique_ptr<::engine::graphic::AActor>& actor
    );

    template <
        typename ActorType,
        typename... Args
    > auto emplaceActor(
        Args&&... args
    ) -> ActorType&
    {
        m_vectorActors.push_back(std::make_unique<ActorType>(std::forward<Args>(args)...));
        return static_cast<ActorType&>(*m_vectorActors.back());
    }

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

    ::engine::graphic::Window& m_window;

    AScene::ShaderMap m_shaderMap;

    std::vector<std::unique_ptr<::engine::graphic::AActor>> m_vectorActors;
    std::vector<::engine::graphic::actor::CubeMap> m_vectorCubeMap;



protected:
private:
private:

    ::engine::graphic::Camera m_camera;

    bool m_isOver { false };

    mutable ::engine::core::Clock m_eventClock;
    mutable ::engine::core::Clock m_updateClock;

    mutable ::engine::core::Clock m_fpsClock;
    mutable float m_elapsed { 0 };
    mutable int m_fps { 0 };

};



} // namespace engine::graphic

#endif // ___INCLUDE_GUARD_SOURCES_ENGINE_CORE_ASCENE_HPP___
